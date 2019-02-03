#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>

using namespace std;

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
    ifstream file(argv[1]);
    int counts = 0;

    if (file) {
        splitstring line = "";
        
        while (getline(file, line)) {
            auto cur = line.split(',');
            counts += size(cur);
        }
    }

    cout << counts << endl;
    return 0;
}