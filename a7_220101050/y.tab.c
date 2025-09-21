/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "a7_220101050.y"

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

#line 87 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 253 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '='  */
  YYSYMBOL_4_ = 4,                         /* '?'  */
  YYSYMBOL_5_ = 5,                         /* ':'  */
  YYSYMBOL_6_ = 6,                         /* '&'  */
  YYSYMBOL_UNARY_PLUS = 7,                 /* UNARY_PLUS  */
  YYSYMBOL_UNARY_MINUS = 8,                /* UNARY_MINUS  */
  YYSYMBOL_IDENTIFIER = 9,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 10,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 11,            /* FLOAT_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 12,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 13,            /* STRING_LITERAL  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_INTEGER = 17,                   /* INTEGER  */
  YYSYMBOL_CHAR = 18,                      /* CHAR  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_CONST = 20,                     /* CONST  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_BOOL = 25,                      /* BOOL  */
  YYSYMBOL_BLOCK_BEGIN = 26,               /* BLOCK_BEGIN  */
  YYSYMBOL_BLOCK_END = 27,                 /* BLOCK_END  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 28,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 29,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_LEFT_PARENTHESIS = 30,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 31,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_ARROW = 32,                     /* ARROW  */
  YYSYMBOL_INCREMENT = 33,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 34,                 /* DECREMENT  */
  YYSYMBOL_LEFT_SHIFT = 35,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 36,               /* RIGHT_SHIFT  */
  YYSYMBOL_LESS_THAN_EQUAL = 37,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 38,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_LESS_THAN = 39,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 40,              /* GREATER_THAN  */
  YYSYMBOL_EQUAL = 41,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 42,                 /* NOT_EQUAL  */
  YYSYMBOL_LOGICAL_AND = 43,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 44,                /* LOGICAL_OR  */
  YYSYMBOL_NOT = 45,                       /* NOT  */
  YYSYMBOL_BITWISE_XOR = 46,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_OR = 47,                /* BITWISE_OR  */
  YYSYMBOL_QUESTION_MARK = 48,             /* QUESTION_MARK  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 50,                 /* SEMICOLON  */
  YYSYMBOL_ADDRESS = 51,                   /* ADDRESS  */
  YYSYMBOL_ASSIGN = 52,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 53,                     /* COMMA  */
  YYSYMBOL_ADD = 54,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 55,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 56,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 57,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 58,                    /* MODULO  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_identifier = 60,                /* identifier  */
  YYSYMBOL_translation_unit = 61,          /* translation_unit  */
  YYSYMBOL_external_declaration = 62,      /* external_declaration  */
  YYSYMBOL_function_definition = 63,       /* function_definition  */
  YYSYMBOL_declaration = 64,               /* declaration  */
  YYSYMBOL_init_declarator = 65,           /* init_declarator  */
  YYSYMBOL_initializer = 66,               /* initializer  */
  YYSYMBOL_type_specifier = 67,            /* type_specifier  */
  YYSYMBOL_declarator = 68,                /* declarator  */
  YYSYMBOL_pointer_opt = 69,               /* pointer_opt  */
  YYSYMBOL_direct_declarator = 70,         /* direct_declarator  */
  YYSYMBOL_parameter_list_opt = 71,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 72,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 73,     /* parameter_declaration  */
  YYSYMBOL_compound_statement = 74,        /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 75,       /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 76,           /* block_item_list  */
  YYSYMBOL_block_item = 77,                /* block_item  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_expression_statement = 79,      /* expression_statement  */
  YYSYMBOL_selection_statement = 80,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 81,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 82,            /* jump_statement  */
  YYSYMBOL_expression_opt = 83,            /* expression_opt  */
  YYSYMBOL_expression = 84,                /* expression  */
  YYSYMBOL_assignment_expression = 85,     /* assignment_expression  */
  YYSYMBOL_conditional_expression = 86,    /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 87,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 88,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 89,       /* equality_expression  */
  YYSYMBOL_relational_expression = 90,     /* relational_expression  */
  YYSYMBOL_additive_expression = 91,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 92, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 93,          /* unary_expression  */
  YYSYMBOL_unary_operator = 94,            /* unary_operator  */
  YYSYMBOL_postfix_expression = 95,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 96,        /* primary_expression  */
  YYSYMBOL_argument_expression_list_opt = 97, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 98   /* argument_expression_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     6,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     5,     2,
       2,     3,     2,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    68,    70,    75,    77,    82,    87,    92,
      94,    99,   104,   106,   108,   110,   112,   117,   123,   124,
     129,   131,   133,   139,   140,   145,   147,   152,   154,   159,
     165,   166,   171,   173,   178,   180,   185,   187,   189,   191,
     193,   198,   203,   205,   210,   215,   221,   222,   227,   232,
     234,   239,   241,   246,   248,   253,   255,   260,   262,   264,
     269,   271,   273,   275,   277,   282,   284,   286,   291,   293,
     295,   297,   302,   304,   309,   311,   313,   315,   317,   322,
     324,   326,   328,   333,   335,   337,   339,   341,   343,   349,
     350,   355,   357
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'='", "'?'", "':'",
  "'&'", "UNARY_PLUS", "UNARY_MINUS", "IDENTIFIER", "INTEGER_CONSTANT",
  "FLOAT_CONSTANT", "CHARACTER_CONSTANT", "STRING_LITERAL", "RETURN",
  "VOID", "FLOAT", "INTEGER", "CHAR", "FOR", "CONST", "WHILE", "DO", "IF",
  "ELSE", "BOOL", "BLOCK_BEGIN", "BLOCK_END", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "ARROW",
  "INCREMENT", "DECREMENT", "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_THAN_EQUAL",
  "GREATER_THAN_EQUAL", "LESS_THAN", "GREATER_THAN", "EQUAL", "NOT_EQUAL",
  "LOGICAL_AND", "LOGICAL_OR", "NOT", "BITWISE_XOR", "BITWISE_OR",
  "QUESTION_MARK", "COLON", "SEMICOLON", "ADDRESS", "ASSIGN", "COMMA",
  "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "MODULO", "$accept",
  "identifier", "translation_unit", "external_declaration",
  "function_definition", "declaration", "init_declarator", "initializer",
  "type_specifier", "declarator", "pointer_opt", "direct_declarator",
  "parameter_list_opt", "parameter_list", "parameter_declaration",
  "compound_statement", "block_item_list_opt", "block_item_list",
  "block_item", "statement", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "expression_opt", "expression",
  "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "unary_operator",
  "postfix_expression", "primary_expression",
  "argument_expression_list_opt", "argument_expression_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      40,  -125,  -125,  -125,  -125,  -125,    46,  -125,  -125,  -125,
     -52,  -125,  -125,  -125,   -37,   -10,    72,  -125,    74,    -2,
    -125,  -125,    47,  -125,  -125,  -125,  -125,  -125,    -2,   -11,
      66,    -2,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   -52,
    -125,   -12,    74,  -125,  -125,  -125,  -125,  -125,  -125,    48,
    -125,  -125,  -125,   -30,    59,     6,   -15,     5,    11,    51,
      -2,    44,  -125,  -125,  -125,    99,    40,    60,    -2,    -2,
      84,    64,  -125,  -125,  -125,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
    -125,    -2,    -2,    72,    88,   -52,    87,    67,  -125,  -125,
      71,    91,  -125,    59,  -125,    77,     6,   -15,   -15,     5,
       5,     5,     5,    11,    11,  -125,  -125,  -125,  -125,    94,
    -125,    96,    85,  -125,  -125,    72,  -125,    40,    -2,   122,
      -2,  -125,  -125,    -2,  -125,  -125,    89,   113,  -125,  -125,
      -2,   122,   109,  -125,   122,  -125
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    14,    15,    13,    16,     0,     3,     5,     6,
      18,     1,     4,    19,     0,     9,     0,     8,    30,     0,
       7,     2,    20,    17,    84,    85,    86,    87,    46,     0,
       0,     0,    76,    77,    74,    75,    78,    83,    34,    18,
      36,     0,    31,    32,    35,    37,    38,    39,    40,     0,
      47,    48,    49,    51,    53,    55,    57,    60,    65,    68,
       0,    72,    79,    10,    11,     0,    23,     0,    46,     0,
       0,     9,    29,    33,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,    89,     0,     0,    18,     0,    24,    25,    45,
       0,     0,    88,    54,    68,     0,    56,    58,    59,    63,
      64,    61,    62,    66,    67,    69,    70,    71,    50,     0,
      91,     0,    90,    82,    21,    28,    22,     0,    46,    46,
       0,    80,    81,     0,    27,    26,     0,    42,    52,    92,
      46,    46,     0,    43,    46,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,   -13,  -125,   136,  -125,     3,  -125,  -125,   -16,   104,
      49,  -125,  -125,  -125,    19,   132,  -125,  -125,   107,  -124,
    -125,  -125,  -125,  -125,   -27,   -25,   -19,    20,  -125,    76,
      78,     0,    25,    10,   -48,  -125,  -125,  -125,  -125,  -125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    37,     6,     7,     8,     9,    14,    63,    10,    15,
      16,    23,    96,    97,    98,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   121,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    67,    39,    22,    13,   137,    70,    21,    24,    25,
      26,    27,    90,    17,    75,    72,    18,   143,    76,    68,
     145,    38,    80,    81,    82,    83,    39,   104,    31,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   115,   116,
     117,   100,    19,    32,   101,    38,    11,    78,    79,    33,
      95,   105,    34,    35,    36,     1,     2,     3,     4,    84,
      85,     1,     2,     3,     4,     5,   119,    86,    87,    88,
     118,     5,    91,   120,    92,    65,    93,    66,   107,   108,
     123,    21,   104,    21,    24,    25,    26,    27,    28,     1,
       2,     3,     4,    29,   113,   114,    69,    30,    74,     5,
      18,   136,    77,    89,    31,   109,   110,   111,   112,    94,
      99,    95,   134,   142,   139,   102,    19,   124,   126,    32,
     127,   128,   129,   131,   -46,    33,   130,   132,    34,    35,
      36,    21,    24,    25,    26,    27,    28,   141,   133,   140,
     144,    29,    12,    71,   125,    30,   135,    20,    18,    73,
     138,   103,    31,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,    33,     0,     0,    34,    35,    36
};

static const yytype_int16 yycheck[] =
{
      19,    28,    18,    16,    56,   129,    31,     9,    10,    11,
      12,    13,    60,    50,    44,    27,    26,   141,    48,    30,
     144,    18,    37,    38,    39,    40,    42,    75,    30,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    68,    52,    45,    69,    42,     0,    41,    42,    51,
      66,    76,    54,    55,    56,    15,    16,    17,    18,    54,
      55,    15,    16,    17,    18,    25,    91,    56,    57,    58,
      89,    25,    28,    92,    30,    28,    32,    30,    78,    79,
      93,     9,   130,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    84,    85,    30,    23,    50,    25,
      26,   128,    43,    52,    30,    80,    81,    82,    83,    10,
      50,   127,   125,   140,   133,    31,    52,    29,    31,    45,
      53,    50,    31,    29,    50,    51,    49,    31,    54,    55,
      56,     9,    10,    11,    12,    13,    14,    24,    53,    50,
      31,    19,     6,    39,    95,    23,   127,    15,    26,    42,
     130,    75,    30,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    17,    18,    25,    61,    62,    63,    64,
      67,     0,    62,    56,    65,    68,    69,    50,    26,    52,
      74,     9,    60,    70,    10,    11,    12,    13,    14,    19,
      23,    30,    45,    51,    54,    55,    56,    60,    64,    67,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    66,    85,    28,    30,    83,    30,    30,
      84,    68,    27,    77,    50,    44,    48,    43,    41,    42,
      37,    38,    39,    40,    54,    55,    56,    57,    58,    52,
      93,    28,    30,    32,    10,    67,    71,    72,    73,    50,
      83,    84,    31,    88,    93,    84,    89,    90,    90,    91,
      91,    91,    91,    92,    92,    93,    93,    93,    85,    84,
      85,    97,    98,    60,    29,    69,    31,    53,    50,    31,
      49,    29,    31,    53,    60,    73,    83,    78,    86,    85,
      50,    24,    83,    78,    31,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    63,    64,    65,
      65,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    79,    80,    80,    81,    82,    83,    83,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      90,    90,    90,    90,    90,    91,    91,    91,    92,    92,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     4,     4,     0,     1,     1,     3,     3,     2,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     7,     9,     3,     0,     1,     1,     1,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* identifier: IDENTIFIER  */
#line 64 "a7_220101050.y"
        { (yyval.str) = (yyvsp[0].str); printf("Reduced: identifier -> IDENTIFIER (%s)\n", (yyvsp[0].str)); }
#line 1452 "y.tab.c"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 69 "a7_220101050.y"
        { printf("Reduced: translation_unit -> external_declaration\n"); }
#line 1458 "y.tab.c"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 71 "a7_220101050.y"
        { printf("Reduced: translation_unit -> translation_unit external_declaration\n"); }
#line 1464 "y.tab.c"
    break;

  case 5: /* external_declaration: function_definition  */
#line 76 "a7_220101050.y"
        { printf("Reduced: external_declaration -> function_definition\n"); }
#line 1470 "y.tab.c"
    break;

  case 6: /* external_declaration: declaration  */
#line 78 "a7_220101050.y"
        { printf("Reduced: external_declaration -> declaration\n"); }
#line 1476 "y.tab.c"
    break;

  case 7: /* function_definition: type_specifier declarator compound_statement  */
#line 83 "a7_220101050.y"
        { printf("Reduced: function_definition -> type_specifier declarator compound_statement\n"); }
#line 1482 "y.tab.c"
    break;

  case 8: /* declaration: type_specifier init_declarator SEMICOLON  */
#line 88 "a7_220101050.y"
        { printf("Reduced: declaration -> type_specifier init_declarator SEMICOLON\n"); }
#line 1488 "y.tab.c"
    break;

  case 9: /* init_declarator: declarator  */
#line 93 "a7_220101050.y"
        { printf("Reduced: init_declarator -> declarator\n"); }
#line 1494 "y.tab.c"
    break;

  case 10: /* init_declarator: declarator ASSIGN initializer  */
#line 95 "a7_220101050.y"
        { printf("Reduced: init_declarator -> declarator ASSIGN initializer\n"); }
#line 1500 "y.tab.c"
    break;

  case 11: /* initializer: assignment_expression  */
#line 100 "a7_220101050.y"
        { printf("Reduced: initializer -> assignment_expression\n"); }
#line 1506 "y.tab.c"
    break;

  case 12: /* type_specifier: VOID  */
#line 105 "a7_220101050.y"
        { printf("Reduced: type_specifier -> VOID\n"); (yyval.str) = "void"; }
#line 1512 "y.tab.c"
    break;

  case 13: /* type_specifier: CHAR  */
#line 107 "a7_220101050.y"
        { printf("Reduced: type_specifier -> CHAR\n"); (yyval.str) = "char"; }
#line 1518 "y.tab.c"
    break;

  case 14: /* type_specifier: FLOAT  */
#line 109 "a7_220101050.y"
        { printf("Reduced: type_specifier -> FLOAT\n"); (yyval.str) = "float"; }
#line 1524 "y.tab.c"
    break;

  case 15: /* type_specifier: INTEGER  */
#line 111 "a7_220101050.y"
        { printf("Reduced: type_specifier -> INTEGER\n"); (yyval.str) = "integer"; }
#line 1530 "y.tab.c"
    break;

  case 16: /* type_specifier: BOOL  */
#line 113 "a7_220101050.y"
        { printf("Reduced: type_specifier -> BOOL\n"); (yyval.str) = "bool"; }
#line 1536 "y.tab.c"
    break;

  case 17: /* declarator: pointer_opt direct_declarator  */
#line 118 "a7_220101050.y"
        { printf("Reduced: declarator -> pointer_opt direct_declarator\n"); (yyval.str) = (yyvsp[0].str); }
#line 1542 "y.tab.c"
    break;

  case 18: /* pointer_opt: %empty  */
#line 123 "a7_220101050.y"
        { printf("Reduced: pointer_opt -> epsilon\n"); (yyval.str) = ""; }
#line 1548 "y.tab.c"
    break;

  case 19: /* pointer_opt: MULTIPLY  */
#line 125 "a7_220101050.y"
        { printf("Reduced: pointer_opt -> '*'\n"); (yyval.str) = "*"; }
#line 1554 "y.tab.c"
    break;

  case 20: /* direct_declarator: identifier  */
#line 130 "a7_220101050.y"
        { printf("Reduced: direct_declarator -> identifier (%s)\n", (yyvsp[0].str)); (yyval.str) = (yyvsp[0].str); }
#line 1560 "y.tab.c"
    break;

  case 21: /* direct_declarator: identifier LEFT_SQUARE_BRACKET INTEGER_CONSTANT RIGHT_SQUARE_BRACKET  */
#line 132 "a7_220101050.y"
        { printf("Reduced: direct_declarator -> identifier [ INTEGER_CONSTANT ]\n"); (yyval.str) = (yyvsp[-3].str); }
#line 1566 "y.tab.c"
    break;

  case 22: /* direct_declarator: identifier LEFT_PARENTHESIS parameter_list_opt RIGHT_PARENTHESIS  */
#line 134 "a7_220101050.y"
        { printf("Reduced: direct_declarator -> identifier ( parameter_list_opt )\n"); (yyval.str) = (yyvsp[-3].str); }
#line 1572 "y.tab.c"
    break;

  case 23: /* parameter_list_opt: %empty  */
#line 139 "a7_220101050.y"
        { printf("Reduced: parameter_list_opt -> epsilon\n"); }
#line 1578 "y.tab.c"
    break;

  case 24: /* parameter_list_opt: parameter_list  */
#line 141 "a7_220101050.y"
        { printf("Reduced: parameter_list_opt -> parameter_list\n"); }
#line 1584 "y.tab.c"
    break;

  case 25: /* parameter_list: parameter_declaration  */
#line 146 "a7_220101050.y"
        { printf("Reduced: parameter_list -> parameter_declaration\n"); }
#line 1590 "y.tab.c"
    break;

  case 26: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 148 "a7_220101050.y"
        { printf("Reduced: parameter_list -> parameter_list , parameter_declaration\n"); }
#line 1596 "y.tab.c"
    break;

  case 27: /* parameter_declaration: type_specifier pointer_opt identifier  */
#line 153 "a7_220101050.y"
        { printf("Reduced: parameter_declaration -> type_specifier pointer_opt identifier\n"); (yyval.str) = (yyvsp[0].str); }
#line 1602 "y.tab.c"
    break;

  case 28: /* parameter_declaration: type_specifier pointer_opt  */
#line 155 "a7_220101050.y"
        { printf("Reduced: parameter_declaration -> type_specifier pointer_opt\n"); (yyval.str) = ""; }
#line 1608 "y.tab.c"
    break;

  case 29: /* compound_statement: BLOCK_BEGIN block_item_list_opt BLOCK_END  */
#line 160 "a7_220101050.y"
        { printf("Reduced: compound_statement -> BLOCK_BEGIN block_item_list_opt BLOCK_END\n"); }
#line 1614 "y.tab.c"
    break;

  case 30: /* block_item_list_opt: %empty  */
#line 165 "a7_220101050.y"
        { printf("Reduced: block_item_list_opt -> epsilon\n"); }
#line 1620 "y.tab.c"
    break;

  case 31: /* block_item_list_opt: block_item_list  */
#line 167 "a7_220101050.y"
        { printf("Reduced: block_item_list -> block_item_list\n"); }
#line 1626 "y.tab.c"
    break;

  case 32: /* block_item_list: block_item  */
#line 172 "a7_220101050.y"
        { printf("Reduced: block_item_list -> block_item\n"); }
#line 1632 "y.tab.c"
    break;

  case 33: /* block_item_list: block_item_list block_item  */
#line 174 "a7_220101050.y"
        { printf("Reduced: block_item_list -> block_item_list block_item\n"); }
#line 1638 "y.tab.c"
    break;

  case 34: /* block_item: declaration  */
#line 179 "a7_220101050.y"
        { printf("Reduced: block_item -> declaration\n"); }
#line 1644 "y.tab.c"
    break;

  case 35: /* block_item: statement  */
#line 181 "a7_220101050.y"
        { printf("Reduced: block_item -> statement\n"); }
#line 1650 "y.tab.c"
    break;

  case 36: /* statement: compound_statement  */
#line 186 "a7_220101050.y"
        { printf("Reduced: statement -> compound_statement\n"); }
#line 1656 "y.tab.c"
    break;

  case 37: /* statement: expression_statement  */
#line 188 "a7_220101050.y"
        { printf("Reduced: statement -> expression_statement\n"); }
#line 1662 "y.tab.c"
    break;

  case 38: /* statement: selection_statement  */
#line 190 "a7_220101050.y"
        { printf("Reduced: statement -> selection_statement\n"); }
#line 1668 "y.tab.c"
    break;

  case 39: /* statement: iteration_statement  */
#line 192 "a7_220101050.y"
        { printf("Reduced: statement -> iteration_statement\n"); }
#line 1674 "y.tab.c"
    break;

  case 40: /* statement: jump_statement  */
#line 194 "a7_220101050.y"
        { printf("Reduced: statement -> jump_statement\n"); }
#line 1680 "y.tab.c"
    break;

  case 41: /* expression_statement: expression_opt SEMICOLON  */
#line 199 "a7_220101050.y"
        { printf("Reduced: expression_statement -> expression_opt SEMICOLON\n"); }
#line 1686 "y.tab.c"
    break;

  case 42: /* selection_statement: IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement  */
#line 204 "a7_220101050.y"
        { printf("Reduced: selection_statement -> IF ( expression ) statement\n"); }
#line 1692 "y.tab.c"
    break;

  case 43: /* selection_statement: IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS statement ELSE statement  */
#line 206 "a7_220101050.y"
        { printf("Reduced: selection_statement -> IF ( expression ) statement ELSE statement\n"); }
#line 1698 "y.tab.c"
    break;

  case 44: /* iteration_statement: FOR LEFT_PARENTHESIS expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RIGHT_PARENTHESIS statement  */
#line 211 "a7_220101050.y"
        { printf("Reduced: iteration_statement -> FOR ( expression_opt ; expression_opt ; expression_opt ) statement\n"); }
#line 1704 "y.tab.c"
    break;

  case 45: /* jump_statement: RETURN expression_opt SEMICOLON  */
#line 216 "a7_220101050.y"
        { printf("Reduced: jump_statement -> RETURN expression_opt SEMICOLON\n"); }
#line 1710 "y.tab.c"
    break;

  case 46: /* expression_opt: %empty  */
#line 221 "a7_220101050.y"
        { printf("Reduced: expression_opt -> epsilon\n"); }
#line 1716 "y.tab.c"
    break;

  case 47: /* expression_opt: expression  */
#line 223 "a7_220101050.y"
        { printf("Reduced: expression_opt -> expression\n"); }
#line 1722 "y.tab.c"
    break;

  case 48: /* expression: assignment_expression  */
#line 228 "a7_220101050.y"
        { printf("Reduced: expression -> assignment_expression\n"); }
#line 1728 "y.tab.c"
    break;

  case 49: /* assignment_expression: conditional_expression  */
#line 233 "a7_220101050.y"
        { printf("Reduced: assignment_expression -> conditional_expression\n"); }
#line 1734 "y.tab.c"
    break;

  case 50: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 235 "a7_220101050.y"
        { printf("Reduced: assignment_expression -> unary_expression ASSIGN assignment_expression\n"); }
#line 1740 "y.tab.c"
    break;

  case 51: /* conditional_expression: logical_or_expression  */
#line 240 "a7_220101050.y"
        { printf("Reduced: conditional_expression -> logical_or_expression\n"); }
#line 1746 "y.tab.c"
    break;

  case 52: /* conditional_expression: logical_or_expression QUESTION_MARK expression COLON conditional_expression  */
#line 242 "a7_220101050.y"
        { printf("Reduced: conditional_expression -> logical_or_expression ? expression : conditional_expression\n"); }
#line 1752 "y.tab.c"
    break;

  case 53: /* logical_or_expression: logical_and_expression  */
#line 247 "a7_220101050.y"
        { printf("Reduced: logical_or_expression -> logical_and_expression\n"); }
#line 1758 "y.tab.c"
    break;

  case 54: /* logical_or_expression: logical_or_expression LOGICAL_OR logical_and_expression  */
#line 249 "a7_220101050.y"
        { printf("Reduced: logical_or_expression -> logical_or_expression || logical_and_expression\n"); }
#line 1764 "y.tab.c"
    break;

  case 55: /* logical_and_expression: equality_expression  */
#line 254 "a7_220101050.y"
        { printf("Reduced: logical_and_expression -> equality_expression\n"); }
#line 1770 "y.tab.c"
    break;

  case 56: /* logical_and_expression: logical_and_expression LOGICAL_AND equality_expression  */
#line 256 "a7_220101050.y"
        { printf("Reduced: logical_and_expression -> logical_and_expression && equality_expression\n"); }
#line 1776 "y.tab.c"
    break;

  case 57: /* equality_expression: relational_expression  */
#line 261 "a7_220101050.y"
        { printf("Reduced: equality_expression -> relational_expression\n"); }
#line 1782 "y.tab.c"
    break;

  case 58: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 263 "a7_220101050.y"
        { printf("Reduced: equality_expression -> equality_expression == relational_expression\n"); }
#line 1788 "y.tab.c"
    break;

  case 59: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 265 "a7_220101050.y"
        { printf("Reduced: equality_expression -> equality_expression != relational_expression\n"); }
#line 1794 "y.tab.c"
    break;

  case 60: /* relational_expression: additive_expression  */
#line 270 "a7_220101050.y"
        { printf("Reduced: relational_expression -> additive_expression\n"); }
#line 1800 "y.tab.c"
    break;

  case 61: /* relational_expression: relational_expression LESS_THAN additive_expression  */
#line 272 "a7_220101050.y"
        { printf("Reduced: relational_expression -> relational_expression < additive_expression\n"); }
#line 1806 "y.tab.c"
    break;

  case 62: /* relational_expression: relational_expression GREATER_THAN additive_expression  */
#line 274 "a7_220101050.y"
        { printf("Reduced: relational_expression -> relational_expression > additive_expression\n"); }
#line 1812 "y.tab.c"
    break;

  case 63: /* relational_expression: relational_expression LESS_THAN_EQUAL additive_expression  */
#line 276 "a7_220101050.y"
        { printf("Reduced: relational_expression -> relational_expression <= additive_expression\n"); }
#line 1818 "y.tab.c"
    break;

  case 64: /* relational_expression: relational_expression GREATER_THAN_EQUAL additive_expression  */
#line 278 "a7_220101050.y"
        { printf("Reduced: relational_expression -> relational_expression >= additive_expression\n"); }
#line 1824 "y.tab.c"
    break;

  case 65: /* additive_expression: multiplicative_expression  */
#line 283 "a7_220101050.y"
        { printf("Reduced: additive_expression -> multiplicative_expression\n"); }
#line 1830 "y.tab.c"
    break;

  case 66: /* additive_expression: additive_expression ADD multiplicative_expression  */
#line 285 "a7_220101050.y"
        { printf("Reduced: additive_expression -> additive_expression + multiplicative_expression\n"); }
#line 1836 "y.tab.c"
    break;

  case 67: /* additive_expression: additive_expression SUBTRACT multiplicative_expression  */
#line 287 "a7_220101050.y"
        { printf("Reduced: additive_expression -> additive_expression - multiplicative_expression\n"); }
#line 1842 "y.tab.c"
    break;

  case 68: /* multiplicative_expression: unary_expression  */
#line 292 "a7_220101050.y"
        { printf("Reduced: multiplicative_expression -> unary_expression\n"); }
#line 1848 "y.tab.c"
    break;

  case 69: /* multiplicative_expression: multiplicative_expression MULTIPLY unary_expression  */
#line 294 "a7_220101050.y"
        { printf("Reduced: multiplicative_expression -> multiplicative_expression * unary_expression\n"); }
#line 1854 "y.tab.c"
    break;

  case 70: /* multiplicative_expression: multiplicative_expression DIVIDE unary_expression  */
#line 296 "a7_220101050.y"
        { printf("Reduced: multiplicative_expression -> multiplicative_expression / unary_expression\n"); }
#line 1860 "y.tab.c"
    break;

  case 71: /* multiplicative_expression: multiplicative_expression MODULO unary_expression  */
#line 298 "a7_220101050.y"
        { printf("Reduced: multiplicative_expression -> multiplicative_expression % unary_expression\n"); }
#line 1866 "y.tab.c"
    break;

  case 72: /* unary_expression: postfix_expression  */
#line 303 "a7_220101050.y"
        { printf("Reduced: unary_expression -> postfix_expression\n"); }
#line 1872 "y.tab.c"
    break;

  case 73: /* unary_expression: unary_operator unary_expression  */
#line 305 "a7_220101050.y"
        { printf("Reduced: unary_expression -> unary_operator unary_expression\n"); }
#line 1878 "y.tab.c"
    break;

  case 74: /* unary_operator: ADD  */
#line 310 "a7_220101050.y"
        { printf("Reduced: unary_operator -> +\n"); }
#line 1884 "y.tab.c"
    break;

  case 75: /* unary_operator: SUBTRACT  */
#line 312 "a7_220101050.y"
        { printf("Reduced: unary_operator -> -\n"); }
#line 1890 "y.tab.c"
    break;

  case 76: /* unary_operator: NOT  */
#line 314 "a7_220101050.y"
        { printf("Reduced: unary_operator -> !\n"); }
#line 1896 "y.tab.c"
    break;

  case 77: /* unary_operator: ADDRESS  */
#line 316 "a7_220101050.y"
        { printf("Reduced: unary_operator -> &\n"); }
#line 1902 "y.tab.c"
    break;

  case 78: /* unary_operator: MULTIPLY  */
#line 318 "a7_220101050.y"
        { printf("Reduced: unary_operator -> *\n"); }
#line 1908 "y.tab.c"
    break;

  case 79: /* postfix_expression: primary_expression  */
#line 323 "a7_220101050.y"
        { printf("Reduced: postfix_expression -> primary_expression\n"); }
#line 1914 "y.tab.c"
    break;

  case 80: /* postfix_expression: postfix_expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET  */
#line 325 "a7_220101050.y"
        { printf("Reduced: postfix_expression -> postfix_expression [ expression ]\n"); }
#line 1920 "y.tab.c"
    break;

  case 81: /* postfix_expression: postfix_expression LEFT_PARENTHESIS argument_expression_list_opt RIGHT_PARENTHESIS  */
#line 327 "a7_220101050.y"
        { printf("Reduced: postfix_expression -> postfix_expression ( argument_expression_list_opt )\n"); }
#line 1926 "y.tab.c"
    break;

  case 82: /* postfix_expression: postfix_expression ARROW identifier  */
#line 329 "a7_220101050.y"
        { printf("Reduced: postfix_expression -> postfix_expression -> identifier\n"); }
#line 1932 "y.tab.c"
    break;

  case 83: /* primary_expression: identifier  */
#line 334 "a7_220101050.y"
        { printf("Reduced: primary_expression -> identifier (%s)\n", (yyvsp[0].str)); }
#line 1938 "y.tab.c"
    break;

  case 84: /* primary_expression: INTEGER_CONSTANT  */
#line 336 "a7_220101050.y"
        { printf("Reduced: primary_expression -> INTEGER_CONSTANT\n"); }
#line 1944 "y.tab.c"
    break;

  case 85: /* primary_expression: FLOAT_CONSTANT  */
#line 338 "a7_220101050.y"
        { printf("Reduced: primary_expression -> FLOAT_CONSTANT\n"); }
#line 1950 "y.tab.c"
    break;

  case 86: /* primary_expression: CHARACTER_CONSTANT  */
#line 340 "a7_220101050.y"
        { printf("Reduced: primary_expression -> CHARACTER_CONSTANT\n"); }
#line 1956 "y.tab.c"
    break;

  case 87: /* primary_expression: STRING_LITERAL  */
#line 342 "a7_220101050.y"
        { printf("Reduced: primary_expression -> STRING_LITERAL\n"); }
#line 1962 "y.tab.c"
    break;

  case 88: /* primary_expression: LEFT_PARENTHESIS expression RIGHT_PARENTHESIS  */
#line 344 "a7_220101050.y"
        { printf("Reduced: primary_expression -> ( expression )\n"); }
#line 1968 "y.tab.c"
    break;

  case 89: /* argument_expression_list_opt: %empty  */
#line 349 "a7_220101050.y"
        { printf("Reduced: argument_expression_list_opt -> epsilon\n"); }
#line 1974 "y.tab.c"
    break;

  case 90: /* argument_expression_list_opt: argument_expression_list  */
#line 351 "a7_220101050.y"
        { printf("Reduced: argument_expression_list_opt -> argument_expression_list\n"); }
#line 1980 "y.tab.c"
    break;

  case 91: /* argument_expression_list: assignment_expression  */
#line 356 "a7_220101050.y"
        { printf("Reduced: argument_expression_list -> assignment_expression\n"); }
#line 1986 "y.tab.c"
    break;

  case 92: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 358 "a7_220101050.y"
        { printf("Reduced: argument_expression_list -> argument_expression_list , assignment_expression\n"); }
#line 1992 "y.tab.c"
    break;


#line 1996 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 361 "a7_220101050.y"


int main() {
    printf("............. Starting the parsing process .............\n\n");
    yyparse();
    printSymbolTable();
    return 0;
}
