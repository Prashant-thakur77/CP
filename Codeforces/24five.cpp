#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> FIRST, FOLLOW;
set<char> nonTerminals;

char startSymbol;

// Find FIRST of a string
set<char> findFirst(string str) {
    set<char> result;

    // Empty string
    if (str.empty()) {
        result.insert('#');
        return result;
    }

    bool allEpsilon = true;

    for (char c : str) {

        // Terminal
        if (!isupper(c)) {
            result.insert(c);
            allEpsilon = false;
            break;
        }

        // Non-terminal
        set<char> temp = FIRST[c];

        for (char x : temp) {
            if (x != '#')
                result.insert(x);
        }

        // If epsilon is not present, stop
        if (temp.find('#') == temp.end()) {
            allEpsilon = false;
            break;
        }
    }

    if (allEpsilon)
        result.insert('#');

    return result;
}

// Calculate FIRST
void calculateFirst() {

    bool changed = true;

    while (changed) {
        changed = false;

        for (auto &p : grammar) {

            char lhs = p.first;

            for (string rhs : p.second) {

                set<char> temp = findFirst(rhs);

                int oldSize = FIRST[lhs].size();

                for (char x : temp)
                    FIRST[lhs].insert(x);

                if (FIRST[lhs].size() != oldSize)
                    changed = true;
            }
        }
    }
}

// Calculate FOLLOW
void calculateFollow() {

    // Start symbol gets $
    FOLLOW[startSymbol].insert('$');

    bool changed = true;

    while (changed) {
        changed = false;

        for (auto &p : grammar) {

            char lhs = p.first;

            for (string rhs : p.second) {

                for (int i = 0; i < rhs.length(); i++) {

                    char current = rhs[i];

                    // Only non-terminals have FOLLOW
                    if (!isupper(current))
                        continue;

                    string remaining = rhs.substr(i + 1);

                    set<char> firstRemaining = findFirst(remaining);

                    int oldSize = FOLLOW[current].size();

                    // Add FIRST(remaining) except epsilon
                    for (char x : firstRemaining) {
                        if (x != '#')
                            FOLLOW[current].insert(x);
                    }

                    // If remaining can produce epsilon
                    // or current is at the end
                    if (remaining.empty() ||
                        firstRemaining.find('#') != firstRemaining.end()) {

                        for (char x : FOLLOW[lhs])
                            FOLLOW[current].insert(x);
                    }

                    if (FOLLOW[current].size() != oldSize)
                        changed = true;
                }
            }
        }
    }
}

int main() {

    int n;

    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Use # for epsilon.\n\n";

    for (int i = 0; i < n; i++) {

        char lhs;
        string rhs;

        cout << "Enter production " << i + 1 << ": ";
        cin >> lhs >> rhs;

        // First production's LHS is start symbol
        if (i == 0)
            startSymbol = lhs;

        grammar[lhs].push_back(rhs);
        nonTerminals.insert(lhs);
    }

    calculateFirst();
    calculateFollow();

    cout << "\nFIRST:\n";

    for (char nt : nonTerminals) {

        cout << "FIRST(" << nt << ") = { ";

        for (char x : FIRST[nt])
            cout << x << " ";

        cout << "}\n";
    }

    cout << "\nFOLLOW:\n";

    for (char nt : nonTerminals) {

        cout << "FOLLOW(" << nt << ") = { ";

        for (char x : FOLLOW[nt])
            cout << x << " ";

        cout << "}\n";
    }

    return 0;
}