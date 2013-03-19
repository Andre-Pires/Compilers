%{ 
/* $Id: at.l,v 1.7 2004/02/15 01:13:32 prs Exp $ */
#include <stdlib.h> 
#include "node.h" 
#include "y.tab.h" 
char *dupstr(const char *s);
%} 
 
%%

"const"								{ return CONST;			}
"void"								{ return VOID;			}
"int"								{ return INT;			}
"real"								{ return REAL;			}
"string"							{ return STRING;		}
"public"							{ return PUBLIC;		}
"use"								{ return USE;			}
"next"								{ return NEXT;			}
"stop"								{ return STOP;			}
"return"							{ return RETURN;		}
[ \t\n\r]+							{ ; /* Ignorar espacos vazios */}
\/\/.*\n 							{ ; /* Ignorar comentários */	}
\/\*(.|\n)*\*\/							{ ; /* Ignorar comentários */	}
">="								{ return GE; 			}
"<="								{ return LE; 			}
"=="								{ return EQ;	 		}
"!="								{ return NE; 			}
"&&"								{ return AND; 			}
"||"								{ return OR; 			}
"~"								{ return NOT;			}
"!"								{ return PRINT;			}
"!!"								{ return PRINT_NEW_LINE;	}
[-()<>=+*/^\[\];{}.?@,:"%""#"]					{ return yytext[0];	 	}
[a-zA-Z]([a-zA-Z0-9_])*		 				{ yylval.text = yytext; return ID;			}
0|[1-9][0-9]*							{ yylval.ival = atoi(yytext); return INTEGER; /* Decimal. Includes 0. */} 
0[0-7]+								{ yylval.ival = atoi(yytext); return INTEGER; /* Octal */		}
(0x|0X)([0-9a-fA-F])+						{ yylval.ival = atoi(yytext); return INTEGER; /* HexaDecimal */		}
0b[01]+								{ yylval.ival = atoi(yytext); return INTEGER; /* Binary */		}
([1-9](E[+-][1-9]+))|([1-9]\.([0-9]+(E[+-][1-9]+)))		{ yylval.dval = atoi(yytext); return LIT_REAL;		}
([1-9]\.[0-9]+)|([1-9][yzafpnumKMGTPEZY][0-9]+)			{ yylval.dval = atoi(yytext); return LIT_REAL;		}
(\'[^']?\')|\'(\\n|\\t|\\r|\\\\|\\\')\'|\'\\[0-9a-fA-F][0-9a-fA-F]?\'	{ yylval.text = yytext; return CHAR;		}
(\"[^"]*\")|\"(\\n|\\t|\\r|\\\\|\\\")\"|\"\\[0-9a-fA-F][0-9a-fA-F]?\"	{ yylval.text = yytext; return LIT_STRING;	}
. 								{ yyerror("Unknown character\n"); }

%%
int yywrap(void){return 1;}
