
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     TYPEDEF = 260,
     INT = 261,
     CHAR = 262,
     VOID = 263,
     STRUCT = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     RETURN = 268,
     SIZEOF = 269,
     COMMA = 270,
     SEMICOLON = 271,
     PTR_OP = 272,
     LT_OP = 273,
     GT_OP = 274,
     LE_OP = 275,
     GE_OP = 276,
     ARRAY_OP = 277,
     NE_OP = 278,
     EQ_OP = 279,
     AND_OP = 280,
     OR_OP = 281,
     ADD_OP = 282,
     SUB_OP = 283,
     MULT_OP = 284,
     DIV_OP = 285,
     STRUCT_DECL_LIST = 286,
     COMPOUND = 287,
     STATE = 288,
     FUNCTION = 289,
     DECLARATION = 290,
     FUNCTION_DEFINITION = 291,
     PROGRAM = 292,
     EXPR_LIST = 293,
     TYPE_SPECIFIER = 294,
     DIRECT_DECL = 295,
     PARAM = 296,
     NEG = 297,
     EXPR = 298,
     TOPLD = 299,
     VALUE = 300,
     DECL = 301,
     DECLARATOR = 302,
     ARRAY_DECL = 303,
     IF_ELSE = 304,
     PARAM_FUNCTION = 305,
     TYPED_STR_ID = 306,
     TYPED_STR = 307
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define TYPEDEF 260
#define INT 261
#define CHAR 262
#define VOID 263
#define STRUCT 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define RETURN 268
#define SIZEOF 269
#define COMMA 270
#define SEMICOLON 271
#define PTR_OP 272
#define LT_OP 273
#define GT_OP 274
#define LE_OP 275
#define GE_OP 276
#define ARRAY_OP 277
#define NE_OP 278
#define EQ_OP 279
#define AND_OP 280
#define OR_OP 281
#define ADD_OP 282
#define SUB_OP 283
#define MULT_OP 284
#define DIV_OP 285
#define STRUCT_DECL_LIST 286
#define COMPOUND 287
#define STATE 288
#define FUNCTION 289
#define DECLARATION 290
#define FUNCTION_DEFINITION 291
#define PROGRAM 292
#define EXPR_LIST 293
#define TYPE_SPECIFIER 294
#define DIRECT_DECL 295
#define PARAM 296
#define NEG 297
#define EXPR 298
#define TOPLD 299
#define VALUE 300
#define DECL 301
#define DECLARATOR 302
#define ARRAY_DECL 303
#define IF_ELSE 304
#define PARAM_FUNCTION 305
#define TYPED_STR_ID 306
#define TYPED_STR 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 47 "yacc2.y"

      int i;
      char* s;
      struct typeNode *n;
    


/* Line 1676 of yacc.c  */
#line 164 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


