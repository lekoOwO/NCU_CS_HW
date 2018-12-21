#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

const int SPECIAL_CHAR_SIZE = 3;

class splitstring : public string {
    /*
        Splits string.
        The reason of using this except of cin is to react to the situation of
            undesigned length.
        @param  <char> delim The char to split the string.
        @param  <int>  rep The counts of the split.
            Keep as default to split as much as possible.
        @return <vector<string>>
        Usage: auto a = (splitstring)"Hello how are you?".split(' ');
    */
    vector<string> flds;

   public:
    template<class T>
    splitstring(T s) : string(s){};
    vector<string>& split(char delim, int rep = 0) {
        if (!flds.empty()) flds.clear();
        string work = data();
        string buf  = "";
        int i       = 0;
        while (i < work.length()) {
            if (work[i] != delim)
                buf += work[i];
            else if (rep == 1) {
                flds.push_back(buf);
                buf = "";
            } else if (buf.length() > 0) {
                flds.push_back(buf);
                buf = "";
            }
            i++;
        }
        if (!buf.empty()) flds.push_back(buf);
        return flds;
    }
};

int main(int argc, char* argv[]){
    map<string, int> counts;
    ifstream file(argv[1]);
    ofstream outputFile(argv[2]);
    if (file) {
        splitstring line = "";
        while (getline(file, line)) {
            for (auto w:(line.split(' '))) {
                if (w.size() == SPECIAL_CHAR_SIZE && !isalnum(w[0]))
                    continue;
                if (!isalnum(*(w.begin()))) {
                    if (ispunct((*(w.begin())))) {
                        w.erase(w.begin());
                    } else {
                        w.erase(0, SPECIAL_CHAR_SIZE);
                    }
                }
                if (!isalnum(*(w.rbegin()))) {
                    if (ispunct((*(w.rbegin())))) {
                        w.erase(w.end() - 1);
                    } else {
                        w.erase(w.size() - SPECIAL_CHAR_SIZE, SPECIAL_CHAR_SIZE);
                    }
                }
                if (counts.count(w))
                    counts[w] += 1;
                else
                    counts[w] = 1;
            }
        }
        file.close();
    }
    if (outputFile){
        string buf = "";
        vector<pair<string, int>> countsVec(counts.begin(), counts.end());
        sort(countsVec.begin(), countsVec.end(), [](auto a, auto b) { return a.second > b.second; });
        for (auto e: countsVec) 
            buf += e.first + ", " + to_string(e.second) + '\n';
        outputFile.write( buf.c_str(), buf.size());
    } else {
        cerr << "Failure opening " << argv[2] << '\n';
        return -1;
    }
    return 0;
}