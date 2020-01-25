/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MULOP = 258,
    BITOP = 259,
    RELOP = 260,
    ADDOP = 261,
    LOGICOP = 262,
    CONST_CHAR = 263,
    ID = 264,
    CONST_INT = 265,
    CONST_FLOAT = 266,
    STRING = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    WHILE = 271,
    DO = 272,
    BREAK = 273,
    INT = 274,
    CHAR = 275,
    FLOAT = 276,
    DOUBLE = 277,
    VOID = 278,
    RETURN = 279,
    SWITCH = 280,
    CASE = 281,
    DEFAULT = 282,
    CONTINUE = 283,
    LPAREN = 284,
    RPAREN = 285,
    LCURL = 286,
    RCURL = 287,
    LTHIRD = 288,
    RTHIRD = 289,
    COMMA = 290,
    SEMICOLON = 291,
    INCOP = 292,
    DECOP = 293,
    ASSIGNOP = 294,
    NOT = 295,
    PRINTLN = 296,
    LOWER_THAN_ELSE = 297
  };
#endif
/* Tokens.  */
#define MULOP 258
#define BITOP 259
#define RELOP 260
#define ADDOP 261
#define LOGICOP 262
#define CONST_CHAR 263
#define ID 264
#define CONST_INT 265
#define CONST_FLOAT 266
#define STRING 267
#define IF 268
#define ELSE 269
#define FOR 270
#define WHILE 271
#define DO 272
#define BREAK 273
#define INT 274
#define CHAR 275
#define FLOAT 276
#define DOUBLE 277
#define VOID 278
#define RETURN 279
#define SWITCH 280
#define CASE 281
#define DEFAULT 282
#define CONTINUE 283
#define LPAREN 284
#define RPAREN 285
#define LCURL 286
#define RCURL 287
#define LTHIRD 288
#define RTHIRD 289
#define COMMA 290
#define SEMICOLON 291
#define INCOP 292
#define DECOP 293
#define ASSIGNOP 294
#define NOT 295
#define PRINTLN 296
#define LOWER_THAN_ELSE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 85 "1505080.y" /* yacc.c:1909  */

	SymbolInfo *symbolInfoVar;

#line 142 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
