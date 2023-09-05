/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COMMENT = 258,
     DO = 259,
     WHILE = 260,
     IF = 261,
     ELSE = 262,
     FOR = 263,
     RETURN = 264,
     BOOL = 265,
     ARROW = 266,
     STRING = 267,
     CHARPTR = 268,
     VOID = 269,
     CHAR = 270,
     INT = 271,
     INTPTR = 272,
     AND = 273,
     ADDRESS = 274,
     EQUAL = 275,
     ASSIGN = 276,
     OR = 277,
     LENGTH = 278,
     GREATEREQUAL = 279,
     GREATER = 280,
     LESSEQUAL = 281,
     LESS = 282,
     NOTEQUAL = 283,
     NOT = 284,
     DIV = 285,
     PLUS = 286,
     MINUS = 287,
     VARIABLE = 288,
     STRING_LTL = 289,
     REAL_LTL = 290,
     CHAR_LTL = 291,
     NULLL = 292,
     MAIN = 293,
     IDENTIFIER = 294,
     SEMICOLON = 295,
     COMMA = 296,
     OPAREN = 297,
     CPAREN = 298,
     OBRACKET = 299,
     CBRACKET = 300,
     OBRACE = 301,
     CBRACE = 302,
     DECIMAL_LTL = 303,
     HEX_LTL = 304,
     TRUE = 305,
     FALSE = 306,
     REAL = 307,
     REALPTR = 308,
     FUNCTION = 309,
     COLON = 310,
     ETOILE = 311
   };
#endif
/* Tokens.  */
#define COMMENT 258
#define DO 259
#define WHILE 260
#define IF 261
#define ELSE 262
#define FOR 263
#define RETURN 264
#define BOOL 265
#define ARROW 266
#define STRING 267
#define CHARPTR 268
#define VOID 269
#define CHAR 270
#define INT 271
#define INTPTR 272
#define AND 273
#define ADDRESS 274
#define EQUAL 275
#define ASSIGN 276
#define OR 277
#define LENGTH 278
#define GREATEREQUAL 279
#define GREATER 280
#define LESSEQUAL 281
#define LESS 282
#define NOTEQUAL 283
#define NOT 284
#define DIV 285
#define PLUS 286
#define MINUS 287
#define VARIABLE 288
#define STRING_LTL 289
#define REAL_LTL 290
#define CHAR_LTL 291
#define NULLL 292
#define MAIN 293
#define IDENTIFIER 294
#define SEMICOLON 295
#define COMMA 296
#define OPAREN 297
#define CPAREN 298
#define OBRACKET 299
#define CBRACKET 300
#define OBRACE 301
#define CBRACE 302
#define DECIMAL_LTL 303
#define HEX_LTL 304
#define TRUE 305
#define FALSE 306
#define REAL 307
#define REALPTR 308
#define FUNCTION 309
#define COLON 310
#define ETOILE 311




/* Copy the first part of user declarations.  */
#line 1 "partie1.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;
	node* mknode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTabs(int n);
	int yylex();
	int yyerror(char *e);
	
	int printlevel=0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "partie1.y"
{
	int i;
    struct node *node;
    char *string;
}
/* Line 193 of yacc.c.  */
#line 234 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 247 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   710

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  240

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    13,    22,    23,    26,
      27,    40,    51,    53,    54,    59,    66,    71,    74,    75,
      82,    89,    94,   104,   105,   111,   115,   119,   121,   123,
     128,   130,   132,   134,   136,   138,   140,   142,   144,   146,
     148,   150,   152,   154,   156,   160,   161,   163,   167,   175,
     180,   181,   187,   195,   202,   213,   219,   223,   227,   229,
     233,   238,   240,   242,   246,   250,   254,   258,   262,   266,
     270,   274,   278,   282,   286,   290,   294,   297,   299,   301,
     304,   306,   308,   310,   312,   314,   316,   318,   322,   327,
     329,   331,   334,   336,   339,   344,   350,   358,   361,   366,
     372,   376,   378,   379,   383
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    60,    59,    -1,    62,    61,    -1,     3,
      60,    -1,    -1,    54,    38,    42,    64,    43,    46,    66,
      47,    -1,    -1,    62,    63,    -1,    -1,    54,    39,    42,
      64,    43,    55,    72,    60,    46,    66,    76,    47,    -1,
      54,    39,    42,    64,    43,    55,    14,    46,    66,    47,
      -1,    65,    -1,    -1,    11,    70,    55,    71,    -1,    65,
      40,    11,    70,    55,    71,    -1,    60,    62,    67,    73,
      -1,    67,    68,    -1,    -1,    33,    70,    55,    71,    40,
      60,    -1,    12,    84,    21,    80,    40,    60,    -1,    12,
      84,    40,    60,    -1,    33,    70,    21,    80,    69,    55,
      71,    40,    60,    -1,    -1,    41,    70,    21,    80,    69,
      -1,    41,    70,    69,    -1,    39,    41,    70,    -1,    39,
      -1,    10,    -1,    12,    44,    48,    45,    -1,    15,    -1,
      16,    -1,    52,    -1,    17,    -1,    13,    -1,    53,    -1,
      10,    -1,    12,    -1,    15,    -1,    16,    -1,    52,    -1,
      17,    -1,    13,    -1,    53,    -1,    73,    77,    67,    -1,
      -1,    77,    -1,     9,    80,    40,    -1,    46,    60,    67,
      73,    76,    47,    60,    -1,     9,    80,    40,    60,    -1,
      -1,     6,    42,    80,    43,    74,    -1,     6,    42,    80,
      43,    74,     7,    74,    -1,     5,    60,    42,    80,    43,
      74,    -1,     8,    60,    42,    78,    40,    80,    40,    78,
      43,    74,    -1,     4,    74,     5,    80,    40,    -1,    78,
      40,    60,    -1,    80,    40,    60,    -1,    75,    -1,    79,
      21,    80,    -1,    39,    44,    80,    45,    -1,    39,    -1,
      83,    -1,    42,    80,    43,    -1,    80,    20,    80,    -1,
      80,    28,    80,    -1,    80,    24,    80,    -1,    80,    25,
      80,    -1,    80,    26,    80,    -1,    80,    27,    80,    -1,
      80,    18,    80,    -1,    80,    22,    80,    -1,    80,    31,
      80,    -1,    80,    32,    80,    -1,    80,    56,    80,    -1,
      80,    30,    80,    -1,    29,    80,    -1,    81,    -1,    83,
      -1,    86,    60,    -1,    48,    -1,    49,    -1,    36,    -1,
      35,    -1,    34,    -1,    51,    -1,    50,    -1,    23,    39,
      23,    -1,    39,    44,    80,    45,    -1,    39,    -1,    37,
      -1,    19,    81,    -1,    82,    -1,    19,    39,    -1,    19,
      42,    39,    43,    -1,    19,    39,    44,    80,    45,    -1,
      19,    42,    39,    44,    80,    45,    43,    -1,    56,    39,
      -1,    56,    42,    80,    43,    -1,    56,    39,    44,    80,
      45,    -1,    80,    41,    84,    -1,    80,    -1,    -1,    42,
      84,    43,    -1,    39,    85,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    62,    65,    65,    68,    73,    76,    77,
      81,    85,    93,    94,    96,    97,   102,   109,   109,   112,
     116,   120,   124,   130,   131,   135,   143,   144,   148,   149,
     150,   151,   152,   153,   154,   155,   160,   161,   162,   163,
     164,   165,   166,   167,   171,   171,   174,   174,   177,   183,
     183,   186,   192,   200,   206,   214,   221,   222,   223,   229,
     236,   240,   241,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   276,   278,
     279,   283,   283,   285,   286,   287,   289,   301,   302,   303,
     307,   308,   309,   312,   315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "DO", "WHILE", "IF", "ELSE",
  "FOR", "RETURN", "BOOL", "ARROW", "STRING", "CHARPTR", "VOID", "CHAR",
  "INT", "INTPTR", "AND", "ADDRESS", "EQUAL", "ASSIGN", "OR", "LENGTH",
  "GREATEREQUAL", "GREATER", "LESSEQUAL", "LESS", "NOTEQUAL", "NOT", "DIV",
  "PLUS", "MINUS", "VARIABLE", "STRING_LTL", "REAL_LTL", "CHAR_LTL",
  "NULLL", "MAIN", "IDENTIFIER", "SEMICOLON", "COMMA", "OPAREN", "CPAREN",
  "OBRACKET", "CBRACKET", "OBRACE", "CBRACE", "DECIMAL_LTL", "HEX_LTL",
  "TRUE", "FALSE", "REAL", "REALPTR", "FUNCTION", "COLON", "ETOILE",
  "$accept", "project", "prog", "comments", "main", "functions",
  "function", "parameters", "parameters_lst", "body", "declarations",
  "declaration", "var_dec", "varident", "id_type", "func_type", "stmnts",
  "stmnt_block", "new_block", "RET", "stmnt", "ass_stmnt", "lhs", "expr",
  "address_exprs", "address_expr", "derefrence_expr", "expr_list",
  "paren_expr", "call_func", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      84,    84,    84,    85,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     8,     0,     2,     0,
      12,    10,     1,     0,     4,     6,     4,     2,     0,     6,
       6,     4,     9,     0,     5,     3,     3,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     3,     7,     4,
       0,     5,     7,     6,    10,     5,     3,     3,     1,     3,
       4,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       1,     2,     1,     2,     4,     5,     7,     2,     4,     5,
       3,     1,     0,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     5,     0,     9,     4,     1,     2,     7,     0,     3,
       8,     0,     0,    13,    13,     0,     0,    12,     0,    27,
       0,     0,     0,     0,     0,     0,     5,     0,     0,    26,
      28,     0,    34,    30,    31,    33,    32,    35,    14,     9,
       0,     0,    36,    37,    42,     0,    38,    39,    41,    40,
      43,     5,     0,    18,     6,     0,     5,     0,     0,     0,
      45,    15,     0,     5,    29,   102,     0,    17,    16,    11,
      50,     0,     0,     0,    84,    83,    82,    90,    89,     0,
      80,    81,    86,    85,     0,   101,    77,    92,    78,     0,
       5,     0,     0,     5,     0,     5,    89,     5,    58,    18,
       0,     0,     0,    78,     0,     0,    93,     0,    91,     0,
      76,   102,     0,   104,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,     5,    79,     0,     0,     0,     0,    46,     0,     0,
       0,     0,    18,    44,     5,     0,     5,     0,    10,     0,
       0,    87,     0,     0,    63,     0,     0,    70,    64,    71,
      66,    67,    68,    69,    65,    75,    72,    73,   100,    74,
       0,    21,    23,     0,     0,     0,     0,     0,     0,     0,
      45,    56,    59,    57,     5,     0,    94,     0,   103,    88,
       0,    98,     5,     0,     0,     5,    47,     0,     0,     0,
      61,     0,    62,    88,    50,    49,    95,     0,    99,    20,
      23,     0,    19,    55,     0,    51,     0,     0,     0,     0,
       0,    25,     0,    53,     0,     0,     0,     5,    96,    23,
       5,    52,    60,     0,    48,    24,    22,     0,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    39,     9,     7,    10,    16,    17,    40,
      60,    67,   194,    20,    38,    51,    68,   136,    98,   105,
     137,   100,   101,   102,    86,    87,    88,    89,   113,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -173
static const yytype_int16 yypact[] =
{
      15,    15,    58,  -173,  -173,  -173,  -173,   -18,    48,  -173,
    -173,    25,    39,    54,    54,    44,    49,    51,    53,    57,
      55,    63,    92,    64,    44,   110,    15,    44,     7,  -173,
    -173,    73,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
      61,    69,  -173,  -173,  -173,    72,  -173,  -173,  -173,  -173,
    -173,    15,    80,    75,  -173,   110,    15,    84,    89,    93,
      -3,  -173,    88,    15,  -173,   654,    44,  -173,   241,  -173,
     127,   -11,    98,   654,  -173,  -173,  -173,  -173,    36,   654,
    -173,  -173,  -173,  -173,    37,   288,  -173,  -173,  -173,    28,
      15,    -8,     6,    15,    97,    15,    -5,    15,  -173,  -173,
     100,   121,   306,   122,   654,   103,   101,   125,  -173,   138,
    -173,   654,   654,  -173,   323,   124,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,    15,  -173,   654,   110,   654,   160,  -173,   128,   654,
     132,   654,  -173,    -3,    15,   654,    15,   343,  -173,   654,
      62,  -173,   126,   360,  -173,   654,   376,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   129,   213,   213,  -173,   129,
     403,  -173,   420,   131,   438,   654,   654,   455,    -6,   475,
      -3,  -173,   639,  -173,    15,   497,  -173,   654,  -173,  -173,
     519,  -173,    15,    44,   120,    15,  -173,   541,   558,     6,
     133,   136,  -173,   157,    65,  -173,  -173,   578,  -173,  -173,
      23,   110,  -173,  -173,     6,   172,   654,   654,   134,   137,
     654,  -173,   142,  -173,     6,   600,   622,    15,  -173,   420,
      15,  -173,  -173,    -6,  -173,  -173,  -173,   140,     6,  -173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,     0,  -173,   146,  -173,   173,  -173,   -29,
     -67,  -173,  -144,   -20,   -52,  -173,     8,  -161,  -173,   -15,
     -63,  -172,  -173,    87,   115,  -173,   -66,   -39,  -173,  -173
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -63
static const yytype_int16 yytable[] =
{
       3,     4,   103,    61,    29,    99,   201,    41,    71,    65,
      92,    93,    94,   133,    95,   135,   -61,    42,     1,    43,
      44,    45,    46,    47,    48,    71,   103,    62,   106,    72,
      66,   107,   143,   200,    70,    73,     8,   111,   215,   141,
      74,    75,    76,    77,   220,    96,    91,   134,    79,   130,
      84,    57,    97,   223,    80,    81,    82,    83,     5,    49,
      50,   237,    84,   231,   193,    15,   221,    13,   131,    92,
      93,    94,   152,    95,   104,   180,   115,   239,   111,   116,
     112,    14,   173,    19,    71,   235,    11,    12,    72,   168,
     132,    22,    21,   138,    73,   140,    23,   142,    24,    74,
      75,    76,    77,    27,    96,   186,   187,    79,    54,    26,
      25,    97,   202,    80,    81,    82,    83,    52,    56,    28,
      30,    84,    31,    32,    55,    33,    34,    35,    58,    59,
      63,   171,    12,   103,    64,    69,   104,   109,   103,   139,
     144,    99,   145,   -62,   181,   149,   183,   117,   103,   118,
     148,   119,    85,   120,   121,   122,   123,   124,   103,   222,
     110,   151,    36,    37,   150,   175,   114,   202,   155,   188,
     176,   195,   103,   210,   178,   211,   217,   216,   -60,   224,
     228,   227,   230,   238,   205,    53,   108,    18,   204,   218,
       0,   147,   209,     0,     0,   212,     0,     0,    85,   153,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    85,   169,   170,     0,     0,
     172,     0,   174,     0,     0,     0,   177,   234,   179,     0,
     236,   117,   182,   118,     0,   119,   185,   120,   121,   122,
     123,   124,   190,   125,     0,    92,    93,    94,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     0,   197,   198,    72,     0,     0,     0,     0,   129,
      73,     0,     0,     0,   207,    74,    75,    76,    77,     0,
      96,     0,     0,    79,     0,     0,     0,    97,     0,    80,
      81,    82,    83,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,   225,   226,     0,   117,   229,   118,     0,
     119,     0,   120,   121,   122,   123,   124,     0,   125,   126,
     127,     0,     0,     0,   117,     0,   118,     0,   119,   128,
     120,   121,   122,   123,   124,     0,   125,   126,   127,     0,
       0,   117,     0,   118,   129,   119,   146,   120,   121,   122,
     123,   124,     0,   125,   126,   127,     0,     0,     0,     0,
       0,   117,   129,   118,     0,   119,   154,   120,   121,   122,
     123,   124,     0,   125,   126,   127,     0,     0,   117,   129,
     118,     0,   119,   184,   120,   121,   122,   123,   124,     0,
     125,   126,   127,     0,   117,     0,   118,     0,   119,   129,
     120,   121,   122,   123,   124,   189,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,   191,
       0,   117,     0,   118,     0,   119,     0,   120,   121,   122,
     123,   124,   129,   125,   126,   127,     0,     0,   117,     0,
     118,     0,   119,   192,   120,   121,   122,   123,   124,     0,
     125,   126,   127,     0,     0,     0,   117,     0,   118,   129,
     119,   193,   120,   121,   122,   123,   124,     0,   125,   126,
     127,     0,     0,   117,     0,   118,   129,   119,   196,   120,
     121,   122,   123,   124,     0,   125,   126,   127,     0,     0,
       0,     0,     0,   117,   129,   118,     0,   119,   199,   120,
     121,   122,   123,   124,     0,   125,   126,   127,     0,     0,
       0,   129,     0,     0,     0,   117,     0,   118,     0,   119,
     203,   120,   121,   122,   123,   124,     0,   125,   126,   127,
       0,   129,     0,     0,     0,     0,     0,   117,     0,   118,
       0,   119,   206,   120,   121,   122,   123,   124,     0,   125,
     126,   127,     0,   129,     0,     0,     0,     0,     0,   117,
       0,   118,     0,   119,   208,   120,   121,   122,   123,   124,
       0,   125,   126,   127,     0,   129,   117,     0,   118,     0,
     119,   213,   120,   121,   122,   123,   124,     0,   125,   126,
     127,     0,     0,     0,     0,     0,   117,   129,   118,     0,
     119,   214,   120,   121,   122,   123,   124,     0,   125,   126,
     127,     0,     0,     0,   129,     0,     0,     0,   117,     0,
     118,     0,   119,   219,   120,   121,   122,   123,   124,     0,
     125,   126,   127,     0,   129,     0,     0,     0,     0,     0,
     117,     0,   118,     0,   119,   232,   120,   121,   122,   123,
     124,     0,   125,   126,   127,     0,   129,   117,     0,   118,
       0,   119,   233,   120,   121,   122,   123,   124,     0,   125,
     126,   127,     0,    71,     0,     0,     0,    72,   129,     0,
       0,     0,     0,    73,     0,     0,     0,     0,    74,    75,
      76,    77,     0,    78,     0,   129,    79,     0,     0,     0,
       0,     0,    80,    81,    82,    83,     0,     0,     0,     0,
      84
};

static const yytype_int16 yycheck[] =
{
       0,     1,    68,    55,    24,    68,   178,    27,    19,    12,
       4,     5,     6,    21,     8,     9,    21,    10,     3,    12,
      13,    14,    15,    16,    17,    19,    92,    56,    39,    23,
      33,    42,    99,    39,    63,    29,    54,    42,   199,    44,
      34,    35,    36,    37,    21,    39,    66,    55,    42,    21,
      56,    51,    46,   214,    48,    49,    50,    51,     0,    52,
      53,   233,    56,   224,    41,    11,   210,    42,    40,     4,
       5,     6,   111,     8,     9,   142,    39,   238,    42,    42,
      44,    42,   134,    39,    19,   229,    38,    39,    23,   128,
      90,    40,    43,    93,    29,    95,    43,    97,    41,    34,
      35,    36,    37,    11,    39,    43,    44,    42,    47,    46,
      55,    46,   178,    48,    49,    50,    51,    44,    46,    55,
      10,    56,    12,    13,    55,    15,    16,    17,    48,    54,
      46,   131,    39,   199,    45,    47,     9,    39,   204,    42,
      40,   204,    21,    21,   144,    44,   146,    18,   214,    20,
      47,    22,    65,    24,    25,    26,    27,    28,   224,   211,
      73,    23,    52,    53,    39,     5,    79,   233,    44,    43,
      42,    40,   238,   193,    42,    55,    40,    44,    21,     7,
      43,    47,    40,    43,   184,    39,    71,    14,   180,   204,
      -1,   104,   192,    -1,    -1,   195,    -1,    -1,   111,   112,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
     133,    -1,   135,    -1,    -1,    -1,   139,   227,   141,    -1,
     230,    18,   145,    20,    -1,    22,   149,    24,    25,    26,
      27,    28,   155,    30,    -1,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,   175,   176,    23,    -1,    -1,    -1,    -1,    56,
      29,    -1,    -1,    -1,   187,    34,    35,    36,    37,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,   216,   217,    -1,    18,   220,    20,    -1,
      22,    -1,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    -1,    -1,    -1,    18,    -1,    20,    -1,    22,    41,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    -1,
      -1,    18,    -1,    20,    56,    22,    40,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    18,    56,    20,    -1,    22,    43,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,    -1,    18,    56,
      20,    -1,    22,    40,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    -1,    18,    -1,    20,    -1,    22,    56,
      24,    25,    26,    27,    28,    45,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    43,
      -1,    18,    -1,    20,    -1,    22,    -1,    24,    25,    26,
      27,    28,    56,    30,    31,    32,    -1,    -1,    18,    -1,
      20,    -1,    22,    40,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    -1,    -1,    -1,    18,    -1,    20,    56,
      22,    41,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    -1,    -1,    18,    -1,    20,    56,    22,    40,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    18,    56,    20,    -1,    22,    43,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    18,    -1,    20,    -1,    22,
      45,    24,    25,    26,    27,    28,    -1,    30,    31,    32,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      -1,    22,    45,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    -1,    56,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    -1,    22,    45,    24,    25,    26,    27,    28,
      -1,    30,    31,    32,    -1,    56,    18,    -1,    20,    -1,
      22,    40,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    18,    56,    20,    -1,
      22,    43,    24,    25,    26,    27,    28,    -1,    30,    31,
      32,    -1,    -1,    -1,    56,    -1,    -1,    -1,    18,    -1,
      20,    -1,    22,    45,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    -1,    22,    45,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    -1,    56,    18,    -1,    20,
      -1,    22,    40,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    -1,    19,    -1,    -1,    -1,    23,    56,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    39,    -1,    56,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    58,    60,    60,     0,    59,    62,    54,    61,
      63,    38,    39,    42,    42,    11,    64,    65,    64,    39,
      70,    43,    40,    43,    41,    55,    46,    11,    55,    70,
      10,    12,    13,    15,    16,    17,    52,    53,    71,    60,
      66,    70,    10,    12,    13,    14,    15,    16,    17,    52,
      53,    72,    44,    62,    47,    55,    46,    60,    48,    54,
      67,    71,    66,    46,    45,    12,    33,    68,    73,    47,
      66,    19,    23,    29,    34,    35,    36,    37,    39,    42,
      48,    49,    50,    51,    56,    80,    81,    82,    83,    84,
      86,    70,     4,     5,     6,     8,    39,    46,    75,    77,
      78,    79,    80,    83,     9,    76,    39,    42,    81,    39,
      80,    42,    44,    85,    80,    39,    42,    18,    20,    22,
      24,    25,    26,    27,    28,    30,    31,    32,    41,    56,
      21,    40,    60,    21,    55,     9,    74,    77,    60,    42,
      60,    44,    60,    67,    40,    21,    40,    80,    47,    44,
      39,    23,    84,    80,    43,    44,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    84,    80,
      80,    60,    80,    71,    80,     5,    42,    80,    42,    80,
      67,    60,    80,    60,    40,    80,    43,    44,    43,    45,
      80,    43,    40,    41,    69,    40,    40,    80,    80,    43,
      39,    78,    83,    45,    73,    60,    45,    80,    45,    60,
      70,    55,    60,    40,    43,    74,    44,    40,    76,    45,
      21,    69,    71,    74,     7,    80,    80,    47,    43,    80,
      40,    74,    45,    40,    60,    69,    60,    78,    43,    74
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 60 "partie1.y"
    { Printtree((yyvsp[(2) - (2)].node)); printf("The syntax is accepted \n");}
    break;

  case 3:
#line 62 "partie1.y"
    {(yyval.node)=mknode("CODE ",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 6:
#line 69 "partie1.y"
    {
(yyval.node)=mknode("function",
mknode("Main",mknode("\n",NULL,NULL),NULL),
mknode("ARGS",NULL,(yyvsp[(7) - (8)].node)));
}
    break;

  case 7:
#line 73 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 8:
#line 76 "partie1.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 9:
#line 77 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 10:
#line 82 "partie1.y"
    { 
  (yyval.node)=mknode("function",mknode((yyvsp[(2) - (12)].string),mknode("\n",NULL,NULL),mknode("ARGS",(yyvsp[(4) - (12)].node),mknode("return",(yyvsp[(7) - (12)].node),NULL))),mknode("",(yyvsp[(10) - (12)].node),(yyvsp[(11) - (12)].node)));	
}
    break;

  case 11:
#line 86 "partie1.y"
    {
  (yyval.node)=mknode("function",mknode((yyvsp[(2) - (10)].string),mknode("\n",NULL,NULL),NULL),mknode("ARGS",(yyvsp[(4) - (10)].node),(yyvsp[(9) - (10)].node)));
}
    break;

  case 12:
#line 93 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 13:
#line 94 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 14:
#line 96 "partie1.y"
    {(yyval.node)=mknode("(",(yyvsp[(4) - (4)].node),mknode("",(yyvsp[(2) - (4)].node),mknode(")",NULL,NULL)));}
    break;

  case 15:
#line 97 "partie1.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (6)].node),mknode("",(yyvsp[(4) - (6)].node),mknode("(",(yyvsp[(6) - (6)].node),mknode(")",NULL,NULL))));}
    break;

  case 16:
#line 103 "partie1.y"
    {
	(yyval.node)=mknode("(BODY\n    ", mknode("",(yyvsp[(2) - (4)].node),NULL),mknode("",(yyvsp[(3) - (4)].node),mknode("",(yyvsp[(4) - (4)].node),mknode("}",NULL,NULL))));
}
    break;

  case 17:
#line 109 "partie1.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 18:
#line 109 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 19:
#line 113 "partie1.y"
    {
    (yyval.node)=mknode("var", (yyvsp[(4) - (6)].node),(yyvsp[(2) - (6)].node));
}
    break;

  case 20:
#line 117 "partie1.y"
    {
    (yyval.node) = mknode("str", (yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node));
}
    break;

  case 21:
#line 121 "partie1.y"
    {
    (yyval.node) = mknode("str", (yyvsp[(2) - (4)].node), NULL);
}
    break;

  case 22:
#line 125 "partie1.y"
    {
    (yyval.node) = mknode("var" ,mknode("", (yyvsp[(5) - (9)].node),mknode("=", (yyvsp[(2) - (9)].node), (yyvsp[(4) - (9)].node))),(yyvsp[(7) - (9)].node));
}
    break;

  case 23:
#line 130 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 24:
#line 132 "partie1.y"
    {
    (yyval.node) = mknode("var", mknode("=", (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)),(yyvsp[(5) - (5)].node));
}
    break;

  case 25:
#line 135 "partie1.y"
    {
    (yyval.node) = mknode("var", mknode("", (yyvsp[(2) - (3)].node), NULL),(yyvsp[(3) - (3)].node));
}
    break;

  case 26:
#line 143 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (3)].string), mknode(" ", (yyvsp[(3) - (3)].node), NULL),NULL);}
    break;

  case 27:
#line 144 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string), NULL, NULL);}
    break;

  case 28:
#line 148 "partie1.y"
    {(yyval.node)=mknode("bool", NULL, NULL);}
    break;

  case 29:
#line 149 "partie1.y"
    {(yyval.node)=mknode("string", NULL, NULL);}
    break;

  case 30:
#line 150 "partie1.y"
    {(yyval.node)=mknode("char", NULL, NULL);}
    break;

  case 31:
#line 151 "partie1.y"
    {(yyval.node)=mknode("int", NULL, NULL);}
    break;

  case 32:
#line 152 "partie1.y"
    {(yyval.node)=mknode("real", NULL, NULL);}
    break;

  case 33:
#line 153 "partie1.y"
    {(yyval.node)=mknode("int*", NULL, NULL);}
    break;

  case 34:
#line 154 "partie1.y"
    {(yyval.node)=mknode("char*", NULL, NULL);}
    break;

  case 35:
#line 155 "partie1.y"
    {(yyval.node)=mknode("real*", NULL, NULL);}
    break;

  case 36:
#line 160 "partie1.y"
    {(yyval.node)=mknode("boolean", NULL, NULL);}
    break;

  case 37:
#line 161 "partie1.y"
    {(yyval.node)=mknode("string", NULL, NULL);}
    break;

  case 38:
#line 162 "partie1.y"
    {(yyval.node)=mknode("char", NULL, NULL);}
    break;

  case 39:
#line 163 "partie1.y"
    {(yyval.node)=mknode("int", NULL, NULL);}
    break;

  case 40:
#line 164 "partie1.y"
    {(yyval.node)=mknode("real", NULL, NULL);}
    break;

  case 41:
#line 165 "partie1.y"
    {(yyval.node)=mknode("int*", NULL, NULL);}
    break;

  case 42:
#line 166 "partie1.y"
    {(yyval.node)=mknode("char*", NULL, NULL);}
    break;

  case 43:
#line 167 "partie1.y"
    {(yyval.node)=mknode("real*", NULL, NULL);}
    break;

  case 44:
#line 171 "partie1.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 45:
#line 171 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 46:
#line 174 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 47:
#line 174 "partie1.y"
    {(yyval.node)=mknode("return",(yyvsp[(2) - (3)].node),NULL);}
    break;

  case 48:
#line 178 "partie1.y"
    {
	(yyval.node)=mknode("{",(yyvsp[(3) - (7)].node),mknode("", (yyvsp[(4) - (7)].node), mknode("",(yyvsp[(5) - (7)].node),mknode("}",NULL,NULL))));
}
    break;

  case 49:
#line 183 "partie1.y"
    {(yyval.node)=mknode("return",(yyvsp[(2) - (4)].node),NULL);}
    break;

  case 50:
#line 183 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 51:
#line 187 "partie1.y"
    {
	(yyval.node)=mknode("if",
	mknode("(", (yyvsp[(3) - (5)].node), 
	mknode(")",NULL,NULL)),(yyvsp[(5) - (5)].node));
}
    break;

  case 52:
#line 193 "partie1.y"
    {
	(yyval.node)=mknode("if-else",
	mknode("(", (yyvsp[(3) - (7)].node), 
	mknode(")",NULL,NULL)),
	mknode("",(yyvsp[(5) - (7)].node),
	mknode("",(yyvsp[(7) - (7)].node),NULL)));
}
    break;

  case 53:
#line 201 "partie1.y"
    {
	(yyval.node)=mknode("while",
	mknode("(", (yyvsp[(4) - (6)].node), 
	mknode(")",NULL,NULL)),(yyvsp[(6) - (6)].node));
}
    break;

  case 54:
#line 207 "partie1.y"
    {
		(yyval.node)= mknode("for",
			mknode("(",
			mknode("",(yyvsp[(4) - (10)].node),(yyvsp[(6) - (10)].node)),
			mknode("",(yyvsp[(8) - (10)].node),
			mknode(")",NULL,NULL))),(yyvsp[(10) - (10)].node));		
}
    break;

  case 55:
#line 215 "partie1.y"
    {
	(yyval.node)=mknode("do-while",
	mknode("DO", (yyvsp[(2) - (5)].node), 
	mknode(")",NULL,NULL)),
	mknode("WHILE",(yyvsp[(4) - (5)].node),NULL));
}
    break;

  case 56:
#line 221 "partie1.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),NULL);}
    break;

  case 57:
#line 222 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node);}
    break;

  case 58:
#line 223 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 59:
#line 230 "partie1.y"
    {
	(yyval.node)=mknode("=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
}
    break;

  case 60:
#line 237 "partie1.y"
    {
	(yyval.node)=mknode((yyvsp[(1) - (4)].string), mknode("[",(yyvsp[(3) - (4)].node),mknode("]",NULL,NULL)), NULL);
}
    break;

  case 61:
#line 240 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 62:
#line 241 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 63:
#line 246 "partie1.y"
    {(yyval.node)=mknode("(",(yyvsp[(2) - (3)].node),mknode(")",NULL,NULL));}
    break;

  case 64:
#line 247 "partie1.y"
    {(yyval.node)=mknode("==",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 65:
#line 248 "partie1.y"
    {(yyval.node)=mknode("!=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 66:
#line 249 "partie1.y"
    {(yyval.node)=mknode(">=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 67:
#line 250 "partie1.y"
    {(yyval.node)=mknode(">",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 68:
#line 251 "partie1.y"
    {(yyval.node)=mknode("<=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 69:
#line 252 "partie1.y"
    {(yyval.node)=mknode("<",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 253 "partie1.y"
    {(yyval.node)=mknode("&&",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 254 "partie1.y"
    {(yyval.node)=mknode("||",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 255 "partie1.y"
    {(yyval.node)=mknode("+",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 256 "partie1.y"
    {(yyval.node)=mknode("-",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 74:
#line 257 "partie1.y"
    {(yyval.node)=mknode("*",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 75:
#line 258 "partie1.y"
    {(yyval.node)=mknode("/",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 76:
#line 259 "partie1.y"
    {(yyval.node)=mknode("!",(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 77:
#line 260 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 78:
#line 261 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 79:
#line 262 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 80:
#line 263 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 81:
#line 264 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 82:
#line 265 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 83:
#line 266 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 84:
#line 267 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 85:
#line 268 "partie1.y"
    {(yyval.node)=mknode("false",NULL,NULL);}
    break;

  case 86:
#line 269 "partie1.y"
    {(yyval.node)=mknode("true",NULL,NULL);}
    break;

  case 87:
#line 271 "partie1.y"
    {
		(yyval.node)=mknode("|",
		mknode((yyvsp[(2) - (3)].string),NULL,NULL),
		mknode("|",NULL,NULL));
	}
    break;

  case 88:
#line 277 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (4)].string),mknode("[",(yyvsp[(3) - (4)].node),mknode("]",NULL,NULL)),NULL);}
    break;

  case 89:
#line 278 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 90:
#line 279 "partie1.y"
    {(yyval.node)=mknode("null",NULL,NULL);}
    break;

  case 91:
#line 283 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 92:
#line 283 "partie1.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 93:
#line 285 "partie1.y"
    {(yyval.node)=mknode("&",mknode((yyvsp[(2) - (2)].string),NULL,NULL),NULL);}
    break;

  case 94:
#line 286 "partie1.y"
    {(yyval.node)=mknode("&",mknode("(",mknode((yyvsp[(3) - (4)].string),NULL,NULL),NULL),mknode(")",NULL,NULL));}
    break;

  case 95:
#line 288 "partie1.y"
    {(yyval.node)=mknode("&", mknode((yyvsp[(2) - (5)].string),NULL,NULL), mknode("[",(yyvsp[(4) - (5)].node),mknode("]",NULL,NULL)));}
    break;

  case 96:
#line 290 "partie1.y"
    {
		(yyval.node)=mknode("&",
		mknode("(", 
		mknode((yyvsp[(3) - (7)].string),NULL,NULL),
		mknode("[",(yyvsp[(5) - (7)].node),NULL)), 
		mknode("]",NULL,mknode(")",NULL,NULL)));
	}
    break;

  case 97:
#line 301 "partie1.y"
    {(yyval.node)=mknode("*",mknode((yyvsp[(2) - (2)].string),NULL,NULL),NULL);}
    break;

  case 98:
#line 302 "partie1.y"
    {(yyval.node)=mknode("*",mknode("(",(yyvsp[(3) - (4)].node),NULL),mknode(")",NULL,NULL));}
    break;

  case 99:
#line 304 "partie1.y"
    {(yyval.node)=mknode((yyvsp[(1) - (5)].string), mknode((yyvsp[(2) - (5)].string),NULL,NULL), mknode("[",(yyvsp[(4) - (5)].node),mknode("]",NULL,NULL)));}
    break;

  case 100:
#line 307 "partie1.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),mknode(",",(yyvsp[(3) - (3)].node),NULL));}
    break;

  case 101:
#line 308 "partie1.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 102:
#line 309 "partie1.y"
    {(yyval.node)=NULL;}
    break;

  case 103:
#line 312 "partie1.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 104:
#line 315 "partie1.y"
    {(yyval.node)=mknode("Call function",mknode((yyvsp[(1) - (2)].string),NULL,NULL),mknode("ARGS",(yyvsp[(2) - (2)].node),NULL));}
    break;


/* Line 1267 of yacc.c.  */
#line 2310 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 316 "partie1.y"




int main()
{
	return yyparse();	
}

/* allocation for node*/
node* mknode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

void printTabs(int n)
{
	int i;
	for(i=0;i<n/3;i++)
		printf(" ");
}



void Printtree(node* tree)
{
	int step = 4;
	printTabs(printlevel); 


	
	if(strcmp(tree->token, "var") == 0)
	{
		
		printf("DECLARE : ");
		step =3;

	}
	else if(strcmp(tree->token, "if") == 0)
	{
		printf("(IF\n");
		step = 1;
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		printf("(WHILE\n");
		step = 1;
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{
		printf("(FOR\n");
		step = 1;
		
		
	}
		else if(strcmp(tree->token, "function") == 0 ||strcmp(tree->token, "CODE") == 0||strcmp(tree->token, "Call function") == 0)
	{
		printf("(%s \n",tree->token);
		step=2;
		
	}
		else if(strcmp(tree->token, "ARGS") == 0)
	{
		printf("ARGS : ");
		if(tree->left)
		{
			step = 1;
			
		}
		else{
			printf(" NONE)\n"); 
		}
	}
		else if(strcmp(tree->token, "if-else") == 0)
	{
		printf("(IF-ELSE\n");
		printlevel--;
		
		step = 1;
	}
		else if(strcmp(tree->token, "do-while") == 0)
	{
		printf("(DO-WHILE\n");
		printlevel--;
		
		step = 1;
	}
			else if(strcmp(tree->token, "return") == 0)
	{
		printf("(RETURN ");
		step = 2;
	}
	else if(strcmp(tree->token, "{") == 0)
	{
                printf("(BLOCK\n");
				
				
	}
	else if(strcmp(tree->token, "}") == 0)
	{
		printf(")\n");
	}
	else if(strcmp(tree->token, "") == 0);
	else if(strcmp(tree->token, "(") == 0)
			printf("(");
	else if(strcmp(tree->token, "\n") == 0)
			printf("\n");
	else if(strcmp(tree->token, ")") == 0)
			printf(")\n");
	else if(strcmp(tree->token, ",") == 0)
			printf(",");
	else if(strcmp(tree->token, ";") == 0)
			printf("\n");
	else if(strcmp(tree->token, "&&") == 0 ||strcmp(tree->token, "||") == 0 || strcmp(tree->token, "!=") == 0 || strcmp(tree->token, "!") == 0 )
	{
			printf("(%s",tree->token);
			step=1;
			if(strcmp(tree->token, "=") == 0)
				step=2;
				
	}
	else if (strcmp(tree->token, "/") == 0 || strcmp(tree->token, "+") == 0 || strcmp(tree->token, "*") == 0 || strcmp(tree->token, "-") == 0 ) 
	{
			printf("(%s",tree->token);
			step=1;
			if(strcmp(tree->token, "=") == 0)
				step=2;
				
	}
	else if (strcmp(tree->token, "=") == 0 || strcmp(tree->token, "==") == 0 || strcmp(tree->token, ">") == 0 || strcmp(tree->token, ">=") == 0 || strcmp(tree->token, "<") == 0 || 
	strcmp(tree->token, "<=") == 0 || strcmp(tree->token, "/") == 0  ||strcmp(tree->token, "&") == 0 || strcmp(tree->token, "|") == 0 || strcmp(tree->token, ",") == 0)
 	{
			printf("(%s",tree->token);
			step=1;
			if(strcmp(tree->token, "=") == 0)
				step=2;
				
	}
	else
	{
		if(tree && (!tree->left && !tree->right)
		||strcmp(tree->token, "Main") == 0)
		{
			printf("%s ", tree->token);
			
		}
		else
		{
			printlevel++;
			printf("%s", tree->token);
			printlevel--;
		
		}
	}
	if (tree->left) 
	{
		printlevel++;
		Printtree(tree->left);
		printlevel--;
	}
	
	if (tree->right)
	{
		printlevel++;
		Printtree(tree->right);
		printlevel--;
		
	}
	if(step == 3)
		printf("\n");
	if(step == 2)
		printf(")\n");
	
	if(step == 1)
		printf(")");
	if(step == 0)
		printf("\n)");

}
int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"You have a %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "The language does not accept '%s'\n",yytext);
	
	return 0;
}
