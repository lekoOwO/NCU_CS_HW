#include <iostream>
#include <vector>
using namespace std;
int main(){
    char input;
    vector<char> inputs;
    cout << "Please input chars, one at a line (Ctrl+Z to stop):";
    while(cin >> input) inputs.push_back(input);
    for (auto e: inputs) cout << e << " -> " << e - 97 << endl;
    return 0;
}