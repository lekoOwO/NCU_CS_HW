#include <iostream>
#include <string>

using namespace std;

int func1(int x) {
    int temp = 1;
    while (x > 1) {
        temp *= x;
        x--;
    }
    return temp;
}

int main(void) {
    int m, n;
    cout << "Please input m: ";
    cin >> m;
    cout << "Please input n: ";
    cin >> n;
    cout << int(func1(m)/func1(n)/func1(m-n)) << endl;
    return 0;
}