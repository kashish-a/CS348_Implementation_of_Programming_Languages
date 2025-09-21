%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int line_number = 1;

/* Symbol table functions */
#define SYMBOL_TABLE_SIZE 1000

typedef struct {
    char name[100];
    char type[50];     // KEYWORD, IDENTIFIER, PUNCTUATOR, INTEGER_CONSTANT, etc.
    int line_number;
} Symbol;

Symbol symbolTable[SYMBOL_TABLE_SIZE];
int symbolCount = 0;

void addToken(char* name, char* type, int line) {
    if(symbolCount < SYMBOL_TABLE_SIZE) {
        strncpy(symbolTable[symbolCount].name, name, 99);
        symbolTable[symbolCount].name[99] = '\0';
        strncpy(symbolTable[symbolCount].type, type, 49);
        symbolTable[symbolCount].type[49] = '\0';
        symbolTable[symbolCount].line_number = line;
        symbolCount++;
    } else {
        fprintf(stderr, "Symbol table overflow\n");
    }
}

void printSymbolTable() {
    int i;
    printf("\n============= SYMBOL TABLE =============\n");
    printf("Name                 Type            Line No \n");
    printf("----------------------------------------\n");
    for (i = 0; i < symbolCount; i++) {
        printf("%-20s %-15s %-10d\n", 
               symbolTable[i].name, 
               symbolTable[i].type, 
               symbolTable[i].line_number);
    }
}
%}

/* Regular expressions for various token types */
DIGIT       [0-9]
NONZERO     [1-9]
IDENTIFIER_NONDIGIT    [a-zA-Z_]
ESCAPE_SEQUENCE        (\\['"?\\abfnrtv])
C_CHAR                 ([^'\\\n]|{ESCAPE_SEQUENCE})
S_CHAR                 ([^"\\\n]|{ESCAPE_SEQUENCE})

%%
"/*"([^*]|\*+[^*/])*\*+"/"      { /* skip multi-line comment */ }
"//".*                          { /* skip single-line comment */ }

"return"                        { addToken("return", "KEYWORD", line_number); return RETURN; }
"void"                          { addToken("void", "KEYWORD", line_number); return VOID; }
"float"                         { addToken("float", "KEYWORD", line_number); return FLOAT; }
"integer"                       { addToken("integer", "KEYWORD", line_number); return INTEGER; }
"char"                          { addToken("char", "KEYWORD", line_number); return CHAR; }
"for"                           { addToken("for", "KEYWORD", line_number); return FOR; }
"const"                         { addToken("const", "KEYWORD", line_number); return CONST; }
"while"                         { addToken("while", "KEYWORD", line_number); return WHILE; }
"do"                            { addToken("do", "KEYWORD", line_number); return DO; }
"if"                            { addToken("if", "KEYWORD", line_number); return IF; }
"else"                          { addToken("else", "KEYWORD", line_number); return ELSE; }
"bool"                          { addToken("bool", "KEYWORD", line_number); return BOOL; }
"begin"                         { addToken("begin", "KEYWORD", line_number); return BLOCK_BEGIN; }
"end"                           { addToken("end", "KEYWORD", line_number); return BLOCK_END; }

"->"                            { addToken("->", "PUNCTUATOR", line_number); return ARROW; }
"++"                            { addToken("++", "PUNCTUATOR", line_number); return INCREMENT; }
"--"                            { addToken("--", "PUNCTUATOR", line_number); return DECREMENT; }
"<<"                            { addToken("<<", "PUNCTUATOR", line_number); return LEFT_SHIFT; }
">>"                            { addToken(">>", "PUNCTUATOR", line_number); return RIGHT_SHIFT; }
"<="                            { addToken("<=", "PUNCTUATOR", line_number); return LESS_THAN_EQUAL; }
">="                            { addToken(">=", "PUNCTUATOR", line_number); return GREATER_THAN_EQUAL; }
"=="                            { addToken("==", "PUNCTUATOR", line_number); return EQUAL; }
"!="                            { addToken("!=", "PUNCTUATOR", line_number); return NOT_EQUAL; }
"&&"                            { addToken("&&", "PUNCTUATOR", line_number); return LOGICAL_AND; }
"||"                            { addToken("||", "PUNCTUATOR", line_number); return LOGICAL_OR; }

"["                             { addToken("[", "PUNCTUATOR", line_number); return LEFT_SQUARE_BRACKET; }
"]"                             { addToken("]", "PUNCTUATOR", line_number); return RIGHT_SQUARE_BRACKET; }
"("                             { addToken("(", "PUNCTUATOR", line_number); return LEFT_PARENTHESIS; }
")"                             { addToken(")", "PUNCTUATOR", line_number); return RIGHT_PARENTHESIS; }
"+"                             { addToken("+", "PUNCTUATOR", line_number); return ADD; }
"-"                             { addToken("-", "PUNCTUATOR", line_number); return SUBTRACT; }
"*"                             { addToken("*", "PUNCTUATOR", line_number); return MULTIPLY; }
"/"                             { addToken("/", "PUNCTUATOR", line_number); return DIVIDE; }
"%"                             { addToken("%", "PUNCTUATOR", line_number); return MODULO; }
"<"                             { addToken("<", "PUNCTUATOR", line_number); return LESS_THAN; }
">"                             { addToken(">", "PUNCTUATOR", line_number); return GREATER_THAN; }
"!"                             { addToken("!", "PUNCTUATOR", line_number); return NOT; }
"&"                             { addToken("&", "PUNCTUATOR", line_number); return ADDRESS; }
"^"                             { addToken("^", "PUNCTUATOR", line_number); return BITWISE_XOR; }
"|"                             { addToken("|", "PUNCTUATOR", line_number); return BITWISE_OR; }
"?"                             { addToken("?", "PUNCTUATOR", line_number); return QUESTION_MARK; }
":"                             { addToken(":", "PUNCTUATOR", line_number); return COLON; }
";"                             { addToken(";", "PUNCTUATOR", line_number); return SEMICOLON; }
"="                             { addToken("=", "PUNCTUATOR", line_number); return ASSIGN; }
","                             { addToken(",", "PUNCTUATOR", line_number); return COMMA; }

{NONZERO}{DIGIT}*               { addToken(yytext, "INTEGER_CONSTANT", line_number); 
                                  yylval.str = strdup(yytext); return INTEGER_CONSTANT; }
0                               { addToken(yytext, "INTEGER_CONSTANT", line_number); 
                                  yylval.str = strdup(yytext); return INTEGER_CONSTANT; }

{DIGIT}+\.{DIGIT}*(e|E)[-+]?{DIGIT}+  { addToken(yytext, "FLOAT_CONSTANT", line_number); 
                                  yylval.str = strdup(yytext); return FLOAT_CONSTANT; }
{DIGIT}*\.{DIGIT}+              { addToken(yytext, "FLOAT_CONSTANT", line_number); 
                                  yylval.str = strdup(yytext); return FLOAT_CONSTANT; }
{DIGIT}+(e|E)[-+]?{DIGIT}+      { addToken(yytext, "FLOAT_CONSTANT", line_number); 
                                  yylval.str = strdup(yytext); return FLOAT_CONSTANT; }

\'({C_CHAR})\'                  { addToken(yytext, "CHARACTER_CONSTANT", line_number); 
                                  yylval.str = strdup(yytext); return CHARACTER_CONSTANT; }
\"({S_CHAR})*\"                 { addToken(yytext, "STRING_LITERAL", line_number); 
                                  yylval.str = strdup(yytext); return STRING_LITERAL; }

{IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*  { addToken(yytext, "IDENTIFIER", line_number);
                                  yylval.str = strdup(yytext); return IDENTIFIER; }

[ \t\r]+                        { /* skip whitespace */ }
\n                              { line_number++; }

.                               { addToken(yytext, "UNKNOWN", line_number);
                                  printf("Error: Unknown token '%s' at line %d\n", yytext, line_number);
                                  return yytext[0]; }
%%

int yywrap(void) {
    return 1;
}