#include <bits/stdc++.h>
using namespace std;

string s;
int pos = 0;

bool S();

bool S() {
    if (pos < s.size() && s[pos] == 'a') {
        pos++;
        return true;
    }

    return false;
}

int main() {
    cout << "Grammar:\n";
    cout << "S -> a\n\n";

    cout << "Enter string: ";
    cin >> s;

    pos = 0;

    if (S() && pos == s.size())
        cout << "String belongs to the grammar.\n";
    else
        cout << "String does NOT belong to the grammar.\n";

    return 0;
}