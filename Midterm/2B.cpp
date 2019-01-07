#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    double rate = stof(argv[2]);
    double twd = stof(argv[1]);
    cout << endl
         << "The corresponding amount of JPY is " << rate * twd << "JPY" << endl;
    return 0;
}