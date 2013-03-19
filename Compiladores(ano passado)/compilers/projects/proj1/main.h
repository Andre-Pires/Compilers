/*****************************
	Compilers, Spring 2009
	IST-TagusPark

  miniC compiler;
	header: "main.h"

  --------------------------
	Nuno AJ de Aniceto
	nº 57682
  --------------------------
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
typedef struct {
	int ln;						/* line number    */
	YY_BUFFER_STATE buffer;		/* lexer's buffer */
} lbuffer;

#ifndef MAIN_H
#define MAIN_H

#define MAX_INCLUDES 10
#define YYTEXT_TO_INT		{ return (int) yytext[0]; }

	/* miniC principal IR tokens */
	#define IDENTIFIER			257
	#define CONSTANT			258
	#define SIZEOF				259
	#define PTR_OP				260
	#define DOT_OP				261
	#define GT_OP				262
	#define LT_OP				263
	#define GE_OP				264
	#define LE_OP				265
	#define NE_OP				266
	#define EQ_OP				267
	#define AND_OP				268
	#define OR_OP				269
	#define TYPEDEF				270
	#define INT					271
	#define CHAR				272
	#define VOID				273
	#define STRUCT				274
	#define IF					275
	#define ELSE				276
	#define WHILE				277
	#define RETURN				278

	/* single tokens */
	#define AND_LG				38		/*/  &  */
	#define P_OPEN				40		/*/  (  */
	#define P_CLOSE				41		/*/  )  */
	#define MULT_OP				42		/*/  *  */
	#define ADD_OP				43		/*/  +  */
	#define SUB_OP				45		/*/  -  */
	#define DIV_OP				47		/*/  /  */
	#define SEMICOLON			59		/*/  ;  */
	#define EQ_SET				61		/*/  =  */
	#define RP_OPEN				91		/*/  [  */
	#define RP_CLOSE			93		/*/  ]  */
	#define BRACKET_OP			123		/*/  {  */
	#define BRACKET_CL			125		/*/  }  */
	#define TILDE				126		/*/  ~  */

#endif
