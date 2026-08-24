#include <bits/stdc++.h>
using namespace std;
/*
E  → T E'
E' → + T E' | ε
T  → i
*/
string s;
int pos = 0;

void printNode(string node, int level) {
    for (int i = 0; i < level; i++)
        cout << "  ";
    cout << node << "\n";
}

bool E(int level);
bool Ep(int level);
bool T(int level);

bool E(int level) {
    printNode("E", level);

    if (!T(level + 1))
        return false;

    return Ep(level + 1);
}

bool Ep(int level) {
    printNode("E'", level);

    if (pos < s.size() && s[pos] == '+') {
        printNode("+", level + 1);
        pos++;

        if (!T(level + 1))
            return false;

        return Ep(level + 1);
    }

    printNode("epsilon", level + 1);
    return true;
}

bool T(int level) {
    printNode("T", level);

    if (pos < s.size() && s[pos] == 'i') {
        printNode("i", level + 1);
        pos++;
        return true;
    }

    return false;
}

int main() {
    cout << "Enter string: ";
    cin >> s;

    pos = 0;

    if (E(0) && pos == s.size())
        cout << "\nValid parse tree.\n";
    else
        cout << "\nInvalid string.\n";

    return 0;
}