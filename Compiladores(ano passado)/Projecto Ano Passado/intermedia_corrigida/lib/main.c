#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char *ext = ".asm", *prog, *infile = "<<stdin>>", *outfile = 0;
int errors, opt, tree, trace, yyparse(void);

int yyerror(char *s)
{
  extern int yylineno;
  extern char yytext[];
  fprintf(stderr, "%s: %s at or before '%s' in line %d\n", infile, s, yytext, yylineno);
  errors++;
  return 1;
}

char *dupstr(const char *s)
{
  char *d;
  if (s == 0) return 0;
  d = (char*)malloc(strlen(s)+1);
  if (d == 0) return 0;
  strcpy(d, s);
  return d;
}

int main(int argc, char *argv[]) {
#ifdef YYDEBUG
  extern int yydebug;
  yydebug = getenv("YYDEBUG") ? 1 : 0;
#endif

  prog = argv[0];

  if (argc > 1 && strcmp(argv[1], "-O") == 0) { opt = 1; argc--; argv++; }
  if (argc > 1 && strcmp(argv[1], "-tree") == 0) { tree = 1; argc--; argv++; }
  if (argc > 1 && strcmp(argv[1], "-trace") == 0) { trace = 1; argc--; argv++; }
  if (argc > 1 && strcmp(argv[1], "-debug") == 0) { trace = 2; ext = ".stk"; argc--; argv++; }
  if (argc > 3) {
    fprintf(stderr, "USAGE: %s [-O] [-tree] [-trace] [-debug] [infile]\n",
	    argv[0]);
    exit(1);
  }

  if (argc > 1) {
    extern FILE *yyin;
    if ((yyin = fopen(infile = argv[1], "r")) == NULL) {
      perror(argv[1]);
      return 1;
    }
  }

  if (argc == 2) {
      char *str = dupstr(argv[1]);
      int len = strlen(str);
      if (len > 4 && str[len-4] == '.')
	  strcpy((outfile = str)+len-4, ext);
  }
  if (argc > 2) outfile = argv[2];

  if (yyparse() != 0 || errors > 0) {
    fprintf(stderr, "%d errors in %s\n", errors, infile);
    return 1;
  }
  return 0;
}
