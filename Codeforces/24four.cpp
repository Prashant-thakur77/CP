#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, alpha, beta;

    cout << "Enter non-terminal: ";
    cin >> A;

    cout << "Enter alpha (after " << A << " in recursive part): ";
    cin >> alpha;

    cout << "Enter beta (non-recursive part): ";
    cin >> beta;

    cout << "\nAfter removing left recursion:\n";

    cout << A << " -> " << beta << A << "'" << endl;
    cout << A << "' -> " << alpha << A << "' | epsilon" << endl;

    return 0;
}