#include <windows.h>
#include <iostream>

void normalOutput(){
    /*
        為了讓視窗顯示英文以外字體的 workaround.
    */
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    SetConsoleOutputCP(CP_UTF8);
}
 
int main()
{
    normalOutput(); // 為了讓視窗顯示英文以外字體的 workaround.
}