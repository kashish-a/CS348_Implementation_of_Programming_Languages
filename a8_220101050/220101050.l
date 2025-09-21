%{
#include <math.h>
#include <string.h>
#include "220101050.tab.h"
%}

%option noyywrap

%%
"expr"      { return EXPR; }
"bintodec"  { return BINTODEC; }
"bintohex"  { return BINTOHEX; }
"hextobin"  { return HEXTOBIN; }
"hextodec"  { return HEXTODEC; }
[0-9A-Fa-f]+    { 
    // Hexadecimal number handling
    yylval.sval = strdup(yytext); 
    return NUMBER; 
}

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULTIPLY; }
"/"         { return DIVIDE; }
"**"        { return POWER; }
"("         { return LPAREN; }
")"         { return RPAREN; }

[ \t\n]     ; // Ignore whitespace
.           { printf("Unexpected character: %s\n", yytext); }

%%