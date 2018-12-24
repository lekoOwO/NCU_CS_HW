#include <fstream>
#include <iostream>
#include <string>

int main(){
    char key;
    std::cin.get(key);
    std::ifstream secretf("secret.txt");
    std::string secret((std::istreambuf_iterator<char>(secretf)), std::istreambuf_iterator<char>());
    for (auto &e: secret) e -= key;

    std::ofstream out("107501006.txt");
    out << secret;
    out.close();
    return 0;
}
