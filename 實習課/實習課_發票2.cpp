#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// const string TWO_MILLION           = "22315462";
const vector<string> TWO_HUNDRED_K = {"91903003", "16228722", "22315462"};

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
    // if (x == TWO_MILLION)
    //     return "Grand Prize";
    if ((find(TWO_HUNDRED_K.begin(), TWO_HUNDRED_K.end(), x)) != TWO_HUNDRED_K.end())
        return "First Prize, $200,000";
    else {
        int maxMatch = 0;
        for (auto e : TWO_HUNDRED_K) {
            int t = match(x, e);
            if (t > maxMatch) maxMatch = t;
        }
        switch (maxMatch) {
            case 7: return "Second Prize, $40,000"; break;
            case 6: return "Third Prize, $10,000"; break;
            case 5: return "Fourth Prize, $4,000"; break;
            case 4: return "Fifth Prize, $1,000"; break;
            case 3: return "Sixth Prize, $200"; break;
            default: return "None"; break;
        }
    }
}

int main(void) {
    vector<string> invoices;
    string input;
    cout << "Enter your invoice number (Ctrl-Z to stop): " << endl;
    while (getline(cin, input)) invoices.push_back(input);
    cout << endl;
    for (auto i: invoices) cout << i << ": " << prize(i) << endl;
    return 0;
}