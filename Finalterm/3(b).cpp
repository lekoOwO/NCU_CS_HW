#include <algorithm>
#include <string>
#include <iostream>

void f1(std::string s){
    if (std::next_permutation(s.begin(), s.end())){
        std::cout << s << '\n';
        f1(s);
    } else {
        return;
    }
}
 
int main()
{
    std::string s;
    std::cout << "Enter alphabets. e.g. abuhgsj: ";
    std::cin >> s;
    std::sort(s.begin(), s.end());
    std::cout << s << '\n';
    f1(s);
    return 0;
}