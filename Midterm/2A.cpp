#include <iostream>

using namespace std;

int main(void) {
    double rate, twd;
    cout << "Please input to exchange rate of TWD to JPY: ";
    cin >> rate;
    cout << endl
         << "Please input the amount of TWD: ";
    cin >> twd;
    cout << endl
         << "The corresponding amount of JPY is " << rate * twd << "JPY" << endl;
    return 0;
}