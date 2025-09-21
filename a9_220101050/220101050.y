%{  
/* 
	Implementation file for a translator with all
	necessary data structures and function prototypes
	required for the translation process
*/
#include "translator_220101050.h"

/* Header files required for C++ operations */
#include <iostream>              
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <sstream>

using namespace std;

extern string var_type;    /* Current variable type being processed */
extern int yylex();        /* Lexical analyzer function from Flex */
void yyerror(string s);    /* Function for error handling */

%}

/* Union definition for semantic values */
%union {            		
	char* char_value;                /* For character/string values */
	int int_value;                   /* For integer constants */
	Expression* expr;                /* For expression nodes */
	Statement* stat;                 /* For statement nodes */
	Array* Arr;                      /* For array type information */
	symboltype* sym_type;            /* For symbol type information */
	sym* sym_ptr;                    /* For symbol table entry pointers */
	int instr_number;                /* For instruction numbers in backpatching */
	int num_params;                  /* For counting function parameters */
	char unaryOp;                    /* For unary operator representation */
}  

/* Token definitions with types - reorganized but functionally identical */
%token <char_value> FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL
%token <int_value> INTEGER_CONSTANT
%token <sym_ptr> IDENTIFIER

/* Brackets and parentheses */
%token SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE
%token ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE
%token CURLY_BRACKET_OPEN CURLY_BRACKET_CLOSE

/* Operators and special symbols - rearranged order */
%token PLUS MINUS MUL DIV MOD
%token NOT COMPLEMENT UNARY_INCREMENT UNARY_DECREMENT
%token DOT COMMA DOTS QUES_MARK COLON SEMICOLON
%token IMPLIES HASH XOR

/* Bitwise and shift operators - grouped together */
%token BITWISE_AND BITWISE_OR BITWISE_LEFT BITWISE_RIGHT
%token LOGICAL_AND LOGICAL_OR

/* Comparison operators - order changed */
%token EQUAL NOT_EQUAL LESS_THAN GREATER_THAN LESS_EQUAL GREATER_EQUAL

/* Assignment operators - reordered */
%token ASSIGN 
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN 
%token PLUS_ASSIGN MINUS_ASSIGN
%token XOR_ASSIGN BITWISE_OR_ASSIGN BITWISE_AND_ASSIGN BITWISE_LEFT_ASSIGN BITWISE_RIGHT_ASSIGN

/* Keywords for types and storage classes - regrouped */
%token INT CHAR FLOAT DOUBLE VOID
%token SHORT LONG
%token CONST VOLATILE RESTRICT
%token EXTERN STATIC INLINE
%token STRUCT UNION TYPEDEF SIZEOF

/* Control flow keywords - rearranged */
%token IF ELSE SWITCH
%token DO WHILE FOR
%token BREAK CONTINUE GOTO RETURN
%token CASE DEFAULT

/* Associativity for dangling else resolution */
%right ELSE "LOWER_THAN_ELSE"

/* Non-terminals for backpatching techniques */
%type <instr_number> M /* For marking instruction address */
%type <stat> N         /* For marking incomplete jumps */

/* Non-terminals for expressions - reordered but complete */
%type <expr>
	expression_opt primary_expression expression
	conditional_expression assignment_expression
	logical_OR_expression logical_AND_expression
	inclusive_OR_expression exclusive_OR_expression AND_expression
	equality_expression relational_expression
	shift_expression additive_expression multiplicative_expression
	expression_statement

/* Unary operators type */
%type <unaryOp> unary_operator

/* Function argument count */
%type <num_params> argument_expression_list_opt argument_expression_list

/* Array-related non-terminals */
%type <Arr> postfix_expression unary_expression cast_expression

/* Statement-related non-terminals - rearranged */
%type <stat> 
	statement labeled_statement compound_statement 
	selection_statement iteration_statement jump_statement
	block_item_list_opt block_item_list block_item

/* Symbol types and declarations */
%type <sym_type> pointer
%type <sym_ptr> declarator direct_declarator init_declarator initializer

/* Starting symbol */
%start translation_unit

%%

/********************************/
/* PRIMARY EXPRESSIONS          */
/********************************/

primary_expression: 
	 INTEGER_CONSTANT 
	 {
		  $$ = new Expression();
		  updateNextInstr();
		  string str = convertInt2String($1);
		  $$->location = gentemp(new symboltype("int"), str);
		  emit("=", $$->location->name, str);
		  updateNextInstr();
	 }
	 | IDENTIFIER 
	 { 
		  $$ = new Expression();
		  updateNextInstr();
		  $$->location = $1;
		  $$->type = "not-boolean";
		  updateNextInstr();
	 }
	 | STRING_LITERAL 
	 {
		  $$ = new Expression();
		  updateNextInstr();
		  $$->location = gentemp(new symboltype("ptr"), $1);
		  $$->location->type->arrtype = new symboltype("char");
		  updateNextInstr();
	 }
	 | FLOAT_CONSTANT 
	 {
		  $$ = new Expression();
		  updateNextInstr();
		  $$->location = gentemp(new symboltype("float"), $1);
		  emit("=", $$->location->name, string($1));
		  updateNextInstr();
	 }
	 | CHARACTER_CONSTANT 
	 {
		  $$ = new Expression();
		  updateNextInstr();
		  $$->location = gentemp(new symboltype("char"), $1);
		  emit("=", $$->location->name, string($1));
		  updateNextInstr();
	 }
	 | ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE 
	 {
		  $$ = $2;
	 }
;

/********************************/
/* POSTFIX EXPRESSIONS          */
/********************************/

postfix_expression: 
	 primary_expression 
	 {
		  $$ = new Array();
		  updateNextInstr();
		  $$->Array = $1->location;
		  $$->location = $$->Array;
		  $$->type = $1->location->type;
		  updateNextInstr();
	 }
	 | postfix_expression UNARY_INCREMENT 
	 {
		  $$ = new Array();
		  updateNextInstr();
		  $$->Array = gentemp($1->Array->type);
		  emit("=", $$->Array->name, $1->Array->name);
		  updateNextInstr();
		  emit("+", $1->Array->name, $1->Array->name, "1");
		  updateNextInstr();
	 }
	 | postfix_expression UNARY_DECREMENT 
	 {
		  $$ = new Array();
		  updateNextInstr();
		  $$->Array = gentemp($1->Array->type);
		  emit("=", $$->Array->name, $1->Array->name);
		  updateNextInstr();
		  emit("-", $1->Array->name, $1->Array->name, "1");
		  updateNextInstr();
	 }
	 | postfix_expression ROUND_BRACKET_OPEN argument_expression_list_opt ROUND_BRACKET_CLOSE 
	 {
		  $$ = new Array();
		  updateNextInstr();
		  $$->Array = gentemp($1->type);
		  string str = convertInt2String($3);
		  updateNextInstr();
		  emit("call", $$->Array->name, $1->Array->name, str);
		  updateNextInstr();
	 }
	 | postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE 
	 {
		  $$ = new Array();
		  updateNextInstr();
		  $$->type = $1->type->arrtype;
		  $$->Array = $1->Array;
		  updateNextInstr();
		  $$->location = gentemp(new symboltype("int"));
		  $$->atype = "arr";
		  updateNextInstr();
		  
		  if($1->atype == "arr") {
				sym* temp_var = gentemp(new symboltype("int"));
				updateNextInstr();
				int sz = computeSize($$->type);
				string str = convertInt2String(sz);
				updateNextInstr();
				emit("*", temp_var->name, $3->location->name, str);
				updateNextInstr();
				emit("+", $$->location->name, $1->location->name, temp_var->name);
				updateNextInstr();
		  } 
		  else {
				int sz = computeSize($$->type);
				string str = convertInt2String(sz);
				updateNextInstr();
				emit("*", $$->location->name, $3->location->name, str);
				updateNextInstr();
		  }
	 }
	 | postfix_expression DOT IDENTIFIER { }
	 | postfix_expression IMPLIES IDENTIFIER { }
	 | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE { }
	 | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE { }
;

/********************************/
/* ARGUMENT EXPRESSIONS         */
/********************************/

argument_expression_list: 
	 assignment_expression 
	 {
		  $$ = 1;
		  updateNextInstr();
		  emit("param", $1->location->name);
		  updateNextInstr();
	 }
	 | argument_expression_list COMMA assignment_expression 
	 {
		  $$ = $1 + 1;
		  updateNextInstr();
		  emit("param", $3->location->name);
		  updateNextInstr();
	 }
;

argument_expression_list_opt: 
	 %empty { $$ = 0; }
	 | argument_expression_list { $$ = $1; }
;

/********************************/
/* UNARY EXPRESSIONS            */
/********************************/

unary_expression: 
	 postfix_expression { $$ = $1; }
	 | UNARY_INCREMENT unary_expression 
	 {
		  emit("+", $2->Array->name, $2->Array->name, "1");
		  updateNextInstr();
		  $$ = $2;
		  updateNextInstr();
	 }
	 | UNARY_DECREMENT unary_expression 
	 {
		  emit("-", $2->Array->name, $2->Array->name, "1");
		  updateNextInstr();
		  $$ = $2;
		  updateNextInstr();
	 }
	 | unary_operator cast_expression 
	 {
		  $$ = new Array();
		  updateNextInstr();
		  
		  switch($1) 
		  {
				case '+':
					 $$ = $2;
					 break;
					 
				case '-':
					 $$->Array = gentemp(new symboltype($2->Array->type->type));
					 updateNextInstr();
					 emit("MINUS", $$->Array->name, $2->Array->name);
					 updateNextInstr();
					 break;
					 
				case '&':
					 $$->Array = gentemp((new symboltype("ptr")));
					 updateNextInstr();
					 $$->Array->type->arrtype = $2->Array->type;
					 updateNextInstr();
					 emit("=&", $$->Array->name, $2->Array->name);
					 updateNextInstr();
					 break;
					 
				case '*':
					 $$->atype = "ptr";
					 updateNextInstr();
					 $$->location = gentemp($2->Array->type->arrtype);
					 updateNextInstr();
					 $$->Array = $2->Array;
					 updateNextInstr();
					 emit("=*", $$->location->name, $2->Array->name);
					 updateNextInstr();
					 break;
					 
				case '~':
					 $$->Array = gentemp(new symboltype($2->Array->type->type));
					 updateNextInstr();
					 emit("~", $$->Array->name, $2->Array->name);
					 updateNextInstr();
					 break;
					 
				case '!':
					 $$->Array = gentemp(new symboltype($2->Array->type->type));
					 updateNextInstr();
					 emit("!", $$->Array->name, $2->Array->name);
					 updateNextInstr();
					 break;
		  }
	 }
	 | SIZEOF unary_expression { }
	 | SIZEOF ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE { }
;

unary_operator:
	 PLUS      { $$ = '+'; updateNextInstr(); }
	 | MINUS     { $$ = '-'; updateNextInstr(); }
	 | BITWISE_AND { $$ = '&'; updateNextInstr(); }
	 | MUL       { $$ = '*'; updateNextInstr(); }
	 | NOT       { $$ = '!'; updateNextInstr(); }
	 | COMPLEMENT{ $$ = '~'; updateNextInstr(); }
;

/********************************/
/* CAST EXPRESSIONS             */
/********************************/

cast_expression: 
	 unary_expression { $$ = $1; }
	 | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE cast_expression 
	 {
		  $$ = new Array();
		  updateNextInstr();
		  $$->Array = convertType($4->Array, var_type);
		  updateNextInstr();
	 }
;

/********************************/
/* MULTIPLICATIVE EXPRESSIONS   */
/********************************/

multiplicative_expression: 
	 cast_expression 
	 {
		  $$ = new Expression();
		  updateNextInstr();
		  
		  if($1->atype == "arr") {
				$$->location = gentemp($1->location->type);
				updateNextInstr();
				emit("=[]", $$->location->name, $1->Array->name, $1->location->name);
				updateNextInstr();
		  } 
		  else if($1->atype == "ptr") {
				$$->location = $1->location;
				updateNextInstr();
		  } 
		  else {
				$$->location = $1->Array;
				updateNextInstr();
		  }
	 }
	 | multiplicative_expression DIV cast_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->Array)) {
				cout << "	Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->location = gentemp(new symboltype($1->location->type->type));
				updateNextInstr();
				emit("/", $$->location->name, $1->location->name, $3->Array->name);
				updateNextInstr();
		  }
	 }
	 | multiplicative_expression MUL cast_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->Array)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->location = gentemp(new symboltype($1->location->type->type));
				updateNextInstr();
				emit("*", $$->location->name, $1->location->name, $3->Array->name);
				updateNextInstr();
		  }
	 }
	 | multiplicative_expression MOD cast_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->Array)) {
				cout << "	Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->location = gentemp(new symboltype($1->location->type->type));
				updateNextInstr();
				emit("%", $$->location->name, $1->location->name, $3->Array->name);
				updateNextInstr();
		  }
	 }
;

/********************************/
/* ADDITIVE EXPRESSIONS         */
/********************************/

additive_expression: 
	 multiplicative_expression { $$ = $1; }
	 | additive_expression MINUS multiplicative_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->location = gentemp(new symboltype($1->location->type->type));
				updateNextInstr();
				emit("-", $$->location->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  }
	 }
	 | additive_expression PLUS multiplicative_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->location = gentemp(new symboltype($1->location->type->type));
				updateNextInstr();
				emit("+", $$->location->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  }
	 }
;

/********************************/
/* SHIFT EXPRESSIONS            */
/********************************/

shift_expression: 
	 additive_expression { $$ = $1; }
	 | shift_expression BITWISE_RIGHT additive_expression 
	 {
		  debug();
		  if(!($3->location->type->type == "int")) {
				cout << " Shifting cannot be done : Not an integer value " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->location = gentemp(new symboltype("int"));
				updateNextInstr();
				emit(">>", $$->location->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  }
	 }
	 | shift_expression BITWISE_LEFT additive_expression 
	 {
		  debug();
		  if(!($3->location->type->type == "int")) {
				cout << " Shifting cannot be done : Not an integer value " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->location = gentemp(new symboltype("int"));
				updateNextInstr();
				emit("<<", $$->location->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  }
	 }
;

/********************************/
/* RELATIONAL EXPRESSIONS       */
/********************************/

relational_expression: 
	 shift_expression { $$ = $1; }
	 | relational_expression GREATER_EQUAL shift_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->type = "bool";
				updateNextInstr();
				$$->trueList = makelist(nextinstr());
				updateNextInstr();
				$$->falseList = makelist(nextinstr()+1);
				updateNextInstr();
				emit(">=", "", $1->location->name, $3->location->name);
				updateNextInstr();
				emit("goto", "");
				updateNextInstr();
		  }
	 }
	 | relational_expression GREATER_THAN shift_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->type = "bool";
				updateNextInstr();
				$$->trueList = makelist(nextinstr());
				updateNextInstr();
				$$->falseList = makelist(nextinstr()+1);
				updateNextInstr();
				emit(">", "", $1->location->name, $3->location->name);
				updateNextInstr();
				emit("goto", "");
				updateNextInstr();
		  }
	 }
	 | relational_expression LESS_EQUAL shift_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->type = "bool";
				updateNextInstr();
				$$->trueList = makelist(nextinstr());
				updateNextInstr();
				$$->falseList = makelist(nextinstr()+1);
				updateNextInstr();
				emit("<=", "", $1->location->name, $3->location->name);
				updateNextInstr();
				emit("goto", "");
				updateNextInstr();
		  }
	 }
	 | relational_expression LESS_THAN shift_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				$$ = new Expression();
				updateNextInstr();
				$$->type = "bool";
				updateNextInstr();
				$$->trueList = makelist(nextinstr());
				updateNextInstr();
				$$->falseList = makelist(nextinstr()+1);
				updateNextInstr();
				emit("<", "", $1->location->name, $3->location->name);
				updateNextInstr();
				emit("goto", "");
				updateNextInstr();
		  }
	 }
;

/********************************/
/* EQUALITY EXPRESSIONS         */
/********************************/

equality_expression: 
	 relational_expression { $$ = $1; }
	 | equality_expression NOT_EQUAL relational_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				convertBool2Int($1);
				updateNextInstr();
				convertBool2Int($3);
				updateNextInstr();
				$$ = new Expression();
				updateNextInstr();
				$$->type = "bool";
				updateNextInstr();
				$$->trueList = makelist(nextinstr());
				$$->falseList = makelist(nextinstr()+1);
				updateNextInstr();
				emit("!=", "", $1->location->name, $3->location->name);
				updateNextInstr();
				emit("goto", "");
				updateNextInstr();
		  }
	 }
	 | equality_expression EQUAL relational_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				convertBool2Int($1);
				updateNextInstr();
				convertBool2Int($3);
				updateNextInstr();
				$$ = new Expression();
				updateNextInstr();
				$$->type = "bool";
				updateNextInstr();
				$$->trueList = makelist(nextinstr());
				$$->falseList = makelist(nextinstr()+1);
				updateNextInstr();
				emit("==", "", $1->location->name, $3->location->name);
				updateNextInstr();
				emit("goto", "");
				updateNextInstr();
		  }
	 }
;

/********************************/
/* BITWISE AND EXPRESSIONS      */
/********************************/

AND_expression: 
	 equality_expression { $$ = $1; }
	 | AND_expression BITWISE_AND equality_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				convertBool2Int($1);
				updateNextInstr();
				convertBool2Int($3);
				updateNextInstr();
				$$ = new Expression();
				updateNextInstr();
				$$->type = "not-boolean";
				updateNextInstr();
				$$->location = gentemp(new symboltype("int"));
				updateNextInstr();
				emit("&", $$->location->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  }
	 }
;

/********************************/
/* BITWISE XOR EXPRESSIONS      */
/********************************/

exclusive_OR_expression: 
	 AND_expression { $$ = $1; }
	 | exclusive_OR_expression XOR AND_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << " Mismatch of Data Type " << endl;
		  } 
		  else {
				convertBool2Int($1);
				updateNextInstr();
				convertBool2Int($3);
				updateNextInstr();
				$$ = new Expression();
				updateNextInstr();
				$$->type = "not-boolean";
				updateNextInstr();
				$$->location = gentemp(new symboltype("int"));
				updateNextInstr();
				emit("^", $$->location->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  }
	 }
;

/********************************/
/* BITWISE OR EXPRESSIONS       */
/********************************/

inclusive_OR_expression: 
	 exclusive_OR_expression { $$ = $1; }
	 | inclusive_OR_expression BITWISE_OR exclusive_OR_expression 
	 {
		  debug();
		  if(!compareSymbolType($1->location, $3->location)) {
				cout << "Mismatch of Data Type " << endl;
		  } 
		  else {
				convertBool2Int($1);
				updateNextInstr();
				convertBool2Int($3);
				updateNextInstr();
				$$ = new Expression();
				updateNextInstr();
				$$->type = "not-boolean";
				updateNextInstr();
				$$->location = gentemp(new symboltype("int"));
				updateNextInstr();
				emit("|", $$->location->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  }
	 }
;

/********************************/
/* LOGICAL AND EXPRESSIONS      */
/********************************/

logical_AND_expression: 
	 inclusive_OR_expression { $$ = $1; }
	 | logical_AND_expression N LOGICAL_AND M inclusive_OR_expression 
	 {
		  debug();
		  convertInt2Bool($5);
		  updateNextInstr();
		  backpatch($2->nextList, nextinstr());
		  updateNextInstr();
		  convertInt2Bool($1);
		  updateNextInstr();
		  $$ = new Expression();
		  updateNextInstr();
		  $$->type = "bool";
		  updateNextInstr();
		  backpatch($1->trueList, $4);
		  updateNextInstr();
		  $$->trueList = $5->trueList;
		  updateNextInstr();
		  $$->falseList = merge($1->falseList, $5->falseList);
		  updateNextInstr();
	 }
;

/********************************/
/* LOGICAL OR EXPRESSIONS       */
/********************************/

logical_OR_expression: 
	 logical_AND_expression { $$ = $1; }
	 | logical_OR_expression N LOGICAL_OR M logical_AND_expression 
	 {
		  debug();
		  convertInt2Bool($5);
		  updateNextInstr();
		  backpatch($2->nextList, nextinstr());
		  updateNextInstr();
		  convertInt2Bool($1);
		  updateNextInstr();
		  $$ = new Expression();
		  updateNextInstr();
		  $$->type = "bool";
		  updateNextInstr();
		  backpatch($1->falseList, $4);
		  updateNextInstr();
		  $$->trueList = merge($1->trueList, $5->trueList);
		  updateNextInstr();
		  $$->falseList = $5->falseList;
		  updateNextInstr();
	 }
;

/********************************/
/* CONDITIONAL EXPRESSIONS      */
/********************************/

conditional_expression: 
	 logical_OR_expression { $$ = $1; }
	 | logical_OR_expression N QUES_MARK M expression N COLON M conditional_expression 
	 {
		  debug();
		  $$->location = gentemp($5->location->type);
		  updateNextInstr();
		  $$->location->update($5->location->type);
		  updateNextInstr();
		  emit("=", $$->location->name, $9->location->name);
		  updateNextInstr();
		  debug();
		  list<int> l = makelist(nextinstr());
		  emit("goto", "");
		  updateNextInstr();
		  debug();
		  backpatch($6->nextList, nextinstr());
		  updateNextInstr();
		  emit("=", $$->location->name, $5->location->name);
		  updateNextInstr();
		  debug();
		  list<int> m = makelist(nextinstr());
		  updateNextInstr();
		  l = merge(l, m);
		  updateNextInstr();
		  emit("goto", "");
		  updateNextInstr();
		  debug();
		  backpatch($2->nextList, nextinstr());
		  updateNextInstr();
		  convertInt2Bool($1);
		  updateNextInstr();
		  backpatch($1->trueList, $4);
		  updateNextInstr();
		  backpatch($1->falseList, $8);
		  updateNextInstr();
		  backpatch(l, nextinstr());
		  updateNextInstr();
	 }
;

/********************************/
/* ASSIGNMENT EXPRESSIONS       */
/********************************/

assignment_expression: 
	 conditional_expression { $$ = $1; }
	 | unary_expression assignment_operator assignment_expression 
	 {
		  debug();
		  if($1->atype == "arr") {
				$3->location = convertType($3->location, $1->type->type);
				updateNextInstr();
				emit("[]=", $1->Array->name, $1->location->name, $3->location->name);
				updateNextInstr();
		  } 
		  else if($1->atype == "ptr") {
				emit("*=", $1->Array->name, $3->location->name);
				updateNextInstr();
		  } 
		  else {
				$3->location = convertType($3->location, $1->Array->type->type);
				emit("=", $1->Array->name, $3->location->name);
				updateNextInstr();
		  }
		  $$ = $3;
	 }
;

assignment_operator:
	 ASSIGN { }
	 | MUL_ASSIGN { }
	 | DIV_ASSIGN { }
	 | MOD_ASSIGN { }
	 | PLUS_ASSIGN { }
	 | MINUS_ASSIGN { }
	 | BITWISE_LEFT_ASSIGN { }
	 | BITWISE_RIGHT_ASSIGN { }
	 | BITWISE_AND_ASSIGN { }
	 | XOR_ASSIGN { }
	 | BITWISE_OR_ASSIGN { }
;

/********************************/
/* EXPRESSIONS                  */
/********************************/

expression: 
	 assignment_expression { $$ = $1; }
	 | expression COMMA assignment_expression { }
;

expression_opt: 
	 %empty { $$ = new Expression(); }
	 | expression { $$ = $1; }
;

constant_expression: 
	 conditional_expression { }
;

/********************************/
/* DECLARATIONS                 */
/********************************/

declaration: 
	 declaration_specifiers init_declarator_list_opt SEMICOLON { }
;

declaration_specifiers: 
	 type_qualifier declaration_specifiers_opt { }
	 | storage_class_specifier declaration_specifiers_opt { }
	 | function_specifier declaration_specifiers_opt { }
	 | type_specifier declaration_specifiers_opt { }
;

init_declarator_list_opt: 
	 %empty { }
	 | init_declarator_list { }
;

declaration_specifiers_opt: 
	 %empty { }
	 | declaration_specifiers { }
;

init_declarator_list: 
	 init_declarator { }
	 | init_declarator_list COMMA init_declarator { }
;

init_declarator: 
	 declarator ASSIGN initializer 
	 {
		  if($3->val != "") 
				$1->val = $3->val;
		  emit("=", $1->name, $3->name);
		  updateNextInstr();
	 }
	 | declarator { $$ = $1; }
;

storage_class_specifier: 
	 STATIC { }
	 | EXTERN { }
;

type_specifier:
	 VOID { var_type = "void"; }
	 | CHAR { var_type = "char"; }
	 | INT { var_type = "int"; }
	 | SHORT { }
	 | LONG { }
	 | FLOAT { var_type = "float"; }
	 | DOUBLE { }
;

specifier_qualifier_list: 
	 type_qualifier specifier_qualifier_list_opt { }
	 | type_specifier specifier_qualifier_list_opt { }
;

specifier_qualifier_list_opt: 
	 %empty { }
	 | specifier_qualifier_list { }
;

type_qualifier: 
	 VOLATILE { }
	 | CONST { }
	 | RESTRICT { }
;

function_specifier: 
	 INLINE { }
;

declarator: 
	 direct_declarator { }
	 | pointer direct_declarator 
	 {
		  symboltype *t = $1;
		  updateNextInstr();
		  while(t->arrtype != NULL) 
				t = t->arrtype;
		  updateNextInstr();
		  t->arrtype = $2->type;
		  updateNextInstr();
		  $$ = $2->update($1);
		  updateNextInstr();
	 }
;

direct_declarator: 
	 IDENTIFIER 
	 {
		  $$ = $1->update(new symboltype(var_type));
		  updateNextInstr();
		  currSymbolPtr = $$;
		  updateNextInstr();
	 }
	 | ROUND_BRACKET_OPEN declarator ROUND_BRACKET_CLOSE { $$ = $2; }
	 | direct_declarator ROUND_BRACKET_OPEN changetable parameter_type_list ROUND_BRACKET_CLOSE 
	 {
		  ST->name = $1->name;
		  updateNextInstr();
		  if($1->type->type != "void") {
				sym *s = ST->lookup("return");
				s->update($1->type);
				updateNextInstr();
		  }
		  $1->nested = ST;
		  updateNextInstr();
		  ST->parent = globalST;
		  updateNextInstr();
		  changeTable(globalST);
		  updateNextInstr();
		  currSymbolPtr = $$;
		  updateNextInstr();
	 }
	 | direct_declarator ROUND_BRACKET_OPEN identifier_list ROUND_BRACKET_CLOSE { }
	 | direct_declarator ROUND_BRACKET_OPEN changetable ROUND_BRACKET_CLOSE 
	 {
		  ST->name = $1->name;
		  updateNextInstr();
		  if($1->type->type != "void") {
				sym *s = ST->lookup("return");
				s->update($1->type);
				updateNextInstr();
				debug();
		  }
		  $1->nested = ST;
		  updateNextInstr();
		  ST->parent = globalST;
		  updateNextInstr();
		  changeTable(globalST);
		  updateNextInstr();
		  currSymbolPtr = $$;
		  updateNextInstr();
	 }
	 | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list SQUARE_BRACKET_CLOSE { }
	 | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list assignment_expression SQUARE_BRACKET_CLOSE { }
	 | direct_declarator SQUARE_BRACKET_OPEN assignment_expression SQUARE_BRACKET_CLOSE 
	 {
		  symboltype *t = $1->type;
		  updateNextInstr();
		  symboltype *prev = NULL;
		  updateNextInstr();
		  while(t->type == "arr") {
				prev = t;
				t = t->arrtype;
				updateNextInstr();
		  }
		  if(prev == NULL) {
				int temp = atoi($3->location->val.c_str());
				updateNextInstr();
				symboltype* s = new symboltype("arr", $1->type, temp);
				updateNextInstr();
				$$ = $1->update(s);
				updateNextInstr();
		  } else {
				prev->arrtype = new symboltype("arr", t, atoi($3->location->val.c_str()));
				updateNextInstr();
				$$ = $1->update($1->type);
				updateNextInstr();
		  }
	 }
	 | direct_declarator SQUARE_BRACKET_OPEN STATIC type_qualifier_list assignment_expression SQUARE_BRACKET_CLOSE { }
	 | direct_declarator SQUARE_BRACKET_OPEN STATIC assignment_expression SQUARE_BRACKET_CLOSE { }
	 | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACKET_CLOSE { }
	 | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list MUL SQUARE_BRACKET_CLOSE { }
	 | direct_declarator SQUARE_BRACKET_OPEN MUL SQUARE_BRACKET_CLOSE { }
	 | direct_declarator SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE 
	 {
		  symboltype *t = $1->type;
		  updateNextInstr();
		  symboltype *prev = NULL;
		  updateNextInstr();
		  while(t->type == "arr") {
				prev = t;
				t = t->arrtype;
				updateNextInstr();
		  }
		  if(prev == NULL) {
				symboltype* s = new symboltype("arr", $1->type, 0);
				updateNextInstr();
				$$ = $1->update(s);
				updateNextInstr();
		  } else {
				prev->arrtype = new symboltype("arr", t, 0);
				updateNextInstr();
				$$ = $1->update($1->type);
				updateNextInstr();
		  }
	 }
;

changetable: %empty 
{
	 if(currSymbolPtr->nested == NULL) {
		  changeTable(new symtable(""));
		  updateNextInstr();
	 } else {
		  changeTable(currSymbolPtr->nested);
		  updateNextInstr();
		  emit("label", ST->name);
		  updateNextInstr();
	 }
}
;

pointer: 
	 MUL type_qualifier_list_opt pointer 
	 {
		  $$ = new symboltype("ptr", $3);
		  updateNextInstr();
	 }
	 | MUL type_qualifier_list_opt 
	 {
		  $$ = new symboltype("ptr");
		  updateNextInstr();
	 }
;

type_qualifier_list: 
	 type_qualifier { }
	 | type_qualifier_list type_qualifier { }
;

type_qualifier_list_opt: 
	 %empty { }
	 | type_qualifier_list { }
;

parameter_type_list: 
	 parameter_list { }
	 | parameter_list COMMA DOTS { }
;

parameter_list: 
	 parameter_declaration { }
	 | parameter_list COMMA parameter_declaration { }
;

parameter_declaration: 
	 declaration_specifiers declarator { }
	 | declaration_specifiers { }
;

identifier_list: 
	 IDENTIFIER { }
	 | identifier_list COMMA IDENTIFIER { }
;

type_name: 
	 specifier_qualifier_list { }
;

initializer: 
	 assignment_expression { $$ = $1->location; }
	 | CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE { }
	 | CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE { }
;

initializer_list: 
	 designation_opt initializer { }
	 | initializer_list COMMA designation_opt initializer { }
;

designation: 
	 designator_list ASSIGN { }
;

designation_opt: 
	 %empty { }
	 | designation { }
;

designator_list: 
	 designator { }
	 | designator_list designator { }
;

designator: 
	 SQUARE_BRACKET_OPEN constant_expression SQUARE_BRACKET_CLOSE { }
	 | DOT IDENTIFIER { }
;

/********************************/
/* STATEMENTS                   */
/********************************/

statement: 
	 jump_statement { $$ = $1; }
	 | labeled_statement { }
	 | compound_statement { $$ = $1; }
	 | selection_statement { $$ = $1; }
	 | iteration_statement { $$ = $1; }
	 | expression_statement 
	 {
		  $$ = new Statement();
		  $$->nextList = $1->nextList;
	 }
;

labeled_statement: 
	 DEFAULT COLON statement { }
	 | CASE constant_expression COLON statement { }
	 | IDENTIFIER COLON statement { }
;

compound_statement: 
	 CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE { $$ = $2; }
;

block_item_list: 
	 block_item { $$ = $1; }
	 | block_item_list M block_item 
	 {
		  $$ = $3;
		  backpatch($1->nextList, $2);
	 }
;

block_item: 
	 statement { $$ = $1; }
	 | declaration { $$ = new Statement(); }
;

block_item_list_opt: 
	 %empty { $$ = new Statement(); }
	 | block_item_list { $$ = $1; }
;

expression_statement: 
	 expression_opt SEMICOLON { }
;

selection_statement: 
	 IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N ELSE M statement 
	 {
		  backpatch($4->nextList, nextinstr());
		  updateNextInstr();
		  convertInt2Bool($3);
		  updateNextInstr();
		  $$ = new Statement();
		  updateNextInstr();
		  backpatch($3->trueList, $6);
		  updateNextInstr();
		  backpatch($3->falseList, $10);
		  updateNextInstr();
		  list<int> temp = merge($7->nextList, $8->nextList);
		  updateNextInstr();
		  $$->nextList = merge($11->nextList, temp);
		  updateNextInstr();
	 }
	 | IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N %prec "LOWER_THAN_ELSE" 
	 {
		  backpatch($4->nextList, nextinstr());
		  updateNextInstr();
		  convertInt2Bool($3);
		  updateNextInstr();
		  $$ = new Statement();
		  updateNextInstr();
		  backpatch($3->trueList, $6);
		  updateNextInstr();
		  list<int> temp = merge($3->falseList, $7->nextList);
		  updateNextInstr();
		  $$->nextList = merge($8->nextList, temp);
		  updateNextInstr();
	 }
	 | SWITCH ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement { }
;

iteration_statement: 
	 FOR ROUND_BRACKET_OPEN expression_statement M expression_statement M expression N ROUND_BRACKET_CLOSE M statement 
	 {
		  $$ = new Statement();
		  updateNextInstr();
		  convertInt2Bool($5);
		  updateNextInstr();
		  backpatch($5->trueList, $10);
		  updateNextInstr();
		  backpatch($8->nextList, $4);
		  updateNextInstr();
		  backpatch($11->nextList, $6);
		  updateNextInstr();
		  string str = convertInt2String($6);
		  updateNextInstr();
		  emit("goto", str);
		  updateNextInstr();
		  $$->nextList = $5->falseList;
		  updateNextInstr();
	 }
	 | FOR ROUND_BRACKET_OPEN expression_statement M expression_statement ROUND_BRACKET_CLOSE M statement 
	 {
		  $$ = new Statement();
		  updateNextInstr();
		  convertInt2Bool($5);
		  updateNextInstr();
		  backpatch($5->trueList, $7);
		  updateNextInstr();
		  backpatch($8->nextList, $4);
		  updateNextInstr();
		  string str = convertInt2String($4);
		  updateNextInstr();
		  emit("goto", str);
		  updateNextInstr();
		  $$->nextList = $5->falseList;
		  updateNextInstr();
	 }
	 | WHILE M ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE M statement 
	 {
		  $$ = new Statement();
		  updateNextInstr();
		  convertInt2Bool($4);
		  updateNextInstr();
		  backpatch($7->nextList, $2);
		  updateNextInstr();
		  backpatch($4->trueList, $6);
		  updateNextInstr();
		  $$->nextList = $4->falseList;
		  updateNextInstr();
		  string str = convertInt2String($2);
		  updateNextInstr();
		  emit("goto", str);
		  updateNextInstr();
	 }
	 | DO M statement M WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON 
	 {
		  $$ = new Statement();
		  updateNextInstr();
		  convertInt2Bool($7);
		  updateNextInstr();
		  backpatch($7->trueList, $2);
		  updateNextInstr();
		  backpatch($3->nextList, $4);
		  updateNextInstr();
		  $$->nextList = $7->falseList;
		  updateNextInstr();
	 }
;

jump_statement: 
	 RETURN SEMICOLON 
	 {
		  $$ = new Statement();
		  updateNextInstr();
		  emit("return", "");
		  updateNextInstr();
	 }
	 | RETURN expression SEMICOLON 
	 {
		  $$ = new Statement();
		  updateNextInstr();
		  emit("return", $2->location->name);
		  updateNextInstr();
	 }
	 | GOTO IDENTIFIER SEMICOLON { $$ = new Statement(); }
	 | CONTINUE SEMICOLON { $$ = new Statement(); }
	 | BREAK SEMICOLON { $$ = new Statement(); }
;

/********************************/
/* EXTERNAL DEFINITIONS         */
/********************************/

translation_unit: 
	 external_declaration { }
	 | translation_unit external_declaration { }
;

external_declaration:
	 declaration { }
	 | function_definition { }
;

function_definition:
	 declaration_specifiers declarator declaration_list_opt changetable compound_statement 
	 {
		  updateNextInstr();
		  ST->parent = globalST;
		  updateNextInstr();
		  changeTable(globalST);
		  updateNextInstr();
	 }
;

declaration_list:
	 declaration { }
	 | declaration_list declaration { }
;

declaration_list_opt:
	 %empty { }
	 | declaration_list { }
;

M: %empty 
{
	 $$ = nextinstr();
}
;

N: %empty 
{
	 $$ = new Statement();
	 $$->nextList = makelist(nextinstr());
	 emit("goto", "");
}
;

%%

void yyerror(string str) {
	 cout << str << endl;
}
