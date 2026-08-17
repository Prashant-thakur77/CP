%option noyywrap c++

%{
#include <iostream>
using namespace std;

int characters = 0;
int words = 0;
int spaces = 0;
int lines = 0;
%}

%%
[ \t]+          { spaces += yyleng; characters += yyleng; }
\n              { lines++; characters++; }
[^ \t\n]+       { words++; characters += yyleng; }
%%

int main() {
    yyFlexLexer scanner;
    scanner.yylex();

    cout << "\nCharacters: " << characters << endl;
    cout << "Words: " << words << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Lines: " << lines << endl;

    return 0;
}