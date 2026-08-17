%option noyywrap c++

%{
#include <iostream>
#include <fstream>
using namespace std;

int commentLines = 0;
ofstream output("without_comments.c");
%}

%x BLOCK_COMMENT

%%
\"([^\\\n]|\\.)*\"       { output << yytext; }
\'([^\\\n]|\\.)*\'       { output << yytext; }

"//"[^\n]*               { commentLines++; }

"/*"                     { commentLines++; BEGIN(BLOCK_COMMENT); }

<BLOCK_COMMENT>\n        { commentLines++; output << '\n'; }
<BLOCK_COMMENT>"*/"      { BEGIN(INITIAL); }
<BLOCK_COMMENT>.         { }

\n                       { output << '\n'; }
.                        { output << yytext; }
%%

int main() {
    yyFlexLexer scanner;
    scanner.yylex();

    output.close();

    cout << "Number of comment lines: "
         << commentLines << endl;

    cout << "Program without comments is saved in "
         << "without_comments.c" << endl;

    return 0;
}