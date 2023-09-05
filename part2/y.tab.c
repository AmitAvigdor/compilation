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
     REAL_LTL = 289,
     CHAR_LTL = 290,
     NULLL = 291,
     MAIN = 292,
     IDENTIFIER = 293,
     SEMICOLON = 294,
     COMMA = 295,
     OPAREN = 296,
     CPAREN = 297,
     OBRACKET = 298,
     CBRACKET = 299,
     OBRACE = 300,
     CBRACE = 301,
     DECIMAL_LTL = 302,
     HEX_LTL = 303,
     STRING_LTL = 304,
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
#define REAL_LTL 289
#define CHAR_LTL 290
#define NULLL 291
#define MAIN 292
#define IDENTIFIER 293
#define SEMICOLON 294
#define COMMA 295
#define OPAREN 296
#define CPAREN 297
#define OBRACKET 298
#define CBRACKET 299
#define OBRACE 300
#define CBRACE 301
#define DECIMAL_LTL 302
#define HEX_LTL 303
#define STRING_LTL 304
#define TRUE 305
#define FALSE 306
#define REAL 307
#define REALPTR 308
#define FUNCTION 309
#define COLON 310
#define ETOILE 311




/* Copy the first part of user declarations.  */
#line 1 "partie2.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"


typedef enum {false,true} bool;


	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;


  typedef struct Function 
	{
        char * name;
		struct Variables * arguments;
        char *returnType; 
		int argNum;
		bool findreturn;
    } Function;
	

	typedef struct Variables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * len;
	}Variables;

		typedef struct SCOPE
	{	
		char *name;
		Variables * var;
		int VarCount;
		int Checkcount;
		Function ** func;
		struct SCOPE * nextScope;
		struct SCOPE * preScope;
	}SCOPE;
	static int scope=0;

	char* getExpType(node *,SCOPE*);
	Variables* mkArguments(node *,int *);
	void addFunc(char * name,Variables * arguments,node *returnType,int argNum,SCOPE*);
	void addVar(Variables * arguments,int,int,SCOPE * TheScope);
	SCOPE* mkcode(char *);
	SCOPE* findScope(SCOPE * scopes);
	SCOPE* globalScope=NULL;
	node* mknode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTabs(int n);
	int yylex();
	int yyerror(char *e);
	void pushScopes(SCOPE* from,char*);
	int printlevel=0;
	SCOPE* mycode=NULL;
	void Analyzer(node *tree,SCOPE * scope);
	char* findFuncInScopes(node * tree,SCOPE * TheScope);
	char* findVar(node * tree,SCOPE * TheScope);
	Variables* callFuncArguments(SCOPE *,node *tree,int * count);
	


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
#line 73 "partie2.y"
{
	int i;
    struct node *node;
    char *string;
}
/* Line 193 of yacc.c.  */
#line 284 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 297 "y.tab.c"

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
#define YYLAST   695

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
      60,    -1,    -1,    54,    37,    41,    64,    42,    45,    66,
      46,    -1,    -1,    62,    63,    -1,    -1,    54,    38,    41,
      64,    42,    55,    72,    60,    45,    66,    76,    46,    -1,
      54,    38,    41,    64,    42,    55,    14,    45,    66,    46,
      -1,    65,    -1,    -1,    11,    70,    55,    71,    -1,    65,
      39,    11,    70,    55,    71,    -1,    60,    62,    67,    73,
      -1,    67,    68,    -1,    -1,    33,    70,    55,    71,    39,
      60,    -1,    12,    84,    21,    80,    39,    60,    -1,    12,
      84,    39,    60,    -1,    33,    70,    21,    80,    69,    55,
      71,    39,    60,    -1,    -1,    40,    70,    21,    80,    69,
      -1,    40,    70,    69,    -1,    38,    40,    70,    -1,    38,
      -1,    10,    -1,    12,    43,    47,    44,    -1,    15,    -1,
      16,    -1,    52,    -1,    17,    -1,    13,    -1,    53,    -1,
      10,    -1,    12,    -1,    15,    -1,    16,    -1,    52,    -1,
      17,    -1,    13,    -1,    53,    -1,    73,    77,    67,    -1,
      -1,    77,    -1,     9,    80,    39,    -1,    45,    60,    67,
      73,    76,    46,    60,    -1,     9,    80,    39,    60,    -1,
      -1,     6,    41,    80,    42,    74,    -1,     6,    41,    80,
      42,    74,     7,    74,    -1,     5,    60,    41,    80,    42,
      74,    -1,     8,    60,    41,    78,    39,    80,    39,    78,
      42,    74,    -1,     4,    74,     5,    80,    39,    -1,    78,
      39,    60,    -1,    80,    39,    60,    -1,    75,    -1,    79,
      21,    80,    -1,    38,    43,    80,    44,    -1,    38,    -1,
      83,    -1,    41,    80,    42,    -1,    80,    20,    80,    -1,
      80,    28,    80,    -1,    80,    24,    80,    -1,    80,    25,
      80,    -1,    80,    26,    80,    -1,    80,    27,    80,    -1,
      80,    18,    80,    -1,    80,    22,    80,    -1,    80,    31,
      80,    -1,    80,    32,    80,    -1,    80,    56,    80,    -1,
      80,    30,    80,    -1,    29,    80,    -1,    81,    -1,    83,
      -1,    86,    60,    -1,    47,    -1,    48,    -1,    35,    -1,
      34,    -1,    49,    -1,    51,    -1,    50,    -1,    23,    38,
      23,    -1,    38,    43,    80,    44,    -1,    38,    -1,    36,
      -1,    19,    81,    -1,    82,    -1,    19,    38,    -1,    19,
      41,    38,    42,    -1,    19,    38,    43,    80,    44,    -1,
      19,    41,    38,    43,    80,    44,    42,    -1,    56,    38,
      -1,    56,    41,    80,    42,    -1,    56,    38,    43,    80,
      44,    -1,    80,    40,    84,    -1,    80,    -1,    -1,    41,
      84,    42,    -1,    38,    85,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   114,   117,   117,   120,   125,   128,   129,
     133,   137,   145,   146,   148,   149,   154,   161,   161,   164,
     168,   172,   176,   182,   183,   187,   195,   196,   200,   201,
     202,   203,   204,   205,   206,   207,   212,   213,   214,   215,
     216,   217,   218,   219,   223,   223,   226,   226,   229,   235,
     235,   238,   244,   252,   258,   266,   273,   274,   275,   281,
     288,   292,   293,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   328,   330,
     331,   335,   335,   337,   338,   339,   341,   353,   354,   355,
     359,   360,   361,   364,   367
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
  "PLUS", "MINUS", "VARIABLE", "REAL_LTL", "CHAR_LTL", "NULLL", "MAIN",
  "IDENTIFIER", "SEMICOLON", "COMMA", "OPAREN", "CPAREN", "OBRACKET",
  "CBRACKET", "OBRACE", "CBRACE", "DECIMAL_LTL", "HEX_LTL", "STRING_LTL",
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
      50,     0,     0,     0,    83,    82,    90,    89,     0,    80,
      81,    84,    86,    85,     0,   101,    77,    92,    78,     0,
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
#define YYPACT_NINF -190
static const yytype_int16 yypact[] =
{
      20,    20,    64,  -190,  -190,  -190,  -190,    14,    25,  -190,
    -190,    28,    29,    65,    65,    41,    38,    42,    43,    44,
      31,    46,    72,    32,    41,   111,    20,    41,   166,  -190,
    -190,    51,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
      50,    34,  -190,  -190,  -190,    54,  -190,  -190,  -190,  -190,
    -190,    20,    53,    47,  -190,   111,    20,    57,    62,    70,
       4,  -190,    63,    20,  -190,   639,    41,  -190,   235,  -190,
     102,    -8,    75,   639,  -190,  -190,  -190,    -7,   639,  -190,
    -190,  -190,  -190,  -190,   -17,   270,  -190,  -190,  -190,     1,
      20,   -13,     9,    20,    74,    20,    -2,    20,  -190,  -190,
      83,   108,   291,   109,   639,    86,    91,    97,  -190,   113,
    -190,   639,   639,  -190,   307,    94,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,    20,  -190,   639,   111,   639,   134,  -190,    99,   639,
     101,   639,  -190,     4,    20,   639,    20,   326,  -190,   639,
      24,  -190,   103,   342,  -190,   639,   363,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,   129,   627,   627,  -190,   129,
     382,  -190,   400,   104,   419,   639,   639,   435,    15,   454,
       4,  -190,   610,  -190,    20,   475,  -190,   639,  -190,  -190,
     496,  -190,    20,    41,    95,    20,  -190,   517,   533,     9,
     118,   123,  -190,   145,    69,  -190,  -190,   552,  -190,  -190,
      -9,   111,  -190,  -190,     9,   161,   639,   639,   124,   127,
     639,  -190,   132,  -190,     9,   573,   594,    20,  -190,   400,
      20,  -190,  -190,    15,  -190,  -190,  -190,   133,     9,  -190
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,     0,  -190,   135,  -190,   163,  -190,   -36,
     -90,  -190,  -181,   -20,   -52,  -190,     5,  -189,  -190,   -18,
     -63,  -172,  -190,    87,   116,  -190,   -66,   -56,  -190,  -190
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -63
static const yytype_int16 yytable[] =
{
       3,     4,   103,    61,    29,    99,   201,    41,   133,   143,
     215,    71,   220,    92,    93,    94,    65,    95,   135,   -61,
      62,   115,   130,     1,   116,   223,   103,    70,    71,   221,
     106,   193,    72,   107,   111,   231,   112,    66,    73,   111,
     131,   141,   134,    74,    75,    76,    91,    96,   235,   239,
      78,    57,   180,   200,    97,   152,    79,    80,    81,    82,
      83,   237,    11,    12,     5,    84,   186,   187,     8,    13,
      14,    84,   168,    92,    93,    94,    15,    95,   104,    19,
      21,    22,   173,    27,    24,    23,    25,    28,    71,    55,
     132,    26,    72,   138,    52,   140,    54,   142,    73,    56,
      58,    59,    63,    74,    75,    76,    64,    96,    12,    69,
      78,   104,   202,   109,    97,   139,    79,    80,    81,    82,
      83,    30,   144,    31,    32,    84,    33,    34,    35,   145,
     -62,   171,   148,   103,   149,   150,   151,   155,   103,   175,
     176,    99,   178,   195,   181,   188,   183,   117,   103,   118,
     211,   119,    85,   120,   121,   122,   123,   124,   103,   222,
     110,   216,   217,    36,    37,   114,   -60,   202,   224,   228,
     227,   230,   103,   210,    53,   238,    42,    18,    43,    44,
      45,    46,    47,    48,   205,   204,   218,   108,     0,     0,
       0,   147,   209,     0,     0,   212,     0,     0,    85,   153,
       0,     0,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    85,   169,   170,    49,    50,
     172,     0,   174,     0,     0,     0,   177,   234,   179,     0,
     236,     0,   182,     0,     0,     0,   185,     0,     0,    92,
      93,    94,   190,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,     0,     0,     0,    72,     0,
       0,     0,   197,   198,    73,     0,     0,     0,     0,    74,
      75,    76,     0,    96,   207,     0,    78,     0,     0,     0,
      97,     0,    79,    80,    81,    82,    83,     0,   117,     0,
     118,    84,   119,     0,   120,   121,   122,   123,   124,     0,
     125,   126,   127,   225,   226,     0,     0,   229,     0,   117,
     128,   118,     0,   119,     0,   120,   121,   122,   123,   124,
       0,   125,   126,   127,     0,   117,   129,   118,     0,   119,
     146,   120,   121,   122,   123,   124,     0,   125,   126,   127,
       0,     0,     0,     0,   117,     0,   118,   129,   119,   154,
     120,   121,   122,   123,   124,     0,   125,   126,   127,     0,
     117,     0,   118,   129,   119,   184,   120,   121,   122,   123,
     124,     0,   125,   126,   127,     0,     0,     0,     0,     0,
       0,   117,   129,   118,     0,   119,   189,   120,   121,   122,
     123,   124,     0,   125,   126,   127,     0,     0,   129,     0,
     117,     0,   118,     0,   119,   191,   120,   121,   122,   123,
     124,     0,   125,   126,   127,     0,     0,     0,   117,   129,
     118,   192,   119,     0,   120,   121,   122,   123,   124,     0,
     125,   126,   127,     0,     0,     0,     0,   117,   129,   118,
     193,   119,     0,   120,   121,   122,   123,   124,     0,   125,
     126,   127,     0,   117,     0,   118,   129,   119,   196,   120,
     121,   122,   123,   124,     0,   125,   126,   127,     0,     0,
       0,     0,   117,     0,   118,   129,   119,   199,   120,   121,
     122,   123,   124,     0,   125,   126,   127,     0,     0,     0,
       0,   129,     0,   117,     0,   118,     0,   119,   203,   120,
     121,   122,   123,   124,     0,   125,   126,   127,     0,     0,
     129,     0,     0,     0,   117,     0,   118,     0,   119,   206,
     120,   121,   122,   123,   124,     0,   125,   126,   127,     0,
       0,   129,     0,     0,     0,   117,     0,   118,     0,   119,
     208,   120,   121,   122,   123,   124,     0,   125,   126,   127,
       0,   117,   129,   118,     0,   119,   213,   120,   121,   122,
     123,   124,     0,   125,   126,   127,     0,     0,     0,     0,
     117,     0,   118,   129,   119,   214,   120,   121,   122,   123,
     124,     0,   125,   126,   127,     0,     0,     0,     0,   129,
       0,   117,     0,   118,     0,   119,   219,   120,   121,   122,
     123,   124,     0,   125,   126,   127,     0,     0,   129,     0,
       0,     0,   117,     0,   118,     0,   119,   232,   120,   121,
     122,   123,   124,     0,   125,   126,   127,     0,   117,   129,
     118,     0,   119,   233,   120,   121,   122,   123,   124,     0,
     125,   126,   127,     0,     0,   117,     0,   118,     0,   119,
     129,   120,   121,   122,   123,   124,     0,   125,    71,     0,
       0,     0,    72,     0,     0,     0,   129,     0,    73,     0,
       0,     0,     0,    74,    75,    76,     0,    77,     0,     0,
      78,     0,     0,   129,     0,     0,    79,    80,    81,    82,
      83,     0,     0,     0,     0,    84
};

static const yytype_int16 yycheck[] =
{
       0,     1,    68,    55,    24,    68,   178,    27,    21,    99,
     199,    19,    21,     4,     5,     6,    12,     8,     9,    21,
      56,    38,    21,     3,    41,   214,    92,    63,    19,   210,
      38,    40,    23,    41,    41,   224,    43,    33,    29,    41,
      39,    43,    55,    34,    35,    36,    66,    38,   229,   238,
      41,    51,   142,    38,    45,   111,    47,    48,    49,    50,
      51,   233,    37,    38,     0,    56,    42,    43,    54,    41,
      41,    56,   128,     4,     5,     6,    11,     8,     9,    38,
      42,    39,   134,    11,    40,    42,    55,    55,    19,    55,
      90,    45,    23,    93,    43,    95,    46,    97,    29,    45,
      47,    54,    45,    34,    35,    36,    44,    38,    38,    46,
      41,     9,   178,    38,    45,    41,    47,    48,    49,    50,
      51,    10,    39,    12,    13,    56,    15,    16,    17,    21,
      21,   131,    46,   199,    43,    38,    23,    43,   204,     5,
      41,   204,    41,    39,   144,    42,   146,    18,   214,    20,
      55,    22,    65,    24,    25,    26,    27,    28,   224,   211,
      73,    43,    39,    52,    53,    78,    21,   233,     7,    42,
      46,    39,   238,   193,    39,    42,    10,    14,    12,    13,
      14,    15,    16,    17,   184,   180,   204,    71,    -1,    -1,
      -1,   104,   192,    -1,    -1,   195,    -1,    -1,   111,   112,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    52,    53,
     133,    -1,   135,    -1,    -1,    -1,   139,   227,   141,    -1,
     230,    -1,   145,    -1,    -1,    -1,   149,    -1,    -1,     4,
       5,     6,   155,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,    -1,
      -1,    -1,   175,   176,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    -1,    38,   187,    -1,    41,    -1,    -1,    -1,
      45,    -1,    47,    48,    49,    50,    51,    -1,    18,    -1,
      20,    56,    22,    -1,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,   216,   217,    -1,    -1,   220,    -1,    18,
      40,    20,    -1,    22,    -1,    24,    25,    26,    27,    28,
      -1,    30,    31,    32,    -1,    18,    56,    20,    -1,    22,
      39,    24,    25,    26,    27,    28,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    18,    -1,    20,    56,    22,    42,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    -1,
      18,    -1,    20,    56,    22,    39,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    56,    20,    -1,    22,    44,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,    -1,    56,    -1,
      18,    -1,    20,    -1,    22,    42,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    -1,    -1,    -1,    18,    56,
      20,    39,    22,    -1,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    18,    56,    20,
      40,    22,    -1,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    -1,    18,    -1,    20,    56,    22,    39,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    18,    -1,    20,    56,    22,    42,    24,    25,
      26,    27,    28,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    56,    -1,    18,    -1,    20,    -1,    22,    44,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    -1,    -1,
      56,    -1,    -1,    -1,    18,    -1,    20,    -1,    22,    44,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    -1,
      -1,    56,    -1,    -1,    -1,    18,    -1,    20,    -1,    22,
      44,    24,    25,    26,    27,    28,    -1,    30,    31,    32,
      -1,    18,    56,    20,    -1,    22,    39,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      18,    -1,    20,    56,    22,    42,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,    56,
      -1,    18,    -1,    20,    -1,    22,    44,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,    -1,    56,    -1,
      -1,    -1,    18,    -1,    20,    -1,    22,    44,    24,    25,
      26,    27,    28,    -1,    30,    31,    32,    -1,    18,    56,
      20,    -1,    22,    39,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    -1,    -1,    18,    -1,    20,    -1,    22,
      56,    24,    25,    26,    27,    28,    -1,    30,    19,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    56,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    -1,    38,    -1,    -1,
      41,    -1,    -1,    56,    -1,    -1,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    58,    60,    60,     0,    59,    62,    54,    61,
      63,    37,    38,    41,    41,    11,    64,    65,    64,    38,
      70,    42,    39,    42,    40,    55,    45,    11,    55,    70,
      10,    12,    13,    15,    16,    17,    52,    53,    71,    60,
      66,    70,    10,    12,    13,    14,    15,    16,    17,    52,
      53,    72,    43,    62,    46,    55,    45,    60,    47,    54,
      67,    71,    66,    45,    44,    12,    33,    68,    73,    46,
      66,    19,    23,    29,    34,    35,    36,    38,    41,    47,
      48,    49,    50,    51,    56,    80,    81,    82,    83,    84,
      86,    70,     4,     5,     6,     8,    38,    45,    75,    77,
      78,    79,    80,    83,     9,    76,    38,    41,    81,    38,
      80,    41,    43,    85,    80,    38,    41,    18,    20,    22,
      24,    25,    26,    27,    28,    30,    31,    32,    40,    56,
      21,    39,    60,    21,    55,     9,    74,    77,    60,    41,
      60,    43,    60,    67,    39,    21,    39,    80,    46,    43,
      38,    23,    84,    80,    42,    43,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    84,    80,
      80,    60,    80,    71,    80,     5,    41,    80,    41,    80,
      67,    60,    80,    60,    39,    80,    42,    43,    42,    44,
      80,    42,    39,    40,    69,    39,    39,    80,    80,    42,
      38,    78,    83,    44,    73,    60,    44,    80,    44,    60,
      70,    55,    60,    39,    42,    74,    43,    39,    76,    44,
      21,    69,    71,    74,     7,    80,    80,    46,    42,    80,
      39,    74,    44,    39,    60,    69,    60,    78,    42,    74
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
#line 112 "partie2.y"
    { Printtree((yyvsp[(2) - (2)].node)); Analyzer((yyvsp[(2) - (2)].node),globalScope);}
    break;

  case 3:
#line 114 "partie2.y"
    {(yyval.node)=mknode("CODE ",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 6:
#line 121 "partie2.y"
    {
(yyval.node)=mknode("function",
mknode("Main",mknode("\n",NULL,NULL),NULL),
mknode("ARGS",NULL,(yyvsp[(7) - (8)].node)));
}
    break;

  case 7:
#line 125 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 8:
#line 128 "partie2.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 9:
#line 129 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 10:
#line 134 "partie2.y"
    { 
  (yyval.node)=mknode("function",mknode((yyvsp[(2) - (12)].string),mknode("\n",NULL,NULL),mknode("ARGS",(yyvsp[(4) - (12)].node),mknode("return",(yyvsp[(7) - (12)].node),NULL))),mknode("",(yyvsp[(10) - (12)].node),(yyvsp[(11) - (12)].node)));	
}
    break;

  case 11:
#line 138 "partie2.y"
    {
  (yyval.node)=mknode("function",mknode((yyvsp[(2) - (10)].string),mknode("\n",NULL,NULL),NULL),mknode("ARGS",(yyvsp[(4) - (10)].node),(yyvsp[(9) - (10)].node)));
}
    break;

  case 12:
#line 145 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 13:
#line 146 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 14:
#line 148 "partie2.y"
    {(yyval.node)=mknode("(",(yyvsp[(4) - (4)].node),mknode("",(yyvsp[(2) - (4)].node),mknode(")",NULL,NULL)));}
    break;

  case 15:
#line 149 "partie2.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (6)].node),mknode("",(yyvsp[(4) - (6)].node),mknode("(",(yyvsp[(6) - (6)].node),mknode(")",NULL,NULL))));}
    break;

  case 16:
#line 155 "partie2.y"
    {
	(yyval.node)=mknode("(BODY\n    ", mknode("",(yyvsp[(2) - (4)].node),NULL),mknode("",(yyvsp[(3) - (4)].node),mknode("",(yyvsp[(4) - (4)].node),mknode("}",NULL,NULL))));
}
    break;

  case 17:
#line 161 "partie2.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 18:
#line 161 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 19:
#line 165 "partie2.y"
    {
    (yyval.node)=mknode("var", (yyvsp[(4) - (6)].node),(yyvsp[(2) - (6)].node));
}
    break;

  case 20:
#line 169 "partie2.y"
    {
    (yyval.node) = mknode("str", (yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node));
}
    break;

  case 21:
#line 173 "partie2.y"
    {
    (yyval.node) = mknode("str", (yyvsp[(2) - (4)].node), NULL);
}
    break;

  case 22:
#line 177 "partie2.y"
    {
    (yyval.node) = mknode("var" ,mknode("", (yyvsp[(5) - (9)].node),mknode("=", (yyvsp[(2) - (9)].node), (yyvsp[(4) - (9)].node))),(yyvsp[(7) - (9)].node));
}
    break;

  case 23:
#line 182 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 24:
#line 184 "partie2.y"
    {
    (yyval.node) = mknode("var", mknode("=", (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)),(yyvsp[(5) - (5)].node));
}
    break;

  case 25:
#line 187 "partie2.y"
    {
    (yyval.node) = mknode("var", mknode("", (yyvsp[(2) - (3)].node), NULL),(yyvsp[(3) - (3)].node));
}
    break;

  case 26:
#line 195 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (3)].string), mknode(" ", (yyvsp[(3) - (3)].node), NULL),NULL);}
    break;

  case 27:
#line 196 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string), NULL, NULL);}
    break;

  case 28:
#line 200 "partie2.y"
    {(yyval.node)=mknode("bool", NULL, NULL);}
    break;

  case 29:
#line 201 "partie2.y"
    {(yyval.node)=mknode("string", NULL, NULL);}
    break;

  case 30:
#line 202 "partie2.y"
    {(yyval.node)=mknode("char", NULL, NULL);}
    break;

  case 31:
#line 203 "partie2.y"
    {(yyval.node)=mknode("int", NULL, NULL);}
    break;

  case 32:
#line 204 "partie2.y"
    {(yyval.node)=mknode("real", NULL, NULL);}
    break;

  case 33:
#line 205 "partie2.y"
    {(yyval.node)=mknode("int*", NULL, NULL);}
    break;

  case 34:
#line 206 "partie2.y"
    {(yyval.node)=mknode("char*", NULL, NULL);}
    break;

  case 35:
#line 207 "partie2.y"
    {(yyval.node)=mknode("real*", NULL, NULL);}
    break;

  case 36:
#line 212 "partie2.y"
    {(yyval.node)=mknode("boolean", NULL, NULL);}
    break;

  case 37:
#line 213 "partie2.y"
    {(yyval.node)=mknode("string", NULL, NULL);}
    break;

  case 38:
#line 214 "partie2.y"
    {(yyval.node)=mknode("char", NULL, NULL);}
    break;

  case 39:
#line 215 "partie2.y"
    {(yyval.node)=mknode("int", NULL, NULL);}
    break;

  case 40:
#line 216 "partie2.y"
    {(yyval.node)=mknode("real", NULL, NULL);}
    break;

  case 41:
#line 217 "partie2.y"
    {(yyval.node)=mknode("int*", NULL, NULL);}
    break;

  case 42:
#line 218 "partie2.y"
    {(yyval.node)=mknode("char*", NULL, NULL);}
    break;

  case 43:
#line 219 "partie2.y"
    {(yyval.node)=mknode("real*", NULL, NULL);}
    break;

  case 44:
#line 223 "partie2.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 45:
#line 223 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 46:
#line 226 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 47:
#line 226 "partie2.y"
    {(yyval.node)=mknode("return",(yyvsp[(2) - (3)].node),NULL);}
    break;

  case 48:
#line 230 "partie2.y"
    {
	(yyval.node)=mknode("{",(yyvsp[(3) - (7)].node),mknode("", (yyvsp[(4) - (7)].node), mknode("",(yyvsp[(5) - (7)].node),mknode("}",NULL,NULL))));
}
    break;

  case 49:
#line 235 "partie2.y"
    {(yyval.node)=mknode("return",(yyvsp[(2) - (4)].node),NULL);}
    break;

  case 50:
#line 235 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 51:
#line 239 "partie2.y"
    {
	(yyval.node)=mknode("if",
	mknode("(", (yyvsp[(3) - (5)].node), 
	mknode(")",NULL,NULL)),(yyvsp[(5) - (5)].node));
}
    break;

  case 52:
#line 245 "partie2.y"
    {
	(yyval.node)=mknode("if-else",
	mknode("(", (yyvsp[(3) - (7)].node), 
	mknode(")",NULL,NULL)),
	mknode("",(yyvsp[(5) - (7)].node),
	mknode("",(yyvsp[(7) - (7)].node),NULL)));
}
    break;

  case 53:
#line 253 "partie2.y"
    {
	(yyval.node)=mknode("while",
	mknode("(", (yyvsp[(4) - (6)].node), 
	mknode(")",NULL,NULL)),(yyvsp[(6) - (6)].node));
}
    break;

  case 54:
#line 259 "partie2.y"
    {
		(yyval.node)= mknode("for",
			mknode("(",
			mknode("",(yyvsp[(4) - (10)].node),(yyvsp[(6) - (10)].node)),
			mknode("",(yyvsp[(8) - (10)].node),
			mknode(")",NULL,NULL))),(yyvsp[(10) - (10)].node));		
}
    break;

  case 55:
#line 267 "partie2.y"
    {
	(yyval.node)=mknode("do-while",
	mknode("DO", (yyvsp[(2) - (5)].node), 
	mknode(")",NULL,NULL)),
	mknode("WHILE",(yyvsp[(4) - (5)].node),NULL));
}
    break;

  case 56:
#line 273 "partie2.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),NULL);}
    break;

  case 57:
#line 274 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node);}
    break;

  case 58:
#line 275 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 59:
#line 282 "partie2.y"
    {
	(yyval.node)=mknode("=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));
}
    break;

  case 60:
#line 289 "partie2.y"
    {
	(yyval.node)=mknode((yyvsp[(1) - (4)].string), mknode("[",(yyvsp[(3) - (4)].node),mknode("]",NULL,NULL)), NULL);
}
    break;

  case 61:
#line 292 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 62:
#line 293 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 63:
#line 298 "partie2.y"
    {(yyval.node)=mknode("(",(yyvsp[(2) - (3)].node),mknode(")",NULL,NULL));}
    break;

  case 64:
#line 299 "partie2.y"
    {(yyval.node)=mknode("==",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 65:
#line 300 "partie2.y"
    {(yyval.node)=mknode("!=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 66:
#line 301 "partie2.y"
    {(yyval.node)=mknode(">=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 67:
#line 302 "partie2.y"
    {(yyval.node)=mknode(">",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 68:
#line 303 "partie2.y"
    {(yyval.node)=mknode("<=",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 69:
#line 304 "partie2.y"
    {(yyval.node)=mknode("<",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 305 "partie2.y"
    {(yyval.node)=mknode("&&",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 306 "partie2.y"
    {(yyval.node)=mknode("||",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 307 "partie2.y"
    {(yyval.node)=mknode("+",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 308 "partie2.y"
    {(yyval.node)=mknode("-",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 74:
#line 309 "partie2.y"
    {(yyval.node)=mknode("*",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 75:
#line 310 "partie2.y"
    {(yyval.node)=mknode("/",(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 76:
#line 311 "partie2.y"
    {(yyval.node)=mknode("!",(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 77:
#line 312 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 78:
#line 313 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 79:
#line 314 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 80:
#line 315 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),mknode("INT",NULL,NULL),NULL);}
    break;

  case 81:
#line 316 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),mknode("HEX", NULL, NULL),NULL);}
    break;

  case 82:
#line 317 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),mknode("CHAR", NULL, NULL),NULL);}
    break;

  case 83:
#line 318 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),mknode("REAL", NULL, NULL),NULL);}
    break;

  case 84:
#line 319 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),mknode("STRING", NULL, NULL),NULL);}
    break;

  case 85:
#line 320 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),mknode("BOOLEAN", NULL, NULL),NULL);}
    break;

  case 86:
#line 321 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),mknode("BOOLEAN", NULL, NULL),NULL);}
    break;

  case 87:
#line 323 "partie2.y"
    {
		(yyval.node)=mknode("|",
		mknode((yyvsp[(2) - (3)].string),NULL,NULL),
		mknode("|",NULL,NULL));
	}
    break;

  case 88:
#line 329 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (4)].string),mknode("[",(yyvsp[(3) - (4)].node),mknode("]",NULL,NULL)),NULL);}
    break;

  case 89:
#line 330 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (1)].string),NULL,NULL);}
    break;

  case 90:
#line 331 "partie2.y"
    {(yyval.node)=mknode("null",NULL,NULL);}
    break;

  case 91:
#line 335 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 92:
#line 335 "partie2.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 93:
#line 337 "partie2.y"
    {(yyval.node)=mknode("&",mknode((yyvsp[(2) - (2)].string),NULL,NULL),NULL);}
    break;

  case 94:
#line 338 "partie2.y"
    {(yyval.node)=mknode("&",mknode("(",mknode((yyvsp[(3) - (4)].string),NULL,NULL),NULL),mknode(")",NULL,NULL));}
    break;

  case 95:
#line 340 "partie2.y"
    {(yyval.node)=mknode("&", mknode((yyvsp[(2) - (5)].string),NULL,NULL), mknode("[",(yyvsp[(4) - (5)].node),mknode("]",NULL,NULL)));}
    break;

  case 96:
#line 342 "partie2.y"
    {
		(yyval.node)=mknode("&",
		mknode("(", 
		mknode((yyvsp[(3) - (7)].string),NULL,NULL),
		mknode("[",(yyvsp[(5) - (7)].node),NULL)), 
		mknode("]",NULL,mknode(")",NULL,NULL)));
	}
    break;

  case 97:
#line 353 "partie2.y"
    {(yyval.node)=mknode("*",mknode((yyvsp[(2) - (2)].string),NULL,NULL),NULL);}
    break;

  case 98:
#line 354 "partie2.y"
    {(yyval.node)=mknode("*",mknode("(",(yyvsp[(3) - (4)].node),NULL),mknode(")",NULL,NULL));}
    break;

  case 99:
#line 356 "partie2.y"
    {(yyval.node)=mknode((yyvsp[(1) - (5)].string), mknode((yyvsp[(2) - (5)].string),NULL,NULL), mknode("[",(yyvsp[(4) - (5)].node),mknode("]",NULL,NULL)));}
    break;

  case 100:
#line 359 "partie2.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (3)].node),mknode(",",(yyvsp[(3) - (3)].node),NULL));}
    break;

  case 101:
#line 360 "partie2.y"
    {(yyval.node)=mknode("",(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 102:
#line 361 "partie2.y"
    {(yyval.node)=NULL;}
    break;

  case 103:
#line 364 "partie2.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 104:
#line 367 "partie2.y"
    {(yyval.node)=mknode("Call function",mknode((yyvsp[(1) - (2)].string),NULL,NULL),mknode("ARGS",(yyvsp[(2) - (2)].node),NULL));}
    break;


/* Line 1267 of yacc.c.  */
#line 2356 "y.tab.c"
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


#line 368 "partie2.y"



int main()
{
	int res = yyparse();
	if(res==0)
		printf("The Syntax and Semantics Are Valid\n"); 
	return res;	
}

void addVar(Variables * arguments,int countvars,int isArg,SCOPE * TheScope){
	if(countvars==0)
	return;
	Variables* tmp;
	SCOPE * scopes=TheScope;

	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("There is the same var %s in one declare",arguments[i].name);
		SCOPE * t=scopes->preScope;
		while(t->preScope!=NULL && t->preScope->Checkcount==0)
			t=t->preScope;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->Checkcount-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(scopes->var==NULL)
	{ 
		scopes->var=(Variables*) malloc(sizeof(Variables)*countvars);
	}
	else
	{
		tmp=scopes->var;
		scopes->var=(Variables*) malloc(sizeof(Variables)*(scopes->VarCount+countvars));
		for(int i=0;i<scopes->VarCount;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(tmp[i].name,arguments[j].name)==0 )
				{
					printf("There can't be the same var %s in same scope",tmp[i].name);
					SCOPE * t=scopes->preScope;
					while(t->preScope!=NULL && t->preScope->Checkcount==0)
						t=t->preScope;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->Checkcount-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			scopes->var[i]=tmp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{

		scopes->var[scopes->VarCount].name=arguments[j].name;
		scopes->var[scopes->VarCount].value=NULL;
		scopes->var[scopes->VarCount].isArg=isArg;
		scopes->var[scopes->VarCount].len=arguments[j].len;
		scopes->var[(scopes->VarCount)++].type=arguments[j].type;
	}

}


char* getExpType(node* tree, SCOPE* TheScope) {
	{   printf("#####################");

    char* msg = (char*)malloc(sizeof(char) * 7);
    strcpy(msg, "");

    if (strcmp(tree->token, "null") == 0)
        strcpy(msg, "NULL");
    else if (tree->left != NULL) {
        if (strcmp(tree->left->token, "INT") == 0)
            strcpy(msg, "int");
        else if (strcmp(tree->left->token, "HEX") == 0)
            strcpy(msg, "hex");
        else if (strcmp(tree->left->token, "CHAR") == 0)
            strcpy(msg, "char");
        else if (strcmp(tree->left->token, "REAL") == 0)
            strcpy(msg, "real");
        else if (strcmp(tree->left->token, "STRING") == 0)
            strcpy(msg, "string");
        else if (strcmp(tree->left->token, "BOOLEAN") == 0)
            strcpy(msg, "boolean");
        else if (strcmp(tree->token, "!") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), "boolean") == 0)
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can use operator ! only on boolean type");
                exit(1);
            }
        } else if (strcmp(tree->token, "|") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), "string") == 0)
                strcpy(msg, "int");
            else {
                printf("ERROR, you can use operator | only on string type in the function %s", globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "==") == 0 || strcmp(tree->token, "!=") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->right, TheScope), "string") != 0)
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, ">=") == 0 || strcmp(tree->token, ">") == 0 || strcmp(tree->token, "<=") == 0 || strcmp(tree->token, "<") == 0) {
            if ((strcmp(getExpType(tree->left, TheScope), "int") == 0 || strcmp(getExpType(tree->left, TheScope), "real") == 0) && (strcmp(getExpType(tree->right, TheScope), "int") == 0 || strcmp(getExpType(tree->right, TheScope), "real") == 0))
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "&&") == 0 || strcmp(tree->token, "||") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->right, TheScope), "boolean") == 0)
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "-") == 0 || strcmp(tree->token, "+") == 0) {
            if ((strcmp(getExpType(tree->left, TheScope), "int") == 0 || strcmp(getExpType(tree->left, TheScope), "real") == 0) && (strcmp(getExpType(tree->right, TheScope), "int") == 0 || strcmp(getExpType(tree->right, TheScope), "real") == 0)) {
                if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->left, TheScope), "int") == 0)
                    strcpy(msg, "int");
                else
                    strcpy(msg, "real");
            } else if (strcmp(getExpType(tree->right, TheScope), "int") == 0 && (strcmp(getExpType(tree->left, TheScope), "char*") == 0 || strcmp(getExpType(tree->right, TheScope), "int*") == 0 || strcmp(getExpType(tree->right, TheScope), "real*") == 0)) {
                strcpy(msg, getExpType(tree->left, TheScope));
            } else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "*") == 0 || strcmp(tree->token, "/") == 0) {
            if ((strcmp(getExpType(tree->left, TheScope), "int") == 0 || strcmp(getExpType(tree->left, TheScope), "real") == 0) && (strcmp(getExpType(tree->right, TheScope), "int") == 0 || strcmp(getExpType(tree->right, TheScope), "real") == 0)) {
                if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->left, TheScope), "int") == 0)
                    strcpy(msg, "int");
                else
                    strcpy(msg, "real");
            } else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "&") == 0) {
            if (strcmp(tree->left->token, "(") == 0)
                strcpy(msg, getExpType(tree->left->left, TheScope));
            else {
                strcpy(msg, getExpType(tree->left, TheScope));
            }
            if (strcmp(msg, "char") == 0)
                strcpy(msg, "char*");
            else if (strcmp(msg, "int") == 0)
                strcpy(msg, "int*");
            else if (strcmp(msg, "real") == 0)
                strcpy(msg, "real*");
            else {
                printf("ERROR, you can't use %s on %s \n", tree->token, msg);
                exit(1);
            }
        } else if (strcmp(tree->token, "*") == 0) {
            if (strcmp(tree->left->token, "(") == 0)
                strcpy(msg, getExpType(tree->left->left, TheScope));
            else
                strcpy(msg, getExpType(tree->left, TheScope));

            if (strcmp(msg, "char*") == 0)
                strcpy(msg, "char");
            else if (strcmp(msg, "int*") == 0)
                strcpy(msg, "int");
            else if (strcmp(msg, "real*") == 0)
                strcpy(msg, "real");
            else {
                printf("ERROR, you can't use %s on %s \n", tree->token, msg);
                exit(1);
            }
        } else if (strcmp(tree->token, "(") == 0)
            strcpy(msg, getExpType(tree->left, TheScope));
        else if (strcmp(tree->token, "Call function") == 0)
            strcpy(msg, findFuncInScopes(tree, TheScope));
    }
    if (strcmp(msg, "") == 0)
        strcpy(msg, findVar(tree, TheScope));

    return msg;
}

SCOPE* mkScope(char* name)
{   
    SCOPE* newScope = (SCOPE*)malloc(sizeof(SCOPE));
    newScope->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(newScope->name, name);
    newScope->var = NULL;
    newScope->VarCount = 0;
    newScope->func = NULL;
    newScope->Checkcount = 0;
    newScope->nextScope = NULL;
    newScope->preScope = NULL;
    return newScope;
}

void addFunc(char * name,Variables * arguments,node *returnType,int argNum,SCOPE * TheScope){
	Function** tmp;
	SCOPE * scopes = TheScope;
	for(int i=0;i<argNum;i++)
		for(int j=0;j<argNum;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("ERROR, there are identicles arguments %s in func %s\n",arguments[i].name,name);
		exit(1);
	}
	if(scopes->func==NULL)
	{ 
		scopes->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		tmp=scopes->func;
		scopes->func=(Function**) malloc(sizeof(Function*)*(scopes->Checkcount+1));
		for(int i=0;i<scopes->Checkcount;i++)
		{
				if(strcmp(tmp[i]->name,name)==0 )
				{
					printf("ERROR, there's already function %s in same scope \n",tmp[i]->name);
					exit(1);
				}
				scopes->func[i]=tmp[i];
		}
	}
		scopes->func[scopes->Checkcount]=(Function*) malloc(sizeof(Function));
		scopes->func[scopes->Checkcount]->name=name;
		scopes->func[scopes->Checkcount]->arguments=arguments;
		if(returnType==NULL)
		scopes->func[scopes->Checkcount]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type function %s can't be string\n",name);
				exit(1);
			}
		scopes->func[scopes->Checkcount]->returnType=returnType->token;
		}
		scopes->func[scopes->Checkcount]->argNum=argNum;
		scopes->func[scopes->Checkcount]->findreturn=false;
		++(scopes->Checkcount); 

}



node* mknode(char* token, node* left, node* right)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->left = left;
    newnode->right = right;
    newnode->token = token;
    return newnode;
}


void printTabs(int n)
{
	int i;
	for(i=0;i<n/9;i++)
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

SCOPE* findScope(SCOPE * scopes){
	SCOPE * TheScope=scopes;
	if(TheScope!=NULL)
	while(TheScope->nextScope!=NULL)
		TheScope=TheScope->nextScope;
	return TheScope;
}


void Analyzer(node *tree,SCOPE * TheScope){
	int flagNew=0;
	if(strcmp(tree->token, "=") == 0 )
	{
		if(!(strcmp(getExpType(tree->right,TheScope),"NULL")==0&& (strcmp(getExpType(tree->left,TheScope),"real*")==0||strcmp(getExpType(tree->left,TheScope),"int*")==0||strcmp(getExpType(tree->left,TheScope),"char*")==0)))
		if(strcmp(getExpType(tree->left,TheScope),getExpType(tree->right,TheScope))!=0)
		{
			printf("ERORR, you can't do = between %s and %s in scope %s in the function %s\n",getExpType(tree->left,TheScope),getExpType(tree->right,TheScope),TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int VarCount=0;
		Variables * var=mkArguments(tree,&VarCount);
		addVar(var,VarCount,0,TheScope);
		
		
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(getExpType(tree->left->left,TheScope),"boolean")!=0)
		{
			printf("ERROR, the condition in if statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(TheScope,tree->token);
			if (tree->left) 
				Analyzer(tree->left,findScope( TheScope->nextScope));
	
			if (tree->right)
				Analyzer(tree->right,findScope( TheScope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(getExpType(tree->left->left,TheScope),"boolean")!=0)
		{
			printf("ERROR, the condition in while statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(TheScope,tree->token);
			if (tree->left) 
				Analyzer(tree->left,findScope( TheScope->nextScope));
	
			if (tree->right)
				Analyzer(tree->right,findScope( TheScope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{

	 if(strcmp(getExpType(tree->left->left->right,TheScope),"boolean")!=0)
		{
			printf("ERROR, the condition in for statement has to be boolean\n");
			exit(1);
		}

		Analyzer(tree->left->left->left,TheScope);

		Analyzer(tree->left->right->left,TheScope);

		if(strcmp(tree->right->token,"{")!=0)
		{

			pushScopes(TheScope,tree->token);

			if (tree->left) 
				Analyzer(tree->left,findScope( TheScope->nextScope));
	
			if (tree->right)
				Analyzer(tree->right,findScope( TheScope->nextScope));
        	scope--;
			return;
		}

		
		
	}
	else if(strcmp(tree->token, "function") == 0)
	{
        int count=0;
		Variables * arg=mkArguments(tree->left->right->left,&count);
		addFunc(tree->left->token,arg,tree->left->right->right->left,count,TheScope);
		pushScopes(TheScope,tree->token);
		addVar(arg,count,1,findScope(TheScope));
	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));

	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
		if(TheScope->func[TheScope->Checkcount-1]->findreturn==false)
		{
			printf("ERORR, there is no Return in func %s\n",tree->left->token); // ######## GALIT: here it's the problem
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "function") == 0)
	{
		
        int count=0;
		Variables * arg=mkArguments(tree->right->left,&count);
		addFunc(tree->left->token,arg,NULL,count,TheScope);
		pushScopes(TheScope,tree->token);
		addVar(arg,count,1,findScope(TheScope));
	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));
	
	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
		scope--;	
		return;
    }


	else if(strcmp(tree->token, "Call function") == 0)
	{
		findFuncInScopes(tree,TheScope);
		//printf("(%s \n",tree->token);
		
		
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{
		pushScopes(NULL,tree->token);
	if (tree->left) 
		Analyzer(tree->left,globalScope);
	
	if (tree->right)
		Analyzer(tree->right,globalScope);
		scope--;
		return;
	}

    else if(strcmp(tree->token, "Main") == 0)
	{
		addFunc(tree->token,NULL,NULL,0,TheScope);
		pushScopes(TheScope,tree->token);

	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));
	
	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
        scope--;
		return;
               
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(getExpType(tree->left->left,TheScope),"boolean")!=0)
		{
			printf("ERORR, if condition must be of type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->left->token,"{")!=0)
		{
			pushScopes(TheScope,tree->token);
			Analyzer(tree->right->left,findScope( TheScope->nextScope));
			scope--;
			pushScopes(TheScope,tree->token);
			Analyzer(tree->right->right->left,findScope( TheScope->nextScope));
        	scope--;
			return;
		}
	}

	else if(strcmp(tree->token, "return") == 0)
	{
		SCOPE * tmp= TheScope;
		int flag=true;
		while(strcmp(tmp->name,"function")!=0&&strcmp(tmp->name,"PROC")!=0&&strcmp(tmp->name,"CODE")!=0)
		{
			tmp=tmp->preScope;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType))
			{
			printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
			printf("%s ,%s %s\n",getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType,tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
			exit(1);
			}
		}
		else
		{
			if (strcmp(tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType, "void")==0) 
				flagNew=1; 
			if(tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType!=NULL && flagNew==0)
			{
				if(0==strcmp(getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType))
				{
					tmp->preScope->func[tmp->preScope->Checkcount-1]->findreturn=true;
				}
				else 
				{
					printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
					printf("%s ,%s %s\n",getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType,tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
					exit(1);
				}
			}
			else
			{
				printf("ERORR, there can't be return in function '%s', because it's void type\n",tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
				exit(1);
			}  
		}  
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    pushScopes(TheScope,tree->token);
	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));
	
	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
        scope--;
		return;			
	}
	else if(strcmp(tree->token, "solovar") == 0 )
	{
		findVar(tree->left,TheScope);
	}
	if (tree->left) 
		Analyzer(tree->left,TheScope);
	
	if (tree->right)
		Analyzer(tree->right,TheScope);
}


void pushScopes(SCOPE* from,char* name)
{
	SCOPE * point;
	if(globalScope==NULL)
		globalScope=mkScope(name);
	else{
	point=globalScope;
	while(point->nextScope!=NULL)
		point=point->nextScope;
	point->nextScope=mkScope(name);
	point->nextScope->preScope=from;
	}
}

char* findFuncInScopes(node * tree,SCOPE * TheScope)
{
	SCOPE* tmp=TheScope;
	Variables* arguments;
	bool find = false, flag = true;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->Checkcount;i++)
		if(strcmp(tree->left->token,tmp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			arguments=callFuncArguments(TheScope,tree->right->left,&count);
			if(count==tmp->func[i]->argNum)
			{
				for(int j=0,t=count-1;j<count;j++,t--)
				{
					if(strcmp(arguments[j].type,tmp->func[i]->arguments[t].type)!=0)
						flag=false;
				}
				if(flag==true)
					return tmp->func[i]->returnType;
			}
		}
		tmp=tmp->preScope;
	}
	printf("ERROR,func %s not find call in scope %s in the function %s\n",tree->left->token,TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
	if(find==true)
		printf("There is a function with the same name that accepts different arguments\n");
		exit(1);
}

char *findVar(node * tree,SCOPE * TheScope)
{
	SCOPE* tmp = TheScope;
	if(strcmp(tree->token,"solovar")==0)
		tree=tree->left;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->VarCount;i++)
		if(strcmp(tree->token,tmp->var[i].name)==0)
		{
			
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(tmp->var[i].type,"string")==0)
					if(strcmp(getExpType(tree->left->left,TheScope),"int")==0)
					{
						return "char";
					}
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in the function %s\n",TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) in scope %s in the function %s\n",TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
					exit(1);
				}

			}
			else
			return tmp->var[i].type;

		}
		tmp=tmp->preScope;
	}
	printf("ERORR, var %s wasn't found in scope %s in the function %s\n ",tree->token,TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
	exit(1);	
}

Variables * mkArguments(node *tree,int *count){
	Variables  *arr=NULL,arr2[50];
	char* type, *len ;
	if(tree!=NULL)
	{
		node * temp1=tree,*tmp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			tmp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
			{
				type=tmp->left->token;
				if(tmp->left->left!=NULL)
					len=tmp->left->left->left->token;
				node * tmptree;
				tmptree=tmp->right->left;
				do{
				arr2[*count].name=tmptree->token;
				arr2[*count].type=type;
				arr2[*count].len=len;
				(*count)++;
				if(tmptree->left==NULL)
					tmptree=NULL;
				else
					tmptree=tmptree->left->left;
				}while(tmptree!=NULL);
			}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(tmp->token, "var")!=0);
		tmp=temp1;
		if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
		{
			type=tmp->left->token;
			node * tmptree;
			if(strcmp(tmp->token, "var")==0)
			tmptree=tmp->right;
			else
			tmptree=tmp->right->left;
			if(tmp->left->left!=NULL)
			len=tmp->left->left->left->token;
			do{
			arr2[*count].name=tmptree->token;
			arr2[*count].type=type;
			arr2[*count].len=len;
			(*count)++;
			if(tmptree->left==NULL)
				tmptree=NULL;
			else
				tmptree=tmptree->left->left;
			}while(tmptree!=NULL);
		}
		arr=(Variables*)malloc(sizeof(Variables)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=arr2[i].name;
			arr[i].type=arr2[i].type;
		}
	}
	return arr;
}


Variables* callFuncArguments(SCOPE * TheScope,node *tree,int * count)
{
	Variables  *arr=NULL,arr2[50];
	char* type,*len;
	while(tree!=NULL)
	{
	arr2[*count].type = getExpType(tree->left, TheScope);
	(*count)++;
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;

	}
	arr=(Variables*)malloc(sizeof(Variables)*(*count));
	for(int i = 0; i<*count; i++)
		arr[i].type=arr2[i].type;
	return arr;
}

