%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* External declarations - defined in lexical_analyzer.c */
extern void print_token(char *token_type, char *lexeme);
extern void add_to_symbol_table(char *lexeme, char *token_type);
%}

%option yylineno
%option noyywrap

/* Keywords */
KEYWORD             "return"|"void"|"float"|"integer"|"char"|"for"|"const"|"while"|"bool"|"if"|"do"|"else"|"begin"|"end"

/* Identifier Components */
NONDIGIT            [a-zA-Z_]
DIGIT               [0-9]
IDENTIFIER          {NONDIGIT}({NONDIGIT}|{DIGIT})*

/* Number Components */
NONZERO_DIGIT       [1-9]
INTEGER_CONSTANT    {NONZERO_DIGIT}{DIGIT}*|0

/* Floating Point Components */
DIGIT_SEQUENCE      {DIGIT}+
FRACTIONAL_CONSTANT ({DIGIT_SEQUENCE}?"."{DIGIT_SEQUENCE})|({DIGIT_SEQUENCE}".")
SIGN                [+-]
EXPONENT_PART       [eE]{SIGN}?{DIGIT_SEQUENCE}
FLOATING_CONSTANT   ({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|({DIGIT_SEQUENCE}{EXPONENT_PART})

/* Character Constants */
ESCAPE_SEQUENCE     "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"
C_CHAR              [^\'\n\\]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE     {C_CHAR}+
CHAR_CONSTANT       \'{C_CHAR_SEQUENCE}\'

/* String Literals */
S_CHAR              [^\"\n\\]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE     {S_CHAR}+
STRING_LITERAL      \"({S_CHAR_SEQUENCE})?\"

/* Punctuators */
PUNCTUATOR          "["|"]"|"("|")"|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"="|","

WHITESPACE          [ \t\r\n]

%%
{KEYWORD}           { print_token("KEYWORD", yytext); /*add_to_symbol_table(yytext, "KEYWORD");*/ }
{IDENTIFIER}        { print_token("IDENTIFIER", yytext); add_to_symbol_table(yytext, "IDENTIFIER"); }
{INTEGER_CONSTANT}  { print_token("INTEGER_CONSTANT", yytext); add_to_symbol_table(yytext, "INTEGER_CONSTANT"); }
{FLOATING_CONSTANT} { print_token("FLOATING_CONSTANT", yytext); add_to_symbol_table(yytext, "FLOATING_CONSTANT"); }
{CHAR_CONSTANT}     { print_token("CHAR_CONSTANT", yytext); add_to_symbol_table(yytext, "CHAR_CONSTANT"); }
{STRING_LITERAL}    { print_token("STRING_LITERAL", yytext); add_to_symbol_table(yytext, "STRING_LITERAL"); }
{PUNCTUATOR}        { print_token("PUNCTUATOR", yytext); add_to_symbol_table(yytext, "PUNCTUATOR"); }

"/*"                { 
                      char c, prev = 0;
                      while((c = input()) != 0) {
                          if(c == '/' && prev == '*')
                              break;
                          prev = c;
                      }
                      print_token("COMMENT", "/*...*/"); 
                    }
                    
"//"                { 
                      char c;
                      while((c = input()) != 0 && c != '\n');
                      print_token("COMMENT", "//..."); 
                    }

{WHITESPACE}        { /* Ignore whitespace */ }
.                   { print_token("INVALID_TOKEN", yytext); }

%%

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Symbol table structure */
struct symbol_entry
{
    char *lexeme;
    char *token_type;
    struct symbol_entry *next;
};

struct symbol_entry *symbol_table = NULL;

/* External declarations for flex */
extern int yylex();
extern FILE *yyin;
extern int yylineno;

/* Function to print token information */
void print_token(char *token_type, char *lexeme)
{
    printf("<%s, %s>\n", token_type, lexeme);
}

/* Function to add an entry to the symbol table */
void add_to_symbol_table(char *lexeme, char *token_type)
{
    struct symbol_entry *s = symbol_table;

    /* Check if symbol already exists */
    while (s != NULL)
    {
        if (strcmp(s->lexeme, lexeme) == 0)
        {
            return; /* Symbol already exists */
        }
        s = s->next;
    }

    /* Add new symbol */
    s = (struct symbol_entry *)malloc(sizeof(struct symbol_entry));
    s->lexeme = strdup(lexeme);
    s->token_type = strdup(token_type);
    s->next = symbol_table;
    symbol_table = s;
}

/* Function to print the symbol table */
void print_symbol_table()
{
    printf("\n----- SYMBOL TABLE -----\n");
    printf("%-4s | %-20s | %-15s\n", "No.", "Lexeme", "Token Type");
    printf("---------------------------------------------\n");
    struct symbol_entry *s = symbol_table;
    int count = 0;

    while (s != NULL)
    {
        printf("%-4d | %-20s | %-15s\n", ++count, s->lexeme, s->token_type);
        s = s->next;
    }
}

/* Function to free the symbol table */
void free_symbol_table()
{
    struct symbol_entry *s = symbol_table;

    while (s != NULL)
    {
        struct symbol_entry *temp = s;
        s = s->next;
        free(temp->lexeme);
        free(temp->token_type);
        free(temp);
    }
    symbol_table = NULL;
}

/* Main function for the lexical analyzer */
int main(int argc, char *argv[])
{
    /* Open the input file if specified */
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            printf("Error: Could not open file %s\n", argv[1]);
            return 1;
        }
    }
    else
    {
        printf("Reading from standard input...\n");
    }

    printf("MICRO C LEXICAL ANALYZER (NON-ITERATIVE VERSION)\n");
    printf("===============================================\n\n");

    /* Process tokens in a non-iterative way */
    yylex();

    /* Print the symbol table */
    print_symbol_table();

    /* Clean up */
    free_symbol_table();
    if (yyin != stdin)
    {
        fclose(yyin);
    }

    return 0;
}