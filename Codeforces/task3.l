%option noyywrap c++

%{
#include <iostream>
using namespace std;

bool valid = true;
bool needValue = true;
%}

%%
[ \t\n]+               { }

[a-zA-Z]+              {
                           cout << "Identifier: " << yytext << endl;
                           if (!needValue) valid = false;
                           needValue = false;
                       }

[0-9]+                 {
                           if (!needValue) valid = false;
                           needValue = false;
                       }

[+*/-]                 {
                           cout << "Operator: " << yytext << endl;
                           if (needValue) valid = false;
                           needValue = true;
                       }

.                      { valid = false; }
%%

int main() {
    yyFlexLexer scanner;
    scanner.yylex();

    if (needValue)
        valid = false;

    if (valid)
        cout << "Valid expression" << endl;
    else
        cout << "Invalid expression" << endl;

    return 0;
}