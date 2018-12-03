#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(void) {
    string words;
    getline(cin, words);

    map<const char, int> acc;

    for (auto s : words) {
        if (acc.count(s))
            acc[s] += 1;
        else
            acc[s] = 1;
    }

    for (auto it : acc) {
        cout << "'" << it.first << "': " << it.second
             << (it == *(acc.rbegin()) ? "" : ", ");
    };

    return 0;
}