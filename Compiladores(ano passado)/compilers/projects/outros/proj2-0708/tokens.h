/*****************************
   Compilers, Spring 2008
   IST-TagusPark
  
   Project2: header
  file "tokens.h"
  
  --------------------------
    Nuno AJ de Aniceto
    nº 57682
  --------------------------
*****************************/

#ifndef TOKENS_HEADER
#define TOKENS_HEADER
    
    /* tokens */
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
    #define IF_PREC 286
    #define FUNCTION 279
    #define DECLARATION 280
    #define TYPE_SPECIFIER 281
    #define DECLARATOR 282
    #define FUNCTION_DEFINITION 283
    #define TYPEDEF_STRUCT 284
    #define STRUCT_DECL_LIST 285
    #define DIRECT_DECL 286
    #define ARRAY_DECL 287
    #define PARAM 288
    #define COMPOUND 289
    #define DECL 290
    #define STATE 291
    #define NEG 292
    #define AST 293
    #define FUNC 294
    #define EXPR_LIST 295
    #define PROGRAM 296
    #define EXPR 297
    #define C_STATE 298
    
    /* generic "single-char" tokens */
    #define YYTEXT_TO_INT { return (int) yytext[0]; }

    typedef union {
      int i;
      char* s;
      struct typeNode *n;
    } YYSTYPE;
    extern YYSTYPE yylval;

/*** The End ***/

#endif
