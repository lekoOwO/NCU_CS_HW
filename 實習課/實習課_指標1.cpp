#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    map<int, int> acc;
    for (char **arg = argv + 1; *arg; ++arg) 
        acc.count(atoi(*arg)) ? acc[atoi(*arg)] += 1 : acc[atoi(*arg)] = 1;
    auto result = &*acc.begin();
    for( auto &p : acc ) if (p.second > result->second) result = &p;
    cout << "Num(" << result->first << "): " << result->second << endl;
    return 0;
}


