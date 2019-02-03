#include <iostream>
#include <string>

using namespace std;

int func1(int x) {
    return x > 1 ? x * func1(x - 1) : x;
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