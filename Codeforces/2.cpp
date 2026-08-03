#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename, targetWord, replaceWord;

    cout << "Enter the filename: ";
    cin >> filename;
    cout << "Enter the word to find: ";
    cin >> targetWord;
    cout << "Enter replace it with: ";
    cin >> replaceWord;
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file '" << filename << "'." << endl;
        return 1;
    }

    string content = "";
    string line;
    int count = 0;
    while (getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(targetWord, pos)) != string::npos) {
            count++; 
            line.replace(pos, targetWord.length(), replaceWord);
            pos += replaceWord.length(); 
        }
        content += line + "\n";
    }
    inputFile.close();
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error" << endl;
        return 1;
    }
    outputFile << content;
    outputFile.close();
    if (count>0) {
        cout << "Success" << count << " occurrences of '" 
             << targetWord << "' with '" << replaceWord << "'." << endl;
    } else {
        cout << "The word'"<< targetWord << "' was not found in the file." << endl;
    }

    return 0;
}