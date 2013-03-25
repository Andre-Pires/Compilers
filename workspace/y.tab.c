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
#line 26 "factorial.y"
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
#line 55 "y.tab.c"

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

#define INTEGER 257
#define NUMBER 258
#define IDENTIF 259
#define STRING 260
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
#define GE 278
#define LE 279
#define EQ 280
#define NE 281
#define INC 282
#define DEC 283
#define ATRIB 284
#define ADDR 285
#define POINTER 286
#define UMINUS 287
#define expressoes 288
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    6,    6,    4,    4,    7,    7,    8,    8,    5,
    5,    5,    5,    9,    9,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   12,   12,
};
static const short yylen[] = {                            2,
    1,    0,    6,    5,    7,    6,    5,    4,    6,    5,
    5,    4,    6,    5,    4,    3,    5,    4,    1,    1,
    1,    1,    2,    3,    2,    2,    2,    4,    3,    3,
    2,    2,    2,    1,    2,    2,    3,    2,    2,    2,
    3,    3,    4,    1,    1,    6,    4,    4,    8,    8,
   10,   10,    2,    1,    3,    3,    4,    1,    1,    1,
    1,    4,    3,    3,    2,    2,    2,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    1,    4,
};
static const short yydefred[] = {                         0,
   19,   21,   20,   22,    0,    0,    0,    1,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   16,    0,    0,    0,    0,   15,    0,    0,   18,
    0,    0,   23,   26,   27,   25,    0,    0,    0,    0,
    0,    8,   12,    0,   17,    0,    0,    7,   11,    0,
   10,   14,    0,   24,    0,   30,   36,    0,    0,    0,
   35,    4,    9,   13,    0,    3,    6,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40,   54,    0,    0,    0,   44,    0,
    0,   37,   28,   33,   32,    5,    0,    0,   58,   59,
   60,    0,    0,    0,    0,    0,    0,    0,   66,   67,
   84,   65,   85,   83,    0,   38,   39,   41,    0,   42,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   53,   68,   69,    0,    0,    0,    0,
    0,    0,    0,   55,   56,   63,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   70,   71,   72,
    0,    0,   62,   87,    0,   48,    0,   57,    0,    0,
    0,   46,    0,    0,    0,    0,    0,    0,   49,    0,
   50,    0,    0,    0,   51,   52,
};
static const short yydgoto[] = {                          7,
    8,   39,   23,   40,   85,   61,   41,   87,   88,   89,
   90,  103,
};
static const short yysindex[] = {                      -171,
    0,    0,    0,    0, -145, -232,    0,    0,  -28, -232,
    4,    9,  -39, -253,   10,  -38, -251,  -37, -235, -118,
  -24,    0,  -18,  -36,  -29, -216,    0,  -10,  -11,    0,
   -3,   -9,    0,    0,    0,    0, -202,  -52,   27,   36,
   34,    0,    0,   23,    0,   29,   -2,    0,    0,   32,
    0,    0,   44,    0,  -33,    0,    0, -175,  -52,   30,
    0,    0,    0,    0,   45,    0,    0,    0,    0,  -27,
    0,    2,    2, -166, -149, -147, -166, -166, -166,    2,
 -166,    2,    2,    0,    0,   55,   -6,   -7,    0,  430,
  -16,    0,    0,    0,    0,    0, -172,    2,    0,    0,
    0,  313,  -43,  286,   39, -151,   66,   68,    0,    0,
    0,    0,    0,    0,  456,    0,    0,    0,   12,    0,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    0,    0,    0,    2,    2,   94,  477,
   21,   21,    2,    0,    0,    0,    0,   25,   25,  863,
  863,  654,  526,   25,   25,   18,   18,    0,    0,    0,
  489,  617,    0,    0, -126,    0,  118,    0,   21,    2,
    2,    0,  134,  148,   21,    2,   21,    2,    0,  515,
    0,  565,   21,   21,    0,    0,
};
static const short yyrindex[] = {                       145,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   87,    0,    0,
  106,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   89,    0,
    0,    0,    0,    0,    0,    0,    0,  341,  393,   38,
  404,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  591,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   91,    0,   64,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  607,  780,  723,
  825,  706,  420,  796,  853,  684,  738,    0,    0,    0,
    0,  760,    0,    0,   33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  213,  558,    0,  -22,   92,  -45,    0,   67,   28,
 1037, 1010,
};
#define YYTABLESIZE 1215
static const short yytable[] = {                         82,
   21,   21,   21,   21,   79,   24,   83,   29,   81,   86,
   21,   80,   97,   14,   95,   56,   38,  138,  137,   22,
   27,   30,   43,   32,    1,    2,   82,    3,   21,   45,
   21,   79,    4,   83,   82,   81,   93,   21,   80,   79,
   42,   83,   47,   81,  138,   17,   80,   49,   48,   52,
   19,   26,  117,   82,  133,   51,   64,   54,   79,  131,
   83,  133,   81,   98,  132,   80,  131,  129,   58,  130,
   55,  132,   86,   60,   86,   86,   59,   60,   86,   86,
   86,   62,   86,   92,   86,    1,    2,   63,    3,   55,
   66,   84,  105,    4,    5,    6,   86,   86,   86,   86,
   86,   86,   67,   96,   86,   86,   86,  107,   86,  108,
   86,    1,    2,  116,    3,  139,   55,  120,  118,    4,
  143,   10,   86,   86,  144,   86,  145,   61,   61,   98,
   86,   61,   61,   61,  163,   61,  147,   61,   33,   34,
   35,   36,  169,   55,    2,   31,   34,   29,   37,   61,
   61,   94,   61,  119,  133,  126,   86,   47,    0,  131,
  129,   86,  130,    0,  132,    0,    0,    0,  165,  166,
  133,  126,    0,    0,    0,  131,  129,  128,  130,  127,
  132,    0,    0,   61,  133,  126,    0,   86,    0,  131,
  129,    0,  130,  128,  132,  127,  172,    0,    0,    0,
    0,    0,  179,    0,  181,    0,    0,  128,    0,  127,
  185,  186,    9,    0,   61,    0,    0,   11,   12,    0,
    0,    0,   15,   68,   69,   70,   71,    0,   72,    0,
   13,    4,    1,    2,    0,    3,   73,   74,  135,  136,
    4,  125,   75,   76,   20,   20,   20,   20,   77,   78,
   99,  100,   70,  101,   20,   72,    0,  125,   99,  100,
   70,  101,   16,   73,   74,  135,  136,   18,   25,   75,
   76,  125,   20,    0,   20,   77,   78,   99,  100,   70,
  101,   20,   72,   77,   78,   57,    1,    2,    0,    3,
   73,   74,    0,    0,    4,    0,   75,   76,   86,    0,
    0,    0,   77,   78,    0,   86,    0,   86,    0,    0,
   86,   86,   86,    0,    0,   86,   86,   86,   86,   86,
   86,    0,  133,  126,   86,    0,    0,  131,  129,    0,
  130,   86,  132,   86,    0,   86,   86,   86,   86,    0,
    0,   86,   86,   86,   86,  128,    0,  127,    0,  133,
  126,   61,    0,    0,  131,  129,    0,  130,   61,  132,
   61,    0,    0,   61,   61,   61,    0,    0,   61,   61,
   61,   61,  128,    0,  127,    0,    0,   58,   58,    0,
    0,    0,   19,   58,    0,   58,    0,   58,    0,    0,
    0,  170,  171,    0,    0,  121,  122,  123,  124,   58,
   58,    0,   58,  175,    0,    0,  176,    0,    0,  125,
    0,  121,  122,  123,  124,    0,    0,  177,    0,    0,
  178,    0,    0,    0,    0,  121,  122,  123,  124,   59,
   59,    0,    0,    0,   21,   59,  125,   59,    0,   59,
   60,   60,    0,    0,    0,   20,   60,    0,   60,    0,
   60,   59,   59,    0,   59,    0,    0,   81,    0,    0,
   81,    0,   60,   60,   58,   60,  133,  126,    0,    0,
    0,  131,  129,    0,  130,    0,  132,    0,   81,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  134,  128,
    0,  127,  133,  126,    0,    0,  146,  131,  129,    0,
  130,    0,  132,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   81,  133,  126,  128,   59,  127,  131,  129,
    0,  130,    0,  132,    0,  133,  126,   60,    0,    0,
  131,  129,    0,  130,    0,  132,  128,    0,  127,    0,
    0,    0,    0,   81,    0,    0,  142,  168,  128,    0,
  127,  133,  126,  125,    0,    0,  131,  129,    0,  130,
    0,  132,  133,  121,  122,  123,  124,  131,  129,  164,
  130,    0,  132,   28,  128,   31,  127,    0,    0,  125,
  141,   44,   46,    0,    0,  128,   50,  127,    0,   53,
  121,  122,  123,  124,    0,    0,    0,    0,    0,   19,
  125,  133,  126,    0,   65,    0,  131,  129,    0,  130,
    0,  132,  125,    0,    0,    0,    0,    0,   58,   58,
   58,   58,    0,    0,  128,    0,  127,   61,   61,    0,
    0,    0,   61,   61,    0,   61,    0,   61,  125,    0,
    0,    0,    0,    0,   79,    0,    0,   79,    0,   61,
   61,   21,   61,  133,  126,    0,    0,    0,  131,  129,
    0,  130,   20,  132,    0,   79,   79,    0,   79,    0,
   59,   59,   59,   59,    0,    0,  128,    0,  127,    0,
   81,   60,   60,   60,   60,    0,    0,   81,  125,   81,
  133,  126,   81,   81,   81,  131,  129,    0,  130,   79,
  132,    0,    0,    0,    0,    0,    0,  121,  122,  123,
  124,    0,    0,  128,   61,  127,    0,    0,    0,    0,
    0,   73,    0,    0,   73,    0,   73,    0,   73,    0,
   79,    0,    0,  121,  122,  123,  124,    0,    0,    0,
  125,    0,   73,   73,    0,   73,   82,    0,    0,    0,
    0,    0,    0,    0,  121,  122,  123,  124,    0,    0,
   77,    0,    0,   77,   82,    0,  121,  122,  123,  124,
    0,    0,    0,    0,    0,   74,   73,    0,   74,    0,
   74,   77,   74,    0,  183,    0,    0,    0,    0,    0,
    0,    0,  121,  122,  123,  124,   74,   74,   82,   74,
   64,    0,    0,  121,  122,  123,  124,   73,    0,    0,
    0,    0,    0,    0,    0,   77,    0,   80,   64,    0,
   80,    0,    0,    0,    0,    0,    0,    0,    0,   82,
   74,    0,    0,   75,  184,    0,   75,    0,   80,   80,
    0,   80,  121,  122,  123,  124,   77,    0,    0,    0,
    0,    0,   64,    0,   75,   75,    0,   75,    0,    0,
    0,   74,   78,    0,    0,   78,    0,   79,   61,   61,
   61,   61,   80,    0,   79,    0,   79,    0,    0,   79,
   79,   79,    0,   78,   79,   79,   79,   79,   75,    0,
   76,    0,    0,   76,  121,  122,  123,  124,    0,  133,
    0,    0,    0,   80,  131,  129,    0,  130,    0,  132,
    0,   76,   76,    0,   76,    0,    0,   78,    0,   75,
    0,    0,  128,    0,  127,    0,    0,    0,    0,    0,
    0,  121,  122,  123,  124,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   73,   76,    0,    0,   78,    0,
    0,   73,    0,   73,    0,    0,   73,   73,   73,    0,
    0,   73,   73,   73,   73,    0,   82,    0,    0,    0,
    0,    0,    0,   82,    0,   82,   76,    0,   82,   82,
   82,    0,    0,   77,    0,    0,    0,    0,    0,    0,
   77,    0,   77,    0,    0,   77,   77,   77,   74,    0,
    0,    0,   77,   77,    0,   74,    0,   74,    0,    0,
   74,   74,   74,    0,    0,   74,   74,   74,   74,    0,
   64,    0,    0,    0,    0,    0,    0,   64,    0,   64,
    0,    0,   64,   64,   64,    0,    0,    0,    0,    0,
   80,    0,    0,    0,    0,    0,    0,   80,    0,   80,
    0,    0,   80,   80,   80,    0,   75,   80,   80,   80,
   80,    0,    0,   75,   91,   75,    0,    0,   75,   75,
   75,    0,    0,   75,   75,   75,   75,    0,    0,    0,
    0,    0,    0,  106,    0,   78,  109,  110,  111,    0,
  113,    0,   78,    0,   78,    0,   91,   78,   78,   78,
    0,    0,    0,    0,   78,   78,    0,    0,  102,  104,
    0,    0,    0,   76,    0,    0,  112,    0,  114,  115,
   76,    0,   76,    0,    0,   76,   76,   76,    0,    0,
   76,   76,   76,   76,  140,    0,    0,    0,    0,    0,
  121,  122,    0,    0,    0,    0,    0,    0,    0,    0,
   91,   91,    0,    0,    0,    0,    0,  148,  149,  150,
  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,
    0,    0,    0,  161,  162,    0,    0,    0,   91,  167,
    0,    0,    0,    0,   91,    0,   91,    0,    0,    0,
    0,    0,   91,   91,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  173,  174,    0,    0,
    0,    0,  180,    0,  182,
};
static const short yycheck[] = {                         33,
   40,   40,   40,   40,   38,  259,   40,  259,   42,   55,
   40,   45,   40,   42,   60,   38,   41,   61,   35,   59,
   59,   59,   59,  259,  257,  258,   33,  260,   40,   59,
   40,   38,  265,   40,   33,   42,   59,   40,   45,   38,
   59,   40,  259,   42,   61,   42,   45,   59,   59,   59,
   42,   42,   59,   33,   37,   59,   59,  260,   38,   42,
   40,   37,   42,   91,   47,   45,   42,   43,   42,   45,
  123,   47,   35,   44,   37,   38,   41,   44,   41,   42,
   43,   59,   45,  259,   47,  257,  258,   59,  260,  123,
   59,  125,  259,  265,  266,  267,   59,   60,   61,   62,
   37,   38,   59,   59,   41,   42,   43,  257,   45,  257,
   47,  257,  258,   59,  260,  288,  123,  125,  125,  265,
  272,  267,   59,   60,   59,   62,   59,   37,   38,   91,
   93,   41,   42,   43,   41,   45,  125,   47,  257,  258,
  259,  260,  269,  123,    0,   59,   41,   59,  267,   59,
   60,   60,   62,   87,   37,   38,   93,  125,   -1,   42,
   43,  124,   45,   -1,   47,   -1,   -1,   -1,  141,  142,
   37,   38,   -1,   -1,   -1,   42,   43,   60,   45,   62,
   47,   -1,   -1,   93,   37,   38,   -1,  124,   -1,   42,
   43,   -1,   45,   60,   47,   62,  169,   -1,   -1,   -1,
   -1,   -1,  175,   -1,  177,   -1,   -1,   60,   -1,   62,
  183,  184,    0,   -1,  124,   -1,   -1,    5,    6,   -1,
   -1,   -1,   10,  257,  258,  259,  260,   -1,  262,   -1,
  259,  265,  257,  258,   -1,  260,  270,  271,  282,  283,
  265,  124,  276,  277,  284,  284,  284,  284,  282,  283,
  257,  258,  259,  260,  284,  262,   -1,  124,  257,  258,
  259,  260,  259,  270,  271,  282,  283,  259,  259,  276,
  277,  124,  284,   -1,  284,  282,  283,  257,  258,  259,
  260,  284,  262,  282,  283,  259,  257,  258,   -1,  260,
  270,  271,   -1,   -1,  265,   -1,  276,  277,  261,   -1,
   -1,   -1,  282,  283,   -1,  268,   -1,  270,   -1,   -1,
  273,  274,  275,   -1,   -1,  278,  279,  280,  281,  282,
  283,   -1,   37,   38,  261,   -1,   -1,   42,   43,   -1,
   45,  268,   47,  270,   -1,  272,  273,  274,  275,   -1,
   -1,  278,  279,  280,  281,   60,   -1,   62,   -1,   37,
   38,  261,   -1,   -1,   42,   43,   -1,   45,  268,   47,
  270,   -1,   -1,  273,  274,  275,   -1,   -1,  278,  279,
  280,  281,   60,   -1,   62,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,  274,  275,   -1,   -1,  278,  279,  280,  281,   59,
   60,   -1,   62,  270,   -1,   -1,  273,   -1,   -1,  124,
   -1,  278,  279,  280,  281,   -1,   -1,  270,   -1,   -1,
  273,   -1,   -1,   -1,   -1,  278,  279,  280,  281,   37,
   38,   -1,   -1,   -1,   42,   43,  124,   45,   -1,   47,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   59,   60,   -1,   62,   -1,   -1,   38,   -1,   -1,
   41,   -1,   59,   60,  124,   62,   37,   38,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,
   -1,   62,   37,   38,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   37,   38,   60,  124,   62,   42,   43,
   -1,   45,   -1,   47,   -1,   37,   38,  124,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   60,   -1,   62,   -1,
   -1,   -1,   -1,  124,   -1,   -1,  261,   59,   60,   -1,
   62,   37,   38,  124,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   37,  278,  279,  280,  281,   42,   43,   93,
   45,   -1,   47,   16,   60,   18,   62,   -1,   -1,  124,
  268,   24,   25,   -1,   -1,   60,   29,   62,   -1,   32,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,  259,
  124,   37,   38,   -1,   47,   -1,   42,   43,   -1,   45,
   -1,   47,  124,   -1,   -1,   -1,   -1,   -1,  278,  279,
  280,  281,   -1,   -1,   60,   -1,   62,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,  124,   -1,
   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   59,
   60,  259,   62,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,  259,   47,   -1,   59,   60,   -1,   62,   -1,
  278,  279,  280,  281,   -1,   -1,   60,   -1,   62,   -1,
  261,  278,  279,  280,  281,   -1,   -1,  268,  124,  270,
   37,   38,  273,  274,  275,   42,   43,   -1,   45,   93,
   47,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,  280,
  281,   -1,   -1,   60,  124,   62,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   41,   -1,   43,   -1,   45,   -1,
  124,   -1,   -1,  278,  279,  280,  281,   -1,   -1,   -1,
  124,   -1,   59,   60,   -1,   62,   41,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  278,  279,  280,  281,   -1,   -1,
   38,   -1,   -1,   41,   59,   -1,  278,  279,  280,  281,
   -1,   -1,   -1,   -1,   -1,   38,   93,   -1,   41,   -1,
   43,   59,   45,   -1,  270,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  278,  279,  280,  281,   59,   60,   93,   62,
   41,   -1,   -1,  278,  279,  280,  281,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   38,   59,   -1,
   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   93,   -1,   -1,   38,  270,   -1,   41,   -1,   59,   60,
   -1,   62,  278,  279,  280,  281,  124,   -1,   -1,   -1,
   -1,   -1,   93,   -1,   59,   60,   -1,   62,   -1,   -1,
   -1,  124,   38,   -1,   -1,   41,   -1,  261,  278,  279,
  280,  281,   93,   -1,  268,   -1,  270,   -1,   -1,  273,
  274,  275,   -1,   59,  278,  279,  280,  281,   93,   -1,
   38,   -1,   -1,   41,  278,  279,  280,  281,   -1,   37,
   -1,   -1,   -1,  124,   42,   43,   -1,   45,   -1,   47,
   -1,   59,   60,   -1,   62,   -1,   -1,   93,   -1,  124,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  261,   93,   -1,   -1,  124,   -1,
   -1,  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,
   -1,  278,  279,  280,  281,   -1,  261,   -1,   -1,   -1,
   -1,   -1,   -1,  268,   -1,  270,  124,   -1,  273,  274,
  275,   -1,   -1,  261,   -1,   -1,   -1,   -1,   -1,   -1,
  268,   -1,  270,   -1,   -1,  273,  274,  275,  261,   -1,
   -1,   -1,  280,  281,   -1,  268,   -1,  270,   -1,   -1,
  273,  274,  275,   -1,   -1,  278,  279,  280,  281,   -1,
  261,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
   -1,   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,
  261,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  270,
   -1,   -1,  273,  274,  275,   -1,  261,  278,  279,  280,
  281,   -1,   -1,  268,   55,  270,   -1,   -1,  273,  274,
  275,   -1,   -1,  278,  279,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,   74,   -1,  261,   77,   78,   79,   -1,
   81,   -1,  268,   -1,  270,   -1,   87,  273,  274,  275,
   -1,   -1,   -1,   -1,  280,  281,   -1,   -1,   72,   73,
   -1,   -1,   -1,  261,   -1,   -1,   80,   -1,   82,   83,
  268,   -1,  270,   -1,   -1,  273,  274,  275,   -1,   -1,
  278,  279,  280,  281,   98,   -1,   -1,   -1,   -1,   -1,
  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  141,  142,   -1,   -1,   -1,   -1,   -1,  121,  122,  123,
  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,
   -1,   -1,   -1,  137,  138,   -1,   -1,   -1,  169,  143,
   -1,   -1,   -1,   -1,  175,   -1,  177,   -1,   -1,   -1,
   -1,   -1,  183,  184,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  170,  171,   -1,   -1,
   -1,   -1,  176,   -1,  178,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 288
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","NUMBER",
"IDENTIF","STRING","WHILE","IF","END","RETURN","VOID","PUBLIC","CONST","THEN",
"ELSE","DO","FOR","IN","STEP","UPTO","DOWNTO","BREAK","CONTINUE","GE","LE","EQ",
"NE","INC","DEC","ATRIB","ADDR","POINTER","UMINUS","expressoes",
};
static const char *yyrule[] = {
"$accept : ficheiro",
"ficheiro : declaracao",
"ficheiro :",
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
"pars : ',' pars",
"parametros : parametro",
"parametros : parametro pars",
"parametro : tipo IDENTIF",
"parametro : tipo '*' IDENTIF",
"pars2 : parametro ';'",
"pars2 : pars2 ';'",
"corpo : '{' '}'",
"corpo : '{' pars2 '}'",
"corpo : '{' instrucoes '}'",
"corpo : '{' pars2 instrucoes '}'",
"instrucoes : instrucao",
"instrucoes : instrucoes",
"instrucao : IF expressao THEN instrucao ELSE instrucao",
"instrucao : IF expressao THEN instrucao",
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
"expressao : INTEGER",
"expressao : NUMBER",
"expressao : STRING",
"expressao : left_value",
"expressao : IDENTIF '(' expressoes ')'",
"expressao : '(' expressao ')'",
"expressao : left_value '=' expressao",
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
"expressao : '!' expressao",
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
#line 166 "factorial.y"
int main()
{
  while (yylex())
    ;
  return 0;
}

void yyerror(char *s)
{
  printf("%s\n", s);
}
#line 617 "y.tab.c"

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
