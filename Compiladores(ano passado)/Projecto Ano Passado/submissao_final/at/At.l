%option c++ outfile="yyFlexLexer.cpp"
%option stack noyywrap nounput noyymore
%option yylineno 8bit
%{
#include <string>
#define String std::string
#include "NodeVariable.hpp"
#include "NodeString.hpp"
#include "NodeInteger.hpp"
#include "NodeReal.hpp"
#include "y.tab.h"
using namespace std;
void yyerror(const char *);
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
[a-zA-Z]([a-zA-Z0-9_])*		 				{ yylval.n = new NodeVariable(String(yytext)); return ID;			}
0|[1-9][0-9]*							{ yylval.n = new NodeInteger(atoi(yytext)); return INTEGER; /* Decimal. Includes 0. */} 
0[0-7]+								{ yylval.n = new NodeInteger(atoi(yytext)); return INTEGER; /* Octal */		}
(0x|0X)([0-9a-fA-F])+						{ yylval.n = new NodeInteger(atoi(yytext)); return INTEGER; /* HexaDecimal */		}
0b[01]+								{ yylval.n = new NodeInteger(atoi(yytext)); return INTEGER; /* Binary */		}
([0-9]+[yzafpnumKMGTPEZY][0-9]*)				{ /*yylval.n = new NodeReal(atoi(yytext));*/ return LIT_REAL;		}
(([1-9][0-9]*|0)?\.[0-9]*)|([1-9]([Ee][+-]?[1-9]+))|([1-9]\.([0-9]*([Ee][+-]?([1-9][0-9]*)))) { /*yylval.n = new NodeReal(atoi(yytext));*/ return LIT_REAL;		}
(\'[^']?\')|\'(\\n|\\t|\\r|\\\\|\\\')\'|\'\\[0-9a-fA-F][0-9a-fA-F]?\'	{ yytext[yyleng-1] = 0; yylval.n = new NodeString(String(yytext+1)); return CHAR;	}
\"([^"\\]|\\.)*\"						{ yytext[yyleng-1] = 0; yylval.n = new NodeString(String(yytext+1)); return LIT_STRING;	}
. 								{ yyerror("Unknown character\n"); }

