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
#define CALL 292
#define CALL2 293
#define NEG 294
#define FACT 295
#define AND 296
#define OR 297
#define PROG 298
#define ADD 299
#define SUBT 300
#define MUL 301
#define DIV 302
#define LT 303
#define GT 304
#define MOD 305
#define PARAMS 306
#define PARS2 307
#define PARS 308
#define PINTR 309
#define INTR 310
#define DECL 311
#define DECLS 312
#define INIT 313
#define NIL 314
#define PNTR 315
#define EXPS 316
#define EXP 317
#define MALL 318
#define BODY 319
#define JZ 320
#define ETIQ 321
#define LABEL 322
#define JNZ 323
#define JMP 324
#define INSTRS 325
#define UMINUS 326
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
