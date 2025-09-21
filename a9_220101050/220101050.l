%{
/* Declarations and Header Inclusions */
	
	#include <stdio.h>
	#include <string.h>
	#include "translator_220101050.h"
	#include "y.tab.h"

%}

%option noyywrap

/* Regular Expression Definition Section */

/*--- LANGUAGE KEYWORDS ---*/
BREAK		"break"
CASE		"case"
CONTINUE	"continue"
CHAR		"char"
DEFAULT		"default"
CONST 		"const"
DO 			"do"
DOUBLE		"double"
EXTERN		"extern"
ELSE		"else"
FOR			"for"
FLOAT		"float"
GOTO		"goto"
IF			"if"
LONG		"long"
INLINE		"inline"	
INT 		"integer"
RESTRICT 	"restrict"
RETURN		"return"
SIZEOF		"sizeof"
SHORT		"short"
STRUCT		"struct"
STATIC		"static"
SWITCH		"switch"
TYPEDEF		"typedef"
VOLATILE	"volatile"
VOID		"void"
UNION		"union"
WHILE		"while"
BEGIN       "begin"
END         "end"

/* DIGITS AND IDENTIFIERS */
DIGIT		[0-9]+
ID 			[a-zA-Z_][a-zA-Z0-9_]*

/* CONSTANTS */
INT_CONST   0+|[1-9][0-9]*
EXPONENT	[eE][+-]?{DIGIT}
FRACTION 	({DIGIT}?\.{DIGIT})|({DIGIT}\.)
FLT_CONST   {FRACTION}{EXPONENT}?|{DIGIT}{EXPONENT}

/* CHARACTER RELATED */
ESC_SEQ 	\\a|\\b|\\f|\\n|\\t|\\r|\\v|\\\'|\\\"|\\\\|\\\?
SRC_SET		[^("\'"|"\\"|"\n")]
C_CHAR		{SRC_SET}|{ESC_SEQ}
CHAR_SEQ	{C_CHAR}+
CHAR_CONST	'{CHAR_SEQ}'

/* STRING RELATED */
STR_SET		[^("\""|"\\"|"\n")]
STR_CHAR	{ESC_SEQ}|{STR_SET}
STR_SEQ		{STR_CHAR}+
STRING		\"{STR_SEQ}?\"

/* OPERATORS AND PUNCTUATIONS */
BRACKET 	"["|"]"|"("|")"
UNARY_OP 	"++"|"--"
PUNC     	"<<="|">>="|"<<"|">>"|"<="|">="|"=="|"!="|"&&"|"||"|"<"|">"|"&"|"|"|"="|"*="|"/="|"%="|"+="|"-="|"|="|"&="|"^="|"->"|"^"|"..."|"."|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"?"|":"|","|"#"|";"

/* WHITESPACE */
WS			[ \t\n]

/* Comment handling states */
%x single_line_comment multi_line_comment

%%

"//"			{BEGIN(single_line_comment);}
<single_line_comment>[^\n]	{}
<single_line_comment>"\n"		{BEGIN(INITIAL);}
<single_line_comment><<EOF>>	{BEGIN(INITIAL);}

"/*"			{BEGIN(multi_line_comment);}
<multi_line_comment>[^*]	{}
<multi_line_comment>"*"[^/]	{}
<multi_line_comment>"*/"	{BEGIN(INITIAL);}

{BREAK}		return BREAK;
{CASE}		return CASE;
{CHAR}		return CHAR;
{CONST}		return CONST;
{CONTINUE}	return CONTINUE;
{DEFAULT}	return DEFAULT;
{DO}		return DO;
{DOUBLE}	return DOUBLE;
{ELSE}		return ELSE;
{EXTERN}	return EXTERN;
{FLOAT}		return FLOAT;
{FOR}		return FOR;
{GOTO}		return GOTO;
{IF}		return IF;
{INLINE} 	return INLINE;
{INT}		return INT;
{LONG}		return LONG;
{RESTRICT} 	return RESTRICT;
{RETURN}	return RETURN;
{SHORT}		return SHORT;
{SIZEOF}	return SIZEOF;
{STATIC}	return STATIC;
{STRUCT}	return STRUCT;
{SWITCH}	return SWITCH;
{TYPEDEF}	return TYPEDEF;
{UNION}		return UNION;
{VOID}		return VOID;
{VOLATILE} 	return VOLATILE;
{WHILE}		return WHILE;
{BEGIN}     return CURLY_BRACKET_OPEN;
{END}       return CURLY_BRACKET_CLOSE;

"{"         { /* Ignoring actual curly braces */ }
"}"         { /* Ignoring actual curly braces */ }

{ID}		{
				yylval.sym_ptr = ST->lookup(yytext);
				return IDENTIFIER;
			}

{INT_CONST}	{
				yylval.int_value = atoi(yytext);
				return INTEGER_CONSTANT;
			}

{FLT_CONST}	{
				yylval.char_value = yytext;
				return FLOAT_CONSTANT;
			}

{CHAR_CONST} {
				yylval.char_value = yytext;
				return CHARACTER_CONSTANT;
			}

{STRING}	{
				yylval.char_value = yytext;
				return STRING_LITERAL;
			}

{BRACKET}	{
			if(!strcmp(yytext,"[")) 
				return SQUARE_BRACKET_OPEN;
			else if(!strcmp(yytext,"]")) 
				return SQUARE_BRACKET_CLOSE;
			else if(!strcmp(yytext,"(")) 
				return ROUND_BRACKET_OPEN;
			else /* must be ")" */
				return ROUND_BRACKET_CLOSE;
			}

{UNARY_OP}	{
			return (!strcmp(yytext,"++")) ? UNARY_INCREMENT : UNARY_DECREMENT;
			}

{PUNC}		{
			if(!strcmp(yytext,"<<=")) return BITWISE_LEFT_ASSIGN;
			else if(!strcmp(yytext,">>=")) return BITWISE_RIGHT_ASSIGN;
			else if(!strcmp(yytext,"<<")) return BITWISE_LEFT;
			else if(!strcmp(yytext,">>")) return BITWISE_RIGHT;
			else if(!strcmp(yytext,"<=")) return LESS_EQUAL;
			else if(!strcmp(yytext,">=")) return GREATER_EQUAL;
			else if(!strcmp(yytext,"==")) return EQUAL;
			else if(!strcmp(yytext,"<")) return LESS_THAN;
			else if(!strcmp(yytext,">")) return GREATER_THAN;
			else if(!strcmp(yytext,"!=")) return NOT_EQUAL;
			else if(!strcmp(yytext,"&&")) return LOGICAL_AND;
			else if(!strcmp(yytext,"||")) return LOGICAL_OR;
			else if(!strcmp(yytext,"&")) return BITWISE_AND;
			else if(!strcmp(yytext,"|")) return BITWISE_OR;
			else if(!strcmp(yytext,"=")) return ASSIGN;
			else if(!strcmp(yytext,"*=")) return MUL_ASSIGN;
			else if(!strcmp(yytext,"/=")) return DIV_ASSIGN;
			else if(!strcmp(yytext,"%=")) return MOD_ASSIGN;
			else if(!strcmp(yytext,"+=")) return PLUS_ASSIGN;
			else if(!strcmp(yytext,"-=")) return MINUS_ASSIGN;
			else if(!strcmp(yytext,"|=")) return BITWISE_OR_ASSIGN;
			else if(!strcmp(yytext,"&=")) return BITWISE_AND_ASSIGN;
			else if(!strcmp(yytext,"^=")) return XOR_ASSIGN;
			else if(!strcmp(yytext,"->")) return IMPLIES;
			else if(!strcmp(yytext,"^")) return XOR;
			else if(!strcmp(yytext,"...")) return DOTS;
			else if(!strcmp(yytext,".")) return DOT;
			else if(!strcmp(yytext,"*")) return MUL;
			else if(!strcmp(yytext,"+")) return PLUS;
			else if(!strcmp(yytext,"-")) return MINUS;
			else if(!strcmp(yytext,"~")) return COMPLEMENT;
			else if(!strcmp(yytext,"!")) return NOT;
			else if(!strcmp(yytext,"/")) return DIV;
			else if(!strcmp(yytext,"%")) return MOD;
			else if(!strcmp(yytext,"?")) return QUES_MARK;
			else if(!strcmp(yytext,":")) return COLON;
			else if(!strcmp(yytext,",")) return COMMA;
			else if(!strcmp(yytext,"#")) return HASH;
			else if(!strcmp(yytext,";")) return SEMICOLON;
			}

{WS} 		{ /* Ignore whitespace */ }

%%
