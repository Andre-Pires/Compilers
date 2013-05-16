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
#define LIST 291
#define VECTOR 292
#define CALL 293
#define CALL2 294
#define NEG 295
#define FACT 296
#define AND 297
#define OR 298
#define PROG 299
#define ADD 300
#define SUBT 301
#define MUL 302
#define DIV 303
#define LT 304
#define GT 305
#define MOD 306
#define PARAMS 307
#define PARS2 308
#define PARS 309
#define PINTR 310
#define INTR 311
#define DECL 312
#define DECLS 313
#define INIT 314
#define NIL 315
#define PNTR 316
#define EXPS 317
#define EXP 318
#define MALL 319
#define BODY 320
#define JZ 321
#define ETIQ 322
#define LABEL 323
#define JNZ 324
#define JMP 325
#define INSTRS 326
#define UMINUS 327
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
