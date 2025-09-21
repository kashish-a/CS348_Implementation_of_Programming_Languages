#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Token definitions
enum TokenTypes
{
    TOK_ERROR = -1,
    TOK_KEYWORD = 10,
    TOK_ID = 11,
    TOK_INTEGER = 12,
    TOK_CHAR = 13,
    TOK_STRING = 14,
    TOK_PUNCT = 15,
    TOK_COMMENT_LINE = 16,
    TOK_COMMENT_BLOCK = 17
};

// Simple symbol table structure
struct SymbolEntry
{
    char *name;      // Name of the identifier
    char *type;      // Type of the identifier (if known)
    int line_number; // Line where it first appears
    struct SymbolEntry *next;
};

// Global symbol table head
struct SymbolEntry *symbol_table = NULL;

// Basic keywords list
const char *keywords[] = {
    "int", "char", "float", "double", "void", "if", "else", "while", "for",
    "return", "break", "continue", "printf", "scanf"};
const int keyword_count = 14;

// Forward declarations for flex-generated functions
extern int yylex(void);
extern char *yytext;
extern int yylineno;
extern FILE *yyin;

// Function prototypes
static void analyze_source_file(FILE *source);
static void print_token(int token_type);
static void add_to_symbol_table(const char *name, const char *type, int line_no);
static void write_symbol_table(void);
static void free_symbol_table(void);
static int is_keyword(const char *text);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        printf("Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    yyin = input;
    analyze_source_file(input);
    write_symbol_table();
    free_symbol_table();
    fclose(input);

    return 0;
}

static void analyze_source_file(FILE *source)
{
    int current_token;
    char *current_type = NULL;

    while ((current_token = yylex()) != 0)
    {
        // Store type for subsequent identifiers
        if (current_token == TOK_KEYWORD)
        {
            if (strcmp(yytext, "int") == 0 || strcmp(yytext, "char") == 0 ||
                strcmp(yytext, "float") == 0 || strcmp(yytext, "double") == 0 ||
                strcmp(yytext, "void") == 0)
            {
                current_type = strdup(yytext);
                add_to_symbol_table(yytext, current_type ? current_type : "unknown", yylineno);
            }
        }
        // Add identifiers to symbol table
        else if (current_token == TOK_ID && !is_keyword(yytext))
        {
            add_to_symbol_table(yytext, current_type ? current_type : "unknown", yylineno);
        }
        else if (current_type)
        {
            add_to_symbol_table(yytext, current_type ? current_type : "unknown", yylineno);
        }
        print_token(current_token);
    }

    if (current_type)
    {
        free(current_type);
    }
}

static void print_token(int token_type)
{
    switch (token_type)
    {
    case TOK_KEYWORD:
        printf("<KEYWORD, %s>\n", yytext);
        break;
    case TOK_ID:
        printf("<IDENTIFIER, %s>\n", yytext);
        break;
    case TOK_INTEGER:
        printf("<INT_CONSTANT, %s>\n", yytext);
        break;
    case TOK_CHAR:
        printf("<CHAR_CONSTANT, %s>\n", yytext);
        break;
    case TOK_STRING:
        printf("<STRING_LITERAL, %s>\n", yytext);
        break;
    case TOK_PUNCT:
        printf("<PUNCTUATOR, %s>\n", yytext);
        break;
    case TOK_COMMENT_LINE:
        printf("<SINGLE_LINE_COMMENT at line number %d>\n", yylineno);
        break;
    case TOK_COMMENT_BLOCK:
        printf("<MULTI_LINE_COMMENT at line number %d>\n", yylineno);
        break;
    default:
        printf("<UNEXPECTED TOKEN at line number %d: %s>\n", yylineno, yytext);
    }
}

static int is_keyword(const char *text)
{
    for (int i = 0; i < keyword_count; i++)
    {
        if (strcmp(text, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

static void add_to_symbol_table(const char *name, const char *type, int line_no)
{
    // Check if symbol already exists
    struct SymbolEntry *current = symbol_table;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return; // Symbol already exists
        }
        current = current->next;
    }

    // Create new entry
    struct SymbolEntry *new_entry = (struct SymbolEntry *)malloc(sizeof(struct SymbolEntry));
    new_entry->name = strdup(name);
    new_entry->type = strdup(type);
    new_entry->line_number = line_no;
    new_entry->next = symbol_table;
    symbol_table = new_entry;
}

static void write_symbol_table(void)
{
    FILE *symtab_file = fopen("symbol_table.txt", "w");
    if (!symtab_file)
    {
        printf("Error: Cannot create symbol table file\n");
        return;
    }

    fprintf(symtab_file, "Symbol Table\n");
    fprintf(symtab_file, "%-20s %-15s %-10s\n", "Name", "Type", "Line");
    fprintf(symtab_file, "----------------------------------------\n");

    struct SymbolEntry *current = symbol_table;
    while (current != NULL)
    {
        fprintf(symtab_file, "%-20s %-15s %-10d\n",
                current->name, current->type, current->line_number);
        current = current->next;
    }

    fclose(symtab_file);
}

static void free_symbol_table(void)
{
    struct SymbolEntry *current = symbol_table;
    while (current != NULL)
    {
        struct SymbolEntry *next = current->next;
        free(current->name);
        free(current->type);
        free(current);
        current = next;
    }
    symbol_table = NULL;
}
