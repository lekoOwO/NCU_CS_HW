#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

struct Data{
    char data;
    void input(){
        cin >> data;
        while (!isalpha(data)) {
            cout << "Error! " << endl;
            cin >> data;
        }
    }

    void output(){
        cout << data << " -> " << tolower(data) - 97 << endl;
    }
} datas[5];

int main(){
    for (int i = 0; i < 5; i++) {
        datas[i].input();
    }
    for (int i = 0; i < 5; i++) {
        datas[i].output();
    }
    return 0;
}