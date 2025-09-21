%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Token codes for different lexemes */
#define KEYWORD 1
#define IDENTIFIER 2
#define INTEGER_CONSTANT 3
#define FLOATING_CONSTANT 4
#define CHAR_CONSTANT 5
#define STRING_LITERAL 6
#define PUNCTUATOR 7
#define COMMENT 8
#define INVALID_TOKEN 9

/* Function declarations - defined in lexical_analyzer.c */
extern void process_token(int token_code, char *lexeme);

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

{KEYWORD}           { return KEYWORD; }
{IDENTIFIER}        { return IDENTIFIER; }
{INTEGER_CONSTANT}  { return INTEGER_CONSTANT; }
{FLOATING_CONSTANT} { return FLOATING_CONSTANT; }
{CHAR_CONSTANT}     { return CHAR_CONSTANT; }
{STRING_LITERAL}    { return STRING_LITERAL; }
{PUNCTUATOR}        { return PUNCTUATOR; }

"/*"                { 
                      char c, prev = 0;
                      while((c = input()) != 0) {
                          if(c == '/' && prev == '*')
                              break;
                          prev = c;
                      }
                      return COMMENT; 
                    }
                    
"//"                { 
                      char c;
                      while((c = input()) != 0 && c != '\n');
                      return COMMENT; 
                    }

{WHITESPACE}        { /* Ignore whitespace */ }
.                   { return INVALID_TOKEN; }

%%

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Token codes for different lexemes */
#define KEYWORD 1
#define IDENTIFIER 2
#define INTEGER_CONSTANT 3
#define FLOATING_CONSTANT 4
#define CHAR_CONSTANT 5
#define STRING_LITERAL 6
#define PUNCTUATOR 7
#define COMMENT 8
#define INVALID_TOKEN 9

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
extern char *yytext;
extern FILE *yyin;
extern int yylineno;
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

/* Function to get token type string based on token code */
char *get_token_type_str(int token_code)
{
    switch (token_code)
    {
    case KEYWORD:
        return "KEYWORD";
    case IDENTIFIER:
        return "IDENTIFIER";
    case INTEGER_CONSTANT:
        return "INTEGER_CONSTANT";
    case FLOATING_CONSTANT:
        return "FLOATING_CONSTANT";
    case CHAR_CONSTANT:
        return "CHAR_CONSTANT";
    case STRING_LITERAL:
        return "STRING_LITERAL";
    case PUNCTUATOR:
        return "PUNCTUATOR";
    case COMMENT:
        return "COMMENT";
    case INVALID_TOKEN:
        return "INVALID_TOKEN";
    default:
        return "UNKNOWN";
    }
}

/* Function to print token information */
void print_token(char *token_type, char *lexeme)
{
    printf("<%s, %s>\n", token_type, lexeme);
}

/* Function to process tokens from flex */
void process_token(int token_code, char *lexeme)
{
    char *token_type = get_token_type_str(token_code);
    print_token(token_type, lexeme);

    /* Add to symbol table only for certain token types */
    if (token_code != KEYWORD && token_code != COMMENT && token_code != INVALID_TOKEN)
    {
        add_to_symbol_table(lexeme, token_type);
    }
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

    printf("MICRO C LEXICAL ANALYZER (ITERATIVE VERSION)\n");
    printf("============================================\n\n");

    /* Process tokens in an iterative way */
    int token;
    while ((token = yylex()) != 0)
    {
        char *token_type = get_token_type_str(token);
        print_token(token_type, yytext);

        /* Add to symbol table only for certain token types */
        if (token != KEYWORD && token != COMMENT && token != INVALID_TOKEN)
        {
            add_to_symbol_table(yytext, token_type);
        }
    }

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