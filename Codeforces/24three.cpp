#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cin.ignore();

    while (n--) {
        string line;
        cout << "\nEnter production: ";
        getline(cin, line);

        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        size_t arrow = line.find("->");

        string lhs = line.substr(0, arrow);
        string rhs = line.substr(arrow + 2);

        vector<string> alternatives;
        string temp;

        for (char c : rhs) {
            if (c == '|') {
                alternatives.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        alternatives.push_back(temp);

        bool leftRecursive = false;

        for (auto &alt : alternatives) {
            if (alt.rfind(lhs, 0) == 0) {
                leftRecursive = true;
                break;
            }
        }

        if (leftRecursive)
            cout << "Left Recursive: YES\n";
        else
            cout << "Left Recursive: NO\n";

        bool leftFactoring = false;

        for (int i = 0; i < alternatives.size(); i++) {
            for (int j = i + 1; j < alternatives.size(); j++) {
                if (!alternatives[i].empty() &&
                    !alternatives[j].empty() &&
                    alternatives[i][0] == alternatives[j][0]) {
                    leftFactoring = true;
                }
            }
        }

        if (leftFactoring)
            cout << "Left Factoring required: YES\n";
        else
            cout << "Left Factoring required: NO\n";
    }

    return 0;
}