/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    UNARY_PLUS = 258,              /* UNARY_PLUS  */
    UNARY_MINUS = 259,             /* UNARY_MINUS  */
    IDENTIFIER = 260,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 261,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 262,          /* FLOAT_CONSTANT  */
    CHARACTER_CONSTANT = 263,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 264,          /* STRING_LITERAL  */
    RETURN = 265,                  /* RETURN  */
    VOID = 266,                    /* VOID  */
    FLOAT = 267,                   /* FLOAT  */
    INTEGER = 268,                 /* INTEGER  */
    CHAR = 269,                    /* CHAR  */
    FOR = 270,                     /* FOR  */
    CONST = 271,                   /* CONST  */
    WHILE = 272,                   /* WHILE  */
    DO = 273,                      /* DO  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    BOOL = 276,                    /* BOOL  */
    BLOCK_BEGIN = 277,             /* BLOCK_BEGIN  */
    BLOCK_END = 278,               /* BLOCK_END  */
    LEFT_SQUARE_BRACKET = 279,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 280,    /* RIGHT_SQUARE_BRACKET  */
    LEFT_PARENTHESIS = 281,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 282,       /* RIGHT_PARENTHESIS  */
    ARROW = 283,                   /* ARROW  */
    INCREMENT = 284,               /* INCREMENT  */
    DECREMENT = 285,               /* DECREMENT  */
    LEFT_SHIFT = 286,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 287,             /* RIGHT_SHIFT  */
    LESS_THAN_EQUAL = 288,         /* LESS_THAN_EQUAL  */
    GREATER_THAN_EQUAL = 289,      /* GREATER_THAN_EQUAL  */
    LESS_THAN = 290,               /* LESS_THAN  */
    GREATER_THAN = 291,            /* GREATER_THAN  */
    EQUAL = 292,                   /* EQUAL  */
    NOT_EQUAL = 293,               /* NOT_EQUAL  */
    LOGICAL_AND = 294,             /* LOGICAL_AND  */
    LOGICAL_OR = 295,              /* LOGICAL_OR  */
    NOT = 296,                     /* NOT  */
    BITWISE_XOR = 297,             /* BITWISE_XOR  */
    BITWISE_OR = 298,              /* BITWISE_OR  */
    QUESTION_MARK = 299,           /* QUESTION_MARK  */
    COLON = 300,                   /* COLON  */
    SEMICOLON = 301,               /* SEMICOLON  */
    ADDRESS = 302,                 /* ADDRESS  */
    ASSIGN = 303,                  /* ASSIGN  */
    COMMA = 304,                   /* COMMA  */
    ADD = 305,                     /* ADD  */
    SUBTRACT = 306,                /* SUBTRACT  */
    MULTIPLY = 307,                /* MULTIPLY  */
    DIVIDE = 308,                  /* DIVIDE  */
    MODULO = 309                   /* MODULO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define UNARY_PLUS 258
#define UNARY_MINUS 259
#define IDENTIFIER 260
#define INTEGER_CONSTANT 261
#define FLOAT_CONSTANT 262
#define CHARACTER_CONSTANT 263
#define STRING_LITERAL 264
#define RETURN 265
#define VOID 266
#define FLOAT 267
#define INTEGER 268
#define CHAR 269
#define FOR 270
#define CONST 271
#define WHILE 272
#define DO 273
#define IF 274
#define ELSE 275
#define BOOL 276
#define BLOCK_BEGIN 277
#define BLOCK_END 278
#define LEFT_SQUARE_BRACKET 279
#define RIGHT_SQUARE_BRACKET 280
#define LEFT_PARENTHESIS 281
#define RIGHT_PARENTHESIS 282
#define ARROW 283
#define INCREMENT 284
#define DECREMENT 285
#define LEFT_SHIFT 286
#define RIGHT_SHIFT 287
#define LESS_THAN_EQUAL 288
#define GREATER_THAN_EQUAL 289
#define LESS_THAN 290
#define GREATER_THAN 291
#define EQUAL 292
#define NOT_EQUAL 293
#define LOGICAL_AND 294
#define LOGICAL_OR 295
#define NOT 296
#define BITWISE_XOR 297
#define BITWISE_OR 298
#define QUESTION_MARK 299
#define COLON 300
#define SEMICOLON 301
#define ADDRESS 302
#define ASSIGN 303
#define COMMA 304
#define ADD 305
#define SUBTRACT 306
#define MULTIPLY 307
#define DIVIDE 308
#define MODULO 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "a7_220101050.y"

    char* str;
    int num;

#line 180 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
