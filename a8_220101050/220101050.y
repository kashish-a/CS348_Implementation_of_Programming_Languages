%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void yyerror(const char *s);
int yylex(void);
int binaryToDecimal(const char *binary);
char* binaryToHex(const char *binary);
char* hexToBinary(const char *hex);
int hexToDecimal(const char *hex);
%}

%union {
    int ival;
    char* sval;
}

%token <sval> NUMBER
%token EXPR BINTODEC BINTOHEX HEXTOBIN HEXTODEC
%token PLUS MINUS MULTIPLY DIVIDE POWER
%token LPAREN RPAREN

%type <ival> expr binary_dec_expr
%type <sval> binary_hex_expr hex_bin_expr hex_dec_expr

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right POWER

%%
program: 
    | program calculation

calculation: 
    EXPR LPAREN expr RPAREN    { printf("%d\n", $3); }
    | BINTODEC LPAREN NUMBER RPAREN { 
        int result = binaryToDecimal($3);
        printf("%d\n", result);
        free($3);
    }
    | BINTOHEX LPAREN NUMBER RPAREN {
        char* result = binaryToHex($3);
        printf("%s\n", result);
        free($3);
        free(result);
    }
    | HEXTOBIN LPAREN NUMBER RPAREN {
        char* result = hexToBinary($3);
        printf("%s\n", result);
        free($3);
        free(result);
    }
    | HEXTODEC LPAREN NUMBER RPAREN {
        int result = hexToDecimal($3);
        printf("%d\n", result);
        free($3);
    }
    ;

expr: 
    NUMBER                     { $$ = atoi($1); }
    | expr PLUS expr           { $$ = $1 + $3; }
    | expr MINUS expr          { $$ = $1 - $3; }
    | expr MULTIPLY expr       { $$ = $1 * $3; }
    | expr DIVIDE expr         { $$ = $1 / $3; }
    | expr POWER expr          { $$ = pow($1, $3); }
    | LPAREN expr RPAREN       { $$ = $2; }
    ;

%%

// Binary to Decimal conversion
int binaryToDecimal(const char *binary) {
    int decimal = 0, power = 0;
    int len = strlen(binary);
    
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Binary to Hexadecimal conversion
char* binaryToHex(const char *binary) {
    // First convert binary to decimal
    int decimal = binaryToDecimal(binary);
    
    // Then convert decimal to hex
    char* hex = malloc(20 * sizeof(char));
    sprintf(hex, "%X", decimal);
    return hex;
}

// Hexadecimal to Binary conversion
char* hexToBinary(const char *hex) {
    char* binary = malloc(100 * sizeof(char));
    binary[0] = '\0';
    
    // Conversion table for hex to binary
    const char* hex_to_bin[] = {
        "0000", "0001", "0010", "0011", 
        "0100", "0101", "0110", "0111", 
        "1000", "1001", "1010", "1011", 
        "1100", "1101", "1110", "1111"
    };
    
    for (int i = 0; hex[i]; i++) {
        char c = hex[i];
        int value;
        
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'A' && c <= 'F')
            value = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            value = c - 'a' + 10;
        else {
            free(binary);
            return strdup("Invalid Hex");
        }
        
        strcat(binary, hex_to_bin[value]);
    }
    
    return binary;
}

// Hexadecimal to Decimal conversion
int hexToDecimal(const char *hex) {
    return (int)strtol(hex, NULL, 16);
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}