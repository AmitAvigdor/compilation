/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "partie1.y"
{
	int i;
    struct node *node;
    char *string;
}
/* Line 1529 of yacc.c.  */
#line 167 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

