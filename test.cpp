#include <windows.h>
#include <iostream>

void normalOutput(){
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    SetConsoleOutputCP(CP_UTF8);
}
 
int main()
{
    normalOutput();
}