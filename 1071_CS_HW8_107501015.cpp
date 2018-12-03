#include <iostream>
#include <cstdlib> 
#include <string>
using namespace std;
string show;

char anw='y';
struct stack 
{
	string check;
	string num;
};
void func(stack &a);
void character()
{   
    stack a1;
    cout<<"Input the stack structure : ";
    cin>>a1.check;
    if(a1.check=="push")
        cin >> a1.num;
    func(a1);
}

int main() 
{
    string input;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<' || input[i] == '>')
            continue;
        if (input[i] == 'p') {
            if (input[i+1] == 'u') {
                stack x;
                string num;
                for (int j = i + 5; input[j] != '>'; j++, i = j - 1) num += input[j];
                x.num = num;
                x.check = "push";
                func(x);
            } else if (input[i+1] == 'o') {
                stack x;
                x.check = "pop";
                func(x);
                i += 2;
            }
        } else if (input[i] == 's') {
            stack x;
            x.check = "show";
            func(x);
            i += 3;
        }
    }
}

void func(struct stack &a)
{
    if(a.check=="push")
		show += ' ' + a.num;
	else if(a.check=="pop"){
        for (int x = show.size(); show[show.size() - x] != ' '; x--) {
            show.pop_back();
        }
        show.pop_back();
    }
    else if(a.check=="show") {
	    cout<<"The stack is ";
        for (int x = 0; x < show.size(); x++) {
            if (show[x] != ' ')
                cout << '<' << show[x] << '>';
        }
        cout << endl;
    }
}