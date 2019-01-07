#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

class Input{
    public:
      Input(char in) {
          this->in = in;
          this->num = tolower(in) - 97;
      }
      char in;
      int num;
};

int main(){
    char input;
    vector<class Input> inputs;
    cout << "Please input chars, one at a line (Ctrl+Z to stop):";
    while(cin >> input) {
        if (isalpha(input)) inputs.push_back(Input(input));
        else cout << "Error!" << endl;
    }
    for (auto e: inputs) cout << e.in << " -> " << e.num << endl;
    return 0;
}