#include <algorithm>
#include <string>
#include <iostream>
 
int main()
{
    std::string s;
    std::cout << "Enter alphabets. e.g. abuhgsj: ";
    std::cin >> s;
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
}