%option noyywrap c++

%{
#include <iostream>
using namespace std;

int identifierCount = 0;
%}

%%
[a-zA-Z]+ {
    identifierCount++;
    cout << yytext << endl;
}

.|\n { }
%%

int main() {
    yyFlexLexer scanner;
    scanner.yylex();

    cout << "Total identifiers: " << identifierCount << endl;

    return 0;
}