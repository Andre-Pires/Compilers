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
#define CALL 291
#define NEG 292
#define FACT 293
#define AND 294
#define OR 295
#define PROG 296
#define ADD 297
#define SUBT 298
#define MUL 299
#define DIV 300
#define LT 301
#define GT 302
#define MOD 303
#define PARAMS 304
#define PARS2 305
#define PARS 306
#define INTRS 307
#define PINTR 308
#define INTR 309
#define DECL 310
#define DECLS 311
#define INIT 312
#define NIL 313
#define PNTR 314
#define EXPS 315
#define EXP 316
#define MALL 317
#define BODY 318
#define JZ 319
#define ETIQ 320
#define LABEL 321
#define JNZ 322
#define JMP 323
#define UMINUS 324
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
  Node * n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
