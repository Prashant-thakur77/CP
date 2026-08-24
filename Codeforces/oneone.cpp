#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int countWord(string s, string word) {
    stringstream ss(s);
    string temp;
    int count = 0;
    while (ss >> temp) {
        if (temp == word) {
            count++;
        }
    }
    return count;
}

int countSubstring(string s, string pattern) {
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find(pattern, pos)) != string::npos) {
        count++;
        pos++;
    }
    return count;
}

int countSubsequence(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 1; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text[i - 1] == pattern[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main() {
    string text, pattern;
    cout << "Enter the string: ";
    getline(cin, text);
    cout << "Enter word/substring/subsequence to search: ";
    getline(cin, pattern);

    cout << "\nWord Occurrences: " << countWord(text, pattern) << endl;
    cout << "Substring Occurrences: " << countSubstring(text, pattern) << endl;
    cout << "Subsequence Occurrences: " << countSubsequence(text, pattern) << endl;

    return 0;
}