#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "factorial.y"
/* Para testar apenas o lex, deve ter um yacc mínimo para gerar o y.tab.h
   Basta definir os tokens necessários à linguagem a testar (%token).
   Também a rotina main() deve chamar apenas o lex (yylex()).
   Devemos igualmente fornecer uma rotina de impressão de erros yyerror.
   A gramática é vazia (file: ;) pelo que só reconhece a linguagem vazia, não devendo ser chamado o analisador sintáctico do yacc (yyparse()).

Compilar com:
byacc -dv solex.y
flex -dl lang.l
gcc lex.yy.c y.tab.c

Executar os exemplos (apenas com redirecção):
./lang < exemplo.lang

Para garantir que as expressões regulares reconhecem correctamente as sequências de entrada deve adicionar o modo debug (-d) ao flex.
Ao executar os diversos exemplos deve verificar quais as expressões regulares que as reconhecem cada uma das sequências de entrada.
As expressões regulares são Identificadas pelo número da linha em que se encontram no ficheiro lex.
*/   
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include "lib/node.h"
#include "lib/tabid.h"

#line 29 "factorial.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
  double d;    /* double value */
	char *s;		/* symbol name or string literal */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 58 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define INT 257
#define NUM 258
#define IDENTIF 259
#define STRN 260
#define WHILE 261
#define IF 262
#define END 263
#define RETURN 264
#define VOID 265
#define PUBLIC 266
#define CONST 267
#define THEN 268
#define ELSE 269
#define DO 270
#define FOR 271
#define IN 272
#define STEP 273
#define UPTO 274
#define DOWNTO 275
#define BREAK 276
#define CONTINUE 277
#define INTEGER 278
#define STRING 279
#define NUMBER 280
#define GE 281
#define LE 282
#define EQ 283
#define NE 284
#define INC 285
#define DEC 286
#define ATRIB 287
#define ADDR 288
#define POINTER 289
#define IFX 290
#define UMINUS 291
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    3,    3,    3,    3,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    7,    7,    5,    5,    8,    8,    9,
    9,    6,    6,    6,    6,   10,   10,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   14,
   14,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   13,   13,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    6,    5,    7,    6,    5,    4,
    6,    5,    5,    4,    6,    5,    4,    3,    5,    4,
    1,    1,    1,    1,    2,    3,    2,    2,    2,    4,
    3,    3,    2,    2,    3,    1,    2,    2,    3,    2,
    3,    2,    3,    3,    4,    1,    2,    4,    6,    4,
    8,    8,   10,   10,    2,    1,    3,    3,    4,    3,
    1,    1,    1,    1,    1,    4,    3,    3,    2,    2,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    1,    4,
};
static const short yydefred[] = {                         0,
   24,    0,    0,   21,   22,   23,    0,    0,    3,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,    0,    0,    0,    0,   17,    0,
    0,   20,    0,    0,   29,    0,   25,   27,   28,    0,
    0,    0,    0,   10,   14,    0,   19,    0,    0,    9,
   13,    0,   12,   16,    0,   26,    0,   32,   38,    0,
    0,    0,    0,    6,   11,   15,    0,    5,    8,   62,
   63,    0,   64,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,   56,    0,    0,    0,
   46,    0,    0,   39,   30,   34,    0,    7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   70,   71,   89,
    0,   69,   90,    0,   40,   43,    0,    0,   44,   47,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   88,   55,   72,   73,    0,    0,   35,
    0,    0,    0,    0,    0,    0,   57,   58,   67,   41,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   66,    0,   92,    0,
   50,    0,   59,    0,    0,    0,    0,   49,    0,    0,
    0,    0,    0,    0,   51,    0,   52,    0,    0,    0,
   53,   54,
};
static const short yydgoto[] = {                          7,
    8,    9,   41,   25,   42,   87,   63,   43,   89,   90,
   91,   92,  102,  142,
};
static const short yysindex[] = {                      -125,
    0, -135, -171,    0,    0,    0,    0, -125,    0,  -35,
 -171,  -26,  -20,    0,  -27, -244,    7,  -23, -238,  -12,
 -228, -153,    9,    0,  -22,    5,   14, -226,    0,  -13,
   15,    0,   -8,   37,    0, -218,    0,    0,    0,  -70,
   38,   24,   27,    0,    0,   19,    0,   22,   46,    0,
    0,   23,    0,    0,   30,    0,  562,    0,    0, -164,
  -70, -171,   59,    0,    0,    0,   40,    0,    0,    0,
    0,  -39,    0,  514,  514, -149, -167, -166, -149, -149,
 -149,  514,  514, -149,  514,    0,    0,   54,  592,  633,
    0,  130,  -29,    0,    0,    0, -171,    0,  514,  514,
  158, -267,  280,   29, -156,   63,   75,    0,    0,    0,
  532,    0,    0,  386,    0,    0,   76,  663,    0,    0,
  514,  514,  514,  514,  514,  514,  514,  514,  514,  514,
  514,  514,  514,    0,    0,    0,    0,  514,  514,    0,
  495,  -21,  343,  753,  753,  514,    0,    0,    0,    0,
    0,  169,  169,  184,  184,  315,  532,  169,  169,  151,
  151,  103,  103,  103,  412,  495,    0,  514,    0, -132,
    0,   55,    0,  495,  753,  514,  514,    0,   86,  114,
  753,  514,  753,  514,    0,  442,    0,  458,  753,  753,
    0,    0,
};
static const short yyrindex[] = {                       138,
    0,    0,    0,    0,    0,    0,    0,  139,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   91,
    0,    0,  117,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  101,    0,  121,    0,    0,    0,    0,    0,    0,    0,
    0,  -33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  484,    0,    0,    0,    0,    0,    0,    0,
    0,   25,    0,   -3,    0,    0,    0,    0,    0,    0,
  638,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   35,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  957, 1093,  613, 1119, 1144, 1347, 1160, 1204, 1050,
 1076,  909,  999, 1025,    0, 1185,    0,    0,    0,  705,
    0,    0,    0,   60,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,  156,  363,  285,    0,  -37,    0,  -14,    0,   77,
  546, 1416, 1413,    0,
};
#define YYTABLESIZE 1622
static const short yytable[] = {                         91,
   99,   91,   58,   91,   91,  138,   16,   91,   91,   91,
   91,   91,   23,   91,   26,   19,   23,  136,  137,  167,
   31,   21,  168,   95,  139,   91,   91,   23,   91,   91,
   34,   24,   49,   91,   91,   29,   44,   91,   91,   91,
   91,   91,   88,   91,   23,   50,   32,   96,   28,   40,
   53,  100,   57,   23,   23,   91,   91,   65,   91,   91,
   56,   65,   65,   45,   61,   65,   65,   65,   65,   65,
   62,   65,   47,   51,  117,   61,   23,   64,   61,   60,
   65,   68,  140,   65,   65,   23,   65,  134,   69,   91,
   91,  133,  126,    1,   94,   54,  131,  129,   98,  130,
   60,  132,   97,   60,   66,   35,    4,    5,    6,  104,
  106,  107,  115,   36,  128,  146,  127,   65,  134,  100,
   91,  147,  133,  126,   37,   38,   39,  131,  129,    1,
  130,   11,  132,  148,  150,  134,  175,    2,    1,    1,
    2,    3,    4,    5,    6,  128,  134,  127,   65,   33,
  133,  126,    4,    5,    6,  131,  129,   36,  130,   31,
  132,   37,  134,   14,    0,  118,  133,  126,    0,    0,
    0,  131,  129,  128,  130,  127,  132,    0,  125,    0,
    0,    0,    0,  134,    0,    0,    0,  133,  135,  128,
  134,  127,  131,    0,  133,  126,    0,  132,    0,  131,
  129,  134,  130,    0,  132,  133,    0,    0,    0,  125,
  131,  129,    0,  130,    0,  132,  134,  128,    0,  127,
  133,    0,    0,   15,    0,  131,  129,   91,  130,    0,
  132,    0,   18,    0,   91,    0,   91,  125,   20,   91,
   91,   91,    0,  128,    0,  127,    0,   91,   91,   91,
   91,   91,   91,  125,    0,  136,  137,   91,   91,   22,
    0,    0,  139,   22,   91,   27,   91,    0,   91,   91,
   91,   91,    0,    1,   22,    0,    0,   91,   91,   91,
   91,  125,    0,    0,    0,   65,    4,    5,    6,    0,
    0,   22,   65,    0,   65,    0,   59,   65,   65,   65,
   22,   22,   30,    0,   33,   65,   65,   65,   65,    0,
   46,   48,  134,    0,    0,   52,  133,  126,   55,    0,
    0,  131,  129,   22,  130,    0,  132,    0,  176,  177,
    0,    0,   22,   67,    0,  121,  122,  123,  124,  128,
    0,  127,    0,    0,    0,    0,    0,  134,    0,    0,
    0,  133,  126,    0,    0,  181,  131,  129,  182,  130,
    0,  132,   10,    0,   12,   13,  121,  122,  123,  124,
   10,    0,    0,   17,  128,  134,  127,    0,    0,  133,
  126,    0,    0,  183,  131,  129,  184,  130,    0,  132,
    0,    0,    0,    0,  121,  122,  123,  124,    0,    0,
    0,    0,  128,  125,  127,    0,    0,    0,    0,    0,
  121,  122,  123,  124,    0,    0,    0,    0,  134,    0,
    0,    0,  133,  126,    0,  144,  149,  131,  129,    0,
  130,    0,  132,    0,    0,  169,    0,    0,  121,  122,
  123,  124,    0,    0,  134,  128,    0,  127,  133,  126,
    0,    0,    0,  131,  129,    0,  130,    0,  132,    0,
    0,    0,    0,    0,  121,  122,  125,    0,    0,    0,
  173,  128,    0,  127,  134,    0,    0,    0,  133,  126,
    0,    0,    0,  131,  129,    0,  130,    0,  132,    0,
  134,    0,    0,    0,  133,  126,    0,    0,    0,  131,
  129,  128,  130,  127,  132,    0,    0,    0,    0,  125,
    0,    0,    0,    0,    0,    0,   65,  128,    0,  127,
   65,   65,    0,    0,    0,   65,   65,  134,   65,    0,
   65,  133,  126,    0,    0,  125,  131,  129,    0,  130,
  145,  132,   65,   65,    0,   65,    0,    0,    0,    0,
    0,   81,    0,   85,  128,   84,  127,    0,   83,    0,
  121,  122,  123,  124,  134,  125,    0,    0,  133,    0,
    0,    0,    0,  131,  129,    0,  130,    0,  132,    0,
    0,  125,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  128,    0,  127,    0,  121,  122,  123,  124,   81,
    0,   85,    0,   84,    0,    0,   83,   65,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  125,    0,
    0,    0,    0,  121,  122,  123,  124,    0,    0,   81,
    0,   85,    0,   84,    0,  120,   83,    0,    0,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   81,    0,    0,   81,    0,    0,   81,    0,    0,    0,
    0,    0,    0,  120,    0,    0,  121,  122,  123,  124,
   81,   81,   85,    0,   84,   87,    0,   83,   87,    0,
    0,   87,    0,    0,   57,    0,   86,   82,    0,  170,
  171,    0,  121,  122,  123,  124,   87,    0,    0,    0,
   81,    0,   85,    0,   84,   81,    0,   83,    0,    0,
    0,  189,    0,    0,   57,    0,  116,   82,    0,    0,
  178,    0,  121,  122,  123,  124,  185,  190,  187,    0,
   87,    0,    0,    0,  191,  192,   81,    0,  121,  122,
  123,  124,   48,    0,   48,    0,   48,    0,    0,   48,
    0,    0,    0,    0,    0,   57,    0,  119,   82,    0,
    0,   87,    0,    0,   65,   65,   65,   65,    0,    0,
   70,   71,   72,   73,    0,  121,  122,  123,  124,    0,
    0,    0,    0,    0,    0,   57,    0,  151,   82,    0,
   81,    0,   85,    0,   84,    0,    0,   83,   79,   80,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  121,  122,  123,  124,    0,    0,   70,   71,
   72,   73,    0,   74,    0,    0,    1,   48,    0,   48,
   48,   75,   76,    0,    0,    0,    0,   77,   78,    4,
    5,    6,    0,    0,    0,    0,   79,   80,   70,   71,
   72,   73,    0,   74,    0,    0,    1,    0,    0,    0,
    0,   75,   76,    0,    0,    0,    0,   77,   78,    4,
    5,    6,    0,   81,    0,   57,   79,   80,   82,    0,
   81,    0,   81,    0,    0,   81,   81,   81,    0,   70,
   71,   72,   73,    0,   74,   81,   81,    0,   87,    0,
    0,    0,   75,   76,    0,   87,    0,   87,   77,   78,
   87,   87,   87,    0,    0,    0,    0,   79,   80,   70,
   71,   72,   73,    0,   74,    0,    0,    0,    0,    0,
    0,    0,   75,   76,    0,    0,    0,    0,   77,   78,
    0,    0,    0,    0,    0,   74,   74,   79,   80,   74,
   74,   74,   74,   74,    0,   74,    0,    0,    0,    0,
    0,   48,   48,   48,   48,    0,   48,   74,   74,    0,
   74,    0,    0,    0,   48,   48,    0,    0,    0,    0,
   48,   48,    0,    0,    0,    0,    0,    0,    0,   48,
   48,    0,    0,    0,   83,    0,    0,   83,    0,    0,
   83,   74,    0,    0,    0,    0,    0,    0,    0,   70,
   71,   72,   73,    0,   74,   83,   83,    0,   83,    0,
    0,    0,   75,   76,    0,    0,    0,    0,   77,   78,
    0,    0,   74,    0,    0,   75,   75,   79,   80,   75,
   75,   75,   75,   75,    0,   75,    0,    0,    0,   83,
    0,    0,    0,    0,    0,    0,    0,   75,   75,    0,
   75,   76,   76,    0,    0,   76,   76,   76,   76,   76,
    0,   76,    0,    0,    0,    0,    0,    0,    0,    0,
   83,    0,    0,   76,   76,    0,   76,   77,    0,    0,
   77,   75,   77,   77,   77,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   77,   77,
    0,   77,    0,   78,    0,    0,   78,   76,   78,   78,
   78,    0,   75,    0,    0,    0,    0,    0,    0,    0,
   84,    0,    0,   84,   78,   78,   84,   78,    0,    0,
    0,    0,   77,    0,    0,    0,    0,    0,   76,    0,
    0,   84,   84,    0,   84,    0,   82,    0,    0,   82,
    0,    0,   82,    0,    0,    0,    0,    0,   78,   74,
    0,    0,    0,   77,    0,    0,   74,   82,   74,    0,
    0,   74,   74,   74,   86,   84,    0,   86,    0,   74,
   74,   74,   74,    0,    0,    0,    0,   79,    0,   78,
   79,    0,   86,   79,    0,    0,    0,    0,    0,    0,
    0,   82,    0,    0,    0,    0,   84,   83,   79,   79,
    0,   79,    0,    0,   83,   68,   83,    0,   68,   83,
   83,   83,    0,    0,    0,    0,   86,   83,   83,   83,
   83,   80,   82,   68,   80,    0,    0,   80,    0,    0,
    0,    0,   79,    0,    0,    0,    0,    0,    0,   75,
    0,    0,   80,   80,    0,   80,   75,   86,   75,    0,
    0,   75,   75,   75,    0,    0,    0,   68,    0,   75,
   75,   75,   75,   79,    0,   76,    0,    0,    0,    0,
    0,    0,   76,    0,   76,    0,   80,   76,   76,   76,
    0,    0,    0,    0,    0,   76,   76,   76,   76,    0,
   77,    0,    0,    0,    0,    0,    0,   77,    0,   77,
    0,    0,   77,   77,   77,    0,    0,   80,    0,    0,
   77,   77,   77,   77,    0,    0,   78,    0,    0,    0,
    0,    0,    0,   78,    0,   78,    0,    0,   78,   78,
   78,    0,    0,   84,    0,    0,   78,   78,   78,   78,
   84,    0,   84,    0,    0,   84,   84,   84,    0,    0,
    0,    0,    0,   84,   84,   84,   84,    0,    0,   82,
    0,    0,    0,    0,   85,    0,   82,   85,   82,    0,
   85,   82,   82,   82,    0,    0,    0,    0,    0,    0,
    0,   82,   82,    0,   86,   85,    0,    0,    0,    0,
    0,   86,    0,   86,    0,    0,   86,   86,   86,    0,
   79,    0,    0,    0,    0,    0,    0,   79,    0,   79,
    0,    0,   79,   79,   79,    0,    0,    0,    0,   85,
   79,   79,   79,   79,    0,   68,    0,    0,    0,    0,
    0,    0,   68,    0,   68,    0,    0,   68,   68,   68,
    0,    0,    0,    0,   80,    0,    0,    0,    0,   93,
   85,   80,    0,   80,    0,    0,   80,   80,   80,    0,
    0,    0,    0,    0,   80,   80,   80,   80,  105,  101,
  103,  108,  109,  110,    0,    0,  113,  111,  112,    0,
  114,   93,   93,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  141,  143,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   93,    0,    0,    0,    0,    0,  152,  153,  154,  155,
  156,  157,  158,  159,  160,  161,  162,  163,  164,    0,
    0,    0,    0,  165,  166,    0,   93,   93,    0,    0,
    0,  172,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  174,    0,    0,    0,   93,    0,    0,
    0,  179,  180,   93,    0,   93,    0,  186,    0,  188,
    0,   93,   93,    0,    0,    0,    0,   85,    0,    0,
    0,    0,    0,    0,   85,    0,   85,    0,    0,   85,
   85,   85,
};
static const short yycheck[] = {                         33,
   40,   35,   40,   37,   38,   35,   42,   41,   42,   43,
   44,   45,   40,   47,  259,   42,   40,  285,  286,   41,
  259,   42,   44,   61,  292,   59,   60,   40,   62,   33,
  259,   59,  259,   37,   38,   59,   59,   41,   42,   43,
   44,   45,   57,   47,   40,   59,   59,   62,   42,   41,
   59,   91,  123,   40,   40,   59,   60,   33,   62,   93,
  279,   37,   38,   59,   41,   41,   42,   43,   44,   45,
   44,   47,   59,   59,   89,   41,   40,   59,   44,   42,
   59,   59,   97,   59,   60,   40,   62,   33,   59,   93,
  124,   37,   38,  265,  259,   59,   42,   43,   59,   45,
   41,   47,   44,   44,   59,  259,  278,  279,  280,  259,
  278,  278,   59,  267,   60,  272,   62,   93,   33,   91,
  124,   59,   37,   38,  278,  279,  280,   42,   43,  265,
   45,  267,   47,   59,   59,   33,  269,    0,    0,  265,
  266,  267,  278,  279,  280,   60,   33,   62,  124,   59,
   37,   38,  278,  279,  280,   42,   43,   41,   45,   59,
   47,   41,   33,    8,   -1,   89,   37,   38,   -1,   -1,
   -1,   42,   43,   60,   45,   62,   47,   -1,  124,   -1,
   -1,   -1,   -1,   33,   -1,   -1,   -1,   37,   59,   60,
   33,   62,   42,   -1,   37,   38,   -1,   47,   -1,   42,
   43,   33,   45,   -1,   47,   37,   -1,   -1,   -1,  124,
   42,   43,   -1,   45,   -1,   47,   33,   60,   -1,   62,
   37,   -1,   -1,  259,   -1,   42,   43,  261,   45,   -1,
   47,   -1,  259,   -1,  268,   -1,  270,  124,  259,  273,
  274,  275,   -1,   60,   -1,   62,   -1,  281,  282,  283,
  284,  285,  286,  124,   -1,  285,  286,  261,  292,  287,
   -1,   -1,  292,  287,  268,  259,  270,   -1,  272,  273,
  274,  275,   -1,  265,  287,   -1,   -1,  281,  282,  283,
  284,  124,   -1,   -1,   -1,  261,  278,  279,  280,   -1,
   -1,  287,  268,   -1,  270,   -1,  259,  273,  274,  275,
  287,  287,   18,   -1,   20,  281,  282,  283,  284,   -1,
   26,   27,   33,   -1,   -1,   31,   37,   38,   34,   -1,
   -1,   42,   43,  287,   45,   -1,   47,   -1,  274,  275,
   -1,   -1,  287,   49,   -1,  281,  282,  283,  284,   60,
   -1,   62,   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,
   -1,   37,   38,   -1,   -1,  270,   42,   43,  273,   45,
   -1,   47,    0,   -1,    2,    3,  281,  282,  283,  284,
    8,   -1,   -1,   11,   60,   33,   62,   -1,   -1,   37,
   38,   -1,   -1,  270,   42,   43,  273,   45,   -1,   47,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,
   -1,   -1,   60,  124,   62,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,   -1,  268,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   93,   -1,   -1,  281,  282,
  283,  284,   -1,   -1,   33,   60,   -1,   62,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,  281,  282,  124,   -1,   -1,   -1,
   59,   60,   -1,   62,   33,   -1,   -1,   -1,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   33,   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,
   43,   60,   45,   62,   47,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   33,   60,   -1,   62,
   37,   38,   -1,   -1,   -1,   42,   43,   33,   45,   -1,
   47,   37,   38,   -1,   -1,  124,   42,   43,   -1,   45,
  261,   47,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   40,   60,   42,   62,   -1,   45,   -1,
  281,  282,  283,  284,   33,  124,   -1,   -1,   37,   -1,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   60,   -1,   62,   -1,  281,  282,  283,  284,   38,
   -1,   40,   -1,   42,   -1,   -1,   45,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,   38,
   -1,   40,   -1,   42,   -1,   90,   45,   -1,   -1,  126,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,  118,   -1,   -1,  281,  282,  283,  284,
   38,   59,   40,   -1,   42,   38,   -1,   45,   41,   -1,
   -1,   44,   -1,   -1,  123,   -1,  125,  126,   -1,  144,
  145,   -1,  281,  282,  283,  284,   59,   -1,   -1,   -1,
   38,   -1,   40,   -1,   42,   93,   -1,   45,   -1,   -1,
   -1,  270,   -1,   -1,  123,   -1,  125,  126,   -1,   -1,
  175,   -1,  281,  282,  283,  284,  181,  270,  183,   -1,
   93,   -1,   -1,   -1,  189,  190,  124,   -1,  281,  282,
  283,  284,   38,   -1,   40,   -1,   42,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,  126,   -1,
   -1,  124,   -1,   -1,  281,  282,  283,  284,   -1,   -1,
  257,  258,  259,  260,   -1,  281,  282,  283,  284,   -1,
   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,  126,   -1,
   38,   -1,   40,   -1,   42,   -1,   -1,   45,  285,  286,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,   -1,   -1,  257,  258,
  259,  260,   -1,  262,   -1,   -1,  265,  123,   -1,  125,
  126,  270,  271,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,  280,   -1,   -1,   -1,   -1,  285,  286,  257,  258,
  259,  260,   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,
   -1,  270,  271,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,  280,   -1,  261,   -1,  123,  285,  286,  126,   -1,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,  257,
  258,  259,  260,   -1,  262,  283,  284,   -1,  261,   -1,
   -1,   -1,  270,  271,   -1,  268,   -1,  270,  276,  277,
  273,  274,  275,   -1,   -1,   -1,   -1,  285,  286,  257,
  258,  259,  260,   -1,  262,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,  276,  277,
   -1,   -1,   -1,   -1,   -1,   37,   38,  285,  286,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,  260,   -1,  262,   59,   60,   -1,
   62,   -1,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,
  276,  277,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,
  286,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,  262,   59,   60,   -1,   62,   -1,
   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,  276,  277,
   -1,   -1,  124,   -1,   -1,   37,   38,  285,  286,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   59,   60,   -1,   62,   38,   -1,   -1,
   41,   93,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,
   -1,   62,   -1,   38,   -1,   -1,   41,   93,   43,   44,
   45,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   38,   -1,   -1,   41,   59,   60,   44,   62,   -1,   -1,
   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   59,   60,   -1,   62,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   93,  261,
   -1,   -1,   -1,  124,   -1,   -1,  268,   59,  270,   -1,
   -1,  273,  274,  275,   41,   93,   -1,   44,   -1,  281,
  282,  283,  284,   -1,   -1,   -1,   -1,   38,   -1,  124,
   41,   -1,   59,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,  124,  261,   59,   60,
   -1,   62,   -1,   -1,  268,   41,  270,   -1,   44,  273,
  274,  275,   -1,   -1,   -1,   -1,   93,  281,  282,  283,
  284,   38,  124,   59,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,  261,
   -1,   -1,   59,   60,   -1,   62,  268,  124,  270,   -1,
   -1,  273,  274,  275,   -1,   -1,   -1,   93,   -1,  281,
  282,  283,  284,  124,   -1,  261,   -1,   -1,   -1,   -1,
   -1,   -1,  268,   -1,  270,   -1,   93,  273,  274,  275,
   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   -1,
  261,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
   -1,   -1,  273,  274,  275,   -1,   -1,  124,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,  261,   -1,   -1,   -1,
   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,  261,   -1,   -1,  281,  282,  283,  284,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,  261,
   -1,   -1,   -1,   -1,   38,   -1,  268,   41,  270,   -1,
   44,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  284,   -1,  261,   59,   -1,   -1,   -1,   -1,
   -1,  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,
  261,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
   -1,   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   93,
  281,  282,  283,  284,   -1,  261,   -1,   -1,   -1,   -1,
   -1,   -1,  268,   -1,  270,   -1,   -1,  273,  274,  275,
   -1,   -1,   -1,   -1,  261,   -1,   -1,   -1,   -1,   57,
  124,  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,
   -1,   -1,   -1,   -1,  281,  282,  283,  284,   76,   74,
   75,   79,   80,   81,   -1,   -1,   84,   82,   83,   -1,
   85,   89,   90,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   99,  100,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  118,   -1,   -1,   -1,   -1,   -1,  121,  122,  123,  124,
  125,  126,  127,  128,  129,  130,  131,  132,  133,   -1,
   -1,   -1,   -1,  138,  139,   -1,  144,  145,   -1,   -1,
   -1,  146,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  168,   -1,   -1,   -1,  175,   -1,   -1,
   -1,  176,  177,  181,   -1,  183,   -1,  182,   -1,  184,
   -1,  189,  190,   -1,   -1,   -1,   -1,  261,   -1,   -1,
   -1,   -1,   -1,   -1,  268,   -1,  270,   -1,   -1,  273,
  274,  275,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'",0,"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","NUM","IDENTIF","STRN",
"WHILE","IF","END","RETURN","VOID","PUBLIC","CONST","THEN","ELSE","DO","FOR",
"IN","STEP","UPTO","DOWNTO","BREAK","CONTINUE","INTEGER","STRING","NUMBER","GE",
"LE","EQ","NE","INC","DEC","ATRIB","ADDR","POINTER","IFX","UMINUS","\":=\"",
};
static const char *yyrule[] = {
"$accept : ficheiro",
"ficheiro : declaracoes",
"ficheiro :",
"declaracoes : declaracao",
"declaracoes : declaracoes declaracao",
"declaracao : PUBLIC tipo '*' IDENTIF init ';'",
"declaracao : tipo '*' IDENTIF init ';'",
"declaracao : PUBLIC CONST tipo '*' IDENTIF init ';'",
"declaracao : CONST tipo '*' IDENTIF init ';'",
"declaracao : PUBLIC tipo IDENTIF init ';'",
"declaracao : tipo IDENTIF init ';'",
"declaracao : PUBLIC CONST tipo IDENTIF init ';'",
"declaracao : CONST tipo IDENTIF init ';'",
"declaracao : PUBLIC tipo '*' IDENTIF ';'",
"declaracao : tipo '*' IDENTIF ';'",
"declaracao : PUBLIC CONST tipo '*' IDENTIF ';'",
"declaracao : CONST tipo '*' IDENTIF ';'",
"declaracao : PUBLIC tipo IDENTIF ';'",
"declaracao : tipo IDENTIF ';'",
"declaracao : PUBLIC CONST tipo IDENTIF ';'",
"declaracao : CONST tipo IDENTIF ';'",
"tipo : INTEGER",
"tipo : STRING",
"tipo : NUMBER",
"tipo : VOID",
"init : ATRIB INTEGER",
"init : ATRIB CONST STRING",
"init : ATRIB STRING",
"init : ATRIB NUMBER",
"init : ATRIB IDENTIF",
"init : '(' parametros ')' corpo",
"init : '(' parametros ')'",
"init : '(' ')' corpo",
"init : '(' ')'",
"pars : ',' parametro",
"pars : pars ',' parametro",
"parametros : parametro",
"parametros : parametro pars",
"parametro : tipo IDENTIF",
"parametro : tipo '*' IDENTIF",
"pars2 : parametro ';'",
"pars2 : pars2 parametro ';'",
"corpo : '{' '}'",
"corpo : '{' pars2 '}'",
"corpo : '{' instrucoes '}'",
"corpo : '{' pars2 instrucoes '}'",
"instrucoes : instrucao",
"instrucoes : instrucoes instrucao",
"instrucao : IF expressao THEN instrucao",
"instrucao : IF expressao THEN instrucao ELSE instrucao",
"instrucao : DO expressao WHILE instrucao",
"instrucao : FOR left_value IN expressao UPTO expressao DO instrucao",
"instrucao : FOR left_value IN expressao DOWNTO expressao DO instrucao",
"instrucao : FOR left_value IN expressao UPTO expressao STEP expressao DO instrucao",
"instrucao : FOR left_value IN expressao DOWNTO expressao STEP expressao DO instrucao",
"instrucao : expressao ';'",
"instrucao : corpo",
"instrucao : BREAK INTEGER ';'",
"instrucao : CONTINUE INTEGER ';'",
"instrucao : left_value '#' expressao ';'",
"expressoes : expressoes ',' expressao",
"expressoes : expressao",
"expressao : INT",
"expressao : NUM",
"expressao : STRN",
"expressao : left_value",
"expressao : IDENTIF '(' expressoes ')'",
"expressao : '(' expressao ')'",
"expressao : left_value \":=\" expressao",
"expressao : '-' expressao",
"expressao : INC left_value",
"expressao : DEC left_value",
"expressao : left_value INC",
"expressao : left_value DEC",
"expressao : expressao '*' expressao",
"expressao : expressao '/' expressao",
"expressao : expressao '%' expressao",
"expressao : expressao '+' expressao",
"expressao : expressao '-' expressao",
"expressao : expressao '>' expressao",
"expressao : expressao '<' expressao",
"expressao : expressao EQ expressao",
"expressao : expressao NE expressao",
"expressao : expressao GE expressao",
"expressao : expressao LE expressao",
"expressao : expressao '&' expressao",
"expressao : expressao '|' expressao",
"expressao : '~' expressao",
"expressao : expressao '!'",
"expressao : '&' left_value",
"expressao : '*' left_value",
"left_value : IDENTIF",
"left_value : IDENTIF '[' expressao ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 179 "factorial.y"

extern FILE *yyin;

int main(int argc, char *argv[]) {

do{yyparse();}

while (!feof(yyin));

return 0;
}

yyerror(s)

char *s;

fprintf(stderr, "%s\n", s);  
#line 721 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
