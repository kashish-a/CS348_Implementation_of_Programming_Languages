%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* External declarations */
extern int line_number;
extern void printSymbolTable();

/* Forward declaration for lexer */
int yylex(void);
void yyerror(const char *s) { 
    printf("Ambiguous grammar -> error at line %d: %s\n", line_number, s);
}
%}

/* Declare a union for semantic values */
%union {
    char* str;
    int num;
}

/* For ensuring left and right associativity */
%right '=' 
%right '?' ':'
%left LOGICAL_OR
%left LOGICAL_AND
%left BITWISE_OR
%left BITWISE_XOR
%left '&'
%left EQUAL NOT_EQUAL
%left LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL
%left LEFT_SHIFT RIGHT_SHIFT
%left ADD SUBTRACT
%left MULTIPLY DIVIDE MODULO
%right NOT ADDRESS UNARY_PLUS UNARY_MINUS
%left LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET LEFT_PARENTHESIS RIGHT_PARENTHESIS ARROW INCREMENT DECREMENT

/* Tokens with associated string values */
%token <str> IDENTIFIER INTEGER_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL

/* Other tokens */
%token RETURN VOID FLOAT INTEGER CHAR FOR CONST WHILE DO IF ELSE BOOL
%token BLOCK_BEGIN BLOCK_END
%token LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token ARROW INCREMENT DECREMENT LEFT_SHIFT RIGHT_SHIFT 
%token LESS_THAN_EQUAL GREATER_THAN_EQUAL LESS_THAN GREATER_THAN EQUAL NOT_EQUAL
%token LOGICAL_AND LOGICAL_OR NOT BITWISE_XOR BITWISE_OR
%token QUESTION_MARK COLON SEMICOLON ADDRESS ASSIGN COMMA
%token ADD SUBTRACT MULTIPLY DIVIDE MODULO

/* Nonterminals that produce a string */
%type <str> type_specifier declarator direct_declarator parameter_declaration
%type <str> identifier pointer_opt

%start translation_unit

%%

/* Grammar rules for micro C */

identifier
    : IDENTIFIER
        { $$ = $1; printf("Reduced: identifier -> IDENTIFIER (%s)\n", $1); }
    ;

translation_unit
    : external_declaration 
        { printf("Reduced: translation_unit -> external_declaration\n"); }
    | translation_unit external_declaration
        { printf("Reduced: translation_unit -> translation_unit external_declaration\n"); }
    ;

external_declaration
    : function_definition
        { printf("Reduced: external_declaration -> function_definition\n"); }
    | declaration
        { printf("Reduced: external_declaration -> declaration\n"); }
    ;

function_definition
    : type_specifier declarator compound_statement
        { printf("Reduced: function_definition -> type_specifier declarator compound_statement\n"); }
    ;

declaration
    : type_specifier init_declarator SEMICOLON
        { printf("Reduced: declaration -> type_specifier init_declarator SEMICOLON\n"); }
    ;

init_declarator
    : declarator
        { printf("Reduced: init_declarator -> declarator\n"); }
    | declarator ASSIGN initializer
        { printf("Reduced: init_declarator -> declarator ASSIGN initializer\n"); }
    ;

initializer
    : assignment_expression
        { printf("Reduced: initializer -> assignment_expression\n"); }
    ;

type_specifier
    : VOID      
        { printf("Reduced: type_specifier -> VOID\n"); $$ = "void"; }
    | CHAR      
        { printf("Reduced: type_specifier -> CHAR\n"); $$ = "char"; }
    | FLOAT     
        { printf("Reduced: type_specifier -> FLOAT\n"); $$ = "float"; }
    | INTEGER   
        { printf("Reduced: type_specifier -> INTEGER\n"); $$ = "integer"; }
    | BOOL      
        { printf("Reduced: type_specifier -> BOOL\n"); $$ = "bool"; }
    ;

declarator
    : pointer_opt direct_declarator
        { printf("Reduced: declarator -> pointer_opt direct_declarator\n"); $$ = $2; }
    ;

pointer_opt
    : /* empty */
        { printf("Reduced: pointer_opt -> epsilon\n"); $$ = ""; }
    | MULTIPLY      
        { printf("Reduced: pointer_opt -> '*'\n"); $$ = "*"; }
    ;

direct_declarator
    : identifier
        { printf("Reduced: direct_declarator -> identifier (%s)\n", $1); $$ = $1; }
    | identifier LEFT_SQUARE_BRACKET INTEGER_CONSTANT RIGHT_SQUARE_BRACKET
        { printf("Reduced: direct_declarator -> identifier [ INTEGER_CONSTANT ]\n"); $$ = $1; }
    | identifier LEFT_PARENTHESIS parameter_list_opt RIGHT_PARENTHESIS
        { printf("Reduced: direct_declarator -> identifier ( parameter_list_opt )\n"); $$ = $1; }
    ;

parameter_list_opt
    : /* empty */
        { printf("Reduced: parameter_list_opt -> epsilon\n"); }
    | parameter_list
        { printf("Reduced: parameter_list_opt -> parameter_list\n"); }
    ;

parameter_list
    : parameter_declaration
        { printf("Reduced: parameter_list -> parameter_declaration\n"); }
    | parameter_list COMMA parameter_declaration
        { printf("Reduced: parameter_list -> parameter_list , parameter_declaration\n"); }
    ;

parameter_declaration
    : type_specifier pointer_opt identifier
        { printf("Reduced: parameter_declaration -> type_specifier pointer_opt identifier\n"); $$ = $3; }
    | type_specifier pointer_opt
        { printf("Reduced: parameter_declaration -> type_specifier pointer_opt\n"); $$ = ""; }
    ;

compound_statement
    : BLOCK_BEGIN block_item_list_opt BLOCK_END
        { printf("Reduced: compound_statement -> BLOCK_BEGIN block_item_list_opt BLOCK_END\n"); }
    ;

block_item_list_opt
    : /* empty */
        { printf("Reduced: block_item_list_opt -> epsilon\n"); }
    | block_item_list
        { printf("Reduced: block_item_list -> block_item_list\n"); }
    ;

block_item_list
    : block_item
        { printf("Reduced: block_item_list -> block_item\n"); }
    | block_item_list block_item
        { printf("Reduced: block_item_list -> block_item_list block_item\n"); }
    ;

block_item
    : declaration
        { printf("Reduced: block_item -> declaration\n"); }
    | statement
        { printf("Reduced: block_item -> statement\n"); }
    ;

statement
    : compound_statement
        { printf("Reduced: statement -> compound_statement\n"); }
    | expression_statement
        { printf("Reduced: statement -> expression_statement\n"); }
    | selection_statement
        { printf("Reduced: statement -> selection_statement\n"); }
    | iteration_statement
        { printf("Reduced: statement -> iteration_statement\n"); }
    | jump_statement
        { printf("Reduced: statement -> jump_statement\n"); }
    ;

expression_statement
    : expression_opt SEMICOLON
        { printf("Reduced: expression_statement -> expression_opt SEMICOLON\n"); }
    ;

selection_statement
    : IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement
        { printf("Reduced: selection_statement -> IF ( expression ) statement\n"); }
    | IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement ELSE statement
        { printf("Reduced: selection_statement -> IF ( expression ) statement ELSE statement\n"); }
    ;

iteration_statement
    : FOR LEFT_PARENTHESIS expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RIGHT_PARENTHESIS statement
        { printf("Reduced: iteration_statement -> FOR ( expression_opt ; expression_opt ; expression_opt ) statement\n"); }
    ;

jump_statement
    : RETURN expression_opt SEMICOLON
        { printf("Reduced: jump_statement -> RETURN expression_opt SEMICOLON\n"); }
    ;

expression_opt
    : /* empty */
        { printf("Reduced: expression_opt -> epsilon\n"); }
    | expression
        { printf("Reduced: expression_opt -> expression\n"); }
    ;

expression
    : assignment_expression
        { printf("Reduced: expression -> assignment_expression\n"); }
    ;

assignment_expression
    : conditional_expression
        { printf("Reduced: assignment_expression -> conditional_expression\n"); }
    | unary_expression ASSIGN assignment_expression
        { printf("Reduced: assignment_expression -> unary_expression ASSIGN assignment_expression\n"); }
    ;

conditional_expression
    : logical_or_expression
        { printf("Reduced: conditional_expression -> logical_or_expression\n"); }
    | logical_or_expression QUESTION_MARK expression COLON conditional_expression
        { printf("Reduced: conditional_expression -> logical_or_expression ? expression : conditional_expression\n"); }
    ;

logical_or_expression
    : logical_and_expression
        { printf("Reduced: logical_or_expression -> logical_and_expression\n"); }
    | logical_or_expression LOGICAL_OR logical_and_expression
        { printf("Reduced: logical_or_expression -> logical_or_expression || logical_and_expression\n"); }
    ;

logical_and_expression
    : equality_expression
        { printf("Reduced: logical_and_expression -> equality_expression\n"); }
    | logical_and_expression LOGICAL_AND equality_expression
        { printf("Reduced: logical_and_expression -> logical_and_expression && equality_expression\n"); }
    ;

equality_expression
    : relational_expression
        { printf("Reduced: equality_expression -> relational_expression\n"); }
    | equality_expression EQUAL relational_expression
        { printf("Reduced: equality_expression -> equality_expression == relational_expression\n"); }
    | equality_expression NOT_EQUAL relational_expression
        { printf("Reduced: equality_expression -> equality_expression != relational_expression\n"); }
    ;

relational_expression
    : additive_expression
        { printf("Reduced: relational_expression -> additive_expression\n"); }
    | relational_expression LESS_THAN additive_expression
        { printf("Reduced: relational_expression -> relational_expression < additive_expression\n"); }
    | relational_expression GREATER_THAN additive_expression
        { printf("Reduced: relational_expression -> relational_expression > additive_expression\n"); }
    | relational_expression LESS_THAN_EQUAL additive_expression
        { printf("Reduced: relational_expression -> relational_expression <= additive_expression\n"); }
    | relational_expression GREATER_THAN_EQUAL additive_expression
        { printf("Reduced: relational_expression -> relational_expression >= additive_expression\n"); }
    ;

additive_expression
    : multiplicative_expression
        { printf("Reduced: additive_expression -> multiplicative_expression\n"); }
    | additive_expression ADD multiplicative_expression
        { printf("Reduced: additive_expression -> additive_expression + multiplicative_expression\n"); }
    | additive_expression SUBTRACT multiplicative_expression
        { printf("Reduced: additive_expression -> additive_expression - multiplicative_expression\n"); }
    ;

multiplicative_expression
    : unary_expression
        { printf("Reduced: multiplicative_expression -> unary_expression\n"); }
    | multiplicative_expression MULTIPLY unary_expression
        { printf("Reduced: multiplicative_expression -> multiplicative_expression * unary_expression\n"); }
    | multiplicative_expression DIVIDE unary_expression
        { printf("Reduced: multiplicative_expression -> multiplicative_expression / unary_expression\n"); }
    | multiplicative_expression MODULO unary_expression
        { printf("Reduced: multiplicative_expression -> multiplicative_expression % unary_expression\n"); }
    ;

unary_expression
    : postfix_expression
        { printf("Reduced: unary_expression -> postfix_expression\n"); }
    | unary_operator unary_expression
        { printf("Reduced: unary_expression -> unary_operator unary_expression\n"); }
    ;

unary_operator
    : ADD %prec UNARY_PLUS
        { printf("Reduced: unary_operator -> +\n"); }
    | SUBTRACT %prec UNARY_MINUS
        { printf("Reduced: unary_operator -> -\n"); }
    | NOT
        { printf("Reduced: unary_operator -> !\n"); }
    | ADDRESS
        { printf("Reduced: unary_operator -> &\n"); }
    | MULTIPLY
        { printf("Reduced: unary_operator -> *\n"); }
    ;

postfix_expression
    : primary_expression
        { printf("Reduced: postfix_expression -> primary_expression\n"); }
    | postfix_expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET
        { printf("Reduced: postfix_expression -> postfix_expression [ expression ]\n"); }
    | postfix_expression LEFT_PARENTHESIS argument_expression_list_opt RIGHT_PARENTHESIS
        { printf("Reduced: postfix_expression -> postfix_expression ( argument_expression_list_opt )\n"); }
    | postfix_expression ARROW identifier
        { printf("Reduced: postfix_expression -> postfix_expression -> identifier\n"); }
    ;

primary_expression
    : identifier
        { printf("Reduced: primary_expression -> identifier (%s)\n", $1); }
    | INTEGER_CONSTANT
        { printf("Reduced: primary_expression -> INTEGER_CONSTANT\n"); }
    | FLOAT_CONSTANT
        { printf("Reduced: primary_expression -> FLOAT_CONSTANT\n"); }
    | CHARACTER_CONSTANT
        { printf("Reduced: primary_expression -> CHARACTER_CONSTANT\n"); }
    | STRING_LITERAL
        { printf("Reduced: primary_expression -> STRING_LITERAL\n"); }
    | LEFT_PARENTHESIS expression RIGHT_PARENTHESIS
        { printf("Reduced: primary_expression -> ( expression )\n"); }
    ;

argument_expression_list_opt
    : /* empty */
        { printf("Reduced: argument_expression_list_opt -> epsilon\n"); }
    | argument_expression_list
        { printf("Reduced: argument_expression_list_opt -> argument_expression_list\n"); }
    ;

argument_expression_list
    : assignment_expression
        { printf("Reduced: argument_expression_list -> assignment_expression\n"); }
    | argument_expression_list COMMA assignment_expression
        { printf("Reduced: argument_expression_list -> argument_expression_list , assignment_expression\n"); }
    ;

%%

int main() {
    printf("............. Starting the parsing process .............\n\n");
    yyparse();
    printSymbolTable();
    return 0;
}