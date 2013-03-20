LANG=factorial
EXT=fac

LEX=flex -l
YACC=byacc -dv

$(LANG): factorial.y $(LANG).l
	$(YACC) factorial.y
	$(LEX) $(LANG).l
	gcc -o $(LANG) -DYYDEBUG lex.yy.c y.tab.c

install:: $(LANG)
	echo "not a delivrable"

clean::
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output *~
