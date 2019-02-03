#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string TWO_MILLION           = "22315462";
const vector<string> TWO_HUNDRED_K = {"91903003", "16228722", "03270598"};

int match(string x, string y) {
    int count = 0;
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] == y[i])
            count++;
        else
            break;
    }
    return count;
}

string prize(string x) {
    if (x == TWO_MILLION)
        return "Grand Prize";
    else if ((find(TWO_HUNDRED_K.begin(), TWO_HUNDRED_K.end(), x)) !=
             TWO_HUNDRED_K.end())
        return "First Prize";
    else {
        int maxMatch = 0;
        for (auto e : TWO_HUNDRED_K) {
            int t = match(x, e);
            if (t > maxMatch) maxMatch = t;
        }
        switch (maxMatch) {
            case 7: return "Second Prize"; break;
            case 6: return "Third Prize"; break;
            case 5: return "Fourth Prize"; break;
            case 4: return "Fifth Prize"; break;
            case 3: return "Sixth Prize"; break;
            default: return "None"; break;
        }
    }
}

int main(void) {
    char y;
    do {
        string x;
        cout << "Enter your invoice number: ";
        cin >> x;
        cout << prize(x) << endl << "Next Invoice?(Y/N): ";
        cin >> y;
    } while (y == 'Y' || y == 'y');
    return 0;
}