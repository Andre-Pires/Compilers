
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
     SIZEOF = 260,
     PTR_OP = 261,
     ARRAY_OP = 262,
     GT_OP = 263,
     LT_OP = 264,
     GE_OP = 265,
     LE_OP = 266,
     NE_OP = 267,
     EQ_OP = 268,
     AND_OP = 269,
     OR_OP = 270,
     INC_OP = 271,
     DEC_OP = 272,
     LEFT_OP = 273,
     RIGHT_OP = 274,
     EQ_ASSIGN = 275,
     RIGHT_ASSIGN = 276,
     LEFT_ASSIGN = 277,
     ADD_ASSIGN = 278,
     SUB_ASSIGN = 279,
     MUL_ASSIGN = 280,
     DIV_ASSIGN = 281,
     MOD_ASSIGN = 282,
     AND_ASSIGN = 283,
     XOR_ASSIGN = 284,
     OR_ASSIGN = 285,
     TYPEDEF = 286,
     INT = 287,
     FLOAT = 288,
     CHAR = 289,
     VOID = 290,
     STRUCT = 291,
     IF = 292,
     ELSE = 293,
     WHILE = 294,
     RETURN = 295,
     ECM = 296,
     MUL = 297,
     DIV = 298,
     PERCENT = 299,
     TIL = 300,
     SUM = 301,
     SUB = 302,
     BANG = 303,
     STRING = 304,
     FUNCTION = 305,
     DECLARATION = 306,
     TYPE_SPECIFIER = 307,
     DECLARATOR = 308,
     FUNCTION_DEFINITION = 309,
     TYPEDEF_STRUCT = 310,
     STRUCT_DECL_LIST = 311,
     DIRECT_DECL = 312,
     ARRAY_DECL = 313,
     PARAM = 314,
     COMPOUND = 315,
     DECL = 316,
     STATE = 317,
     NEG = 318,
     AST = 319,
     FUNC = 320,
     EXP_LIST = 321,
     ASSIGN_LIST = 322,
     UNARY_EXP = 323,
     SIZEOF_EXP = 324,
     SIZEOF_TYPE = 325,
     CAST_EXP = 326,
     AR_EXP = 327,
     SHIFT_EXP = 328,
     REL_OP_EXP = 329,
     EQ_OP_EXP = 330,
     NE_OP_EXP = 331,
     AND_OP_EXP = 332,
     EXCLOR_OP_EXP = 333,
     INCLOR_OP_EXP = 334,
     COND_EXP = 335,
     ASSIGN_EXP = 336,
     PROGRAM = 337,
     EXP = 338,
     C_STATE = 339,
     IF_PREC = 340
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define SIZEOF 260
#define PTR_OP 261
#define ARRAY_OP 262
#define GT_OP 263
#define LT_OP 264
#define GE_OP 265
#define LE_OP 266
#define NE_OP 267
#define EQ_OP 268
#define AND_OP 269
#define OR_OP 270
#define INC_OP 271
#define DEC_OP 272
#define LEFT_OP 273
#define RIGHT_OP 274
#define EQ_ASSIGN 275
#define RIGHT_ASSIGN 276
#define LEFT_ASSIGN 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define MUL_ASSIGN 280
#define DIV_ASSIGN 281
#define MOD_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define TYPEDEF 286
#define INT 287
#define FLOAT 288
#define CHAR 289
#define VOID 290
#define STRUCT 291
#define IF 292
#define ELSE 293
#define WHILE 294
#define RETURN 295
#define ECM 296
#define MUL 297
#define DIV 298
#define PERCENT 299
#define TIL 300
#define SUM 301
#define SUB 302
#define BANG 303
#define STRING 304
#define FUNCTION 305
#define DECLARATION 306
#define TYPE_SPECIFIER 307
#define DECLARATOR 308
#define FUNCTION_DEFINITION 309
#define TYPEDEF_STRUCT 310
#define STRUCT_DECL_LIST 311
#define DIRECT_DECL 312
#define ARRAY_DECL 313
#define PARAM 314
#define COMPOUND 315
#define DECL 316
#define STATE 317
#define NEG 318
#define AST 319
#define FUNC 320
#define EXP_LIST 321
#define ASSIGN_LIST 322
#define UNARY_EXP 323
#define SIZEOF_EXP 324
#define SIZEOF_TYPE 325
#define CAST_EXP 326
#define AR_EXP 327
#define SHIFT_EXP 328
#define REL_OP_EXP 329
#define EQ_OP_EXP 330
#define NE_OP_EXP 331
#define AND_OP_EXP 332
#define EXCLOR_OP_EXP 333
#define INCLOR_OP_EXP 334
#define COND_EXP 335
#define ASSIGN_EXP 336
#define PROGRAM 337
#define EXP 338
#define C_STATE 339
#define IF_PREC 340




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 50 "parser.y"

    struct{
	int warn;
	unsigned short int type;
	char* id;
    } node;



/* Line 1676 of yacc.c  */
#line 232 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


