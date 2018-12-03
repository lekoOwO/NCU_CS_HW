#include <iostream>
#include <cstdlib> 
#include <string>
using namespace std;

struct Node{
    string data;
    Node *nextNode = nullptr;
};

struct Nodehead {
    string data;
    Node *nextNode = nullptr;

    void push(string newData) {
        if (data.empty()) {
            data = newData;
            return;
        }

        if (nextNode == nullptr){
            nextNode = new Node{newData};
            return;
        }

        Node *lastNode = nextNode;
        while (lastNode->nextNode != nullptr) {
            lastNode = lastNode->nextNode;
        }
        lastNode->nextNode = new Node{newData};
    }

    void pop(){
        if (nextNode == nullptr) {
            data = "";
            return;
        }
        
        if (nextNode->nextNode == nullptr) {
            delete nextNode;
            nextNode = nullptr;
            return;
        }

        Node *secondLastNode = nextNode;
        Node *lastNode = nextNode->nextNode;
        while (lastNode->nextNode != nullptr) {
            secondLastNode = lastNode;
            lastNode = lastNode->nextNode;
        }
        delete lastNode;
        secondLastNode->nextNode = nullptr;
    }

    void show(){
        if (!data.empty()) cout << "<" << data << ">";

        Node *currentNode = nextNode;
        while (currentNode != nullptr) {
            cout << "<" << currentNode->data << ">";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
} first;

int main (){
	cout<<"Input:";
    string input;
    getline(cin,input);

    for (auto e = input.begin(); e != input.end(); e++){
        string operation;
        string target;

        if (*e == '<') { // 遇到 '<'，開始儲存指令
            e++;
            while (*e != ' ' && *e != '>') { // 遇到空白或>之前都當作指令儲存在 operation 裡面
                operation += *e;
                e++;
            } // 此時指令儲存完成，*e == ' ' 或 *e == '>' 有一個會成立

            if (*e == ' ') {
                e++; // 跳過空白

                while (*e != '>') { // 在遇到>之前都當作要儲存的東西
                    target += *e;
                    e++;
                }
            } // 此時 target 是要儲存的目標, *e == '>'。

            if (operation == "push") {
                first.push(target);         // 做 push
            } else if (operation == "pop"){ // 此時 *e == '>', operation == "pop"
                first.pop();                // 做 pop
            } else if (operation == "show"){ // 此時 *e == '>', operation == "show"
                first.show();                // 做 show
            }
        }
	}
    return 0;
}