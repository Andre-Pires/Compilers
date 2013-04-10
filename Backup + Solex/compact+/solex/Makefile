LANG=compact
EXT=cpt

LEX=flex -l
YACC=byacc -dv

$(LANG): solex.y $(LANG).l
	$(YACC) -dv solex.y
	$(LEX) -l $(LANG).l
	gcc -o $(LANG) -DYYDEBUG lex.yy.c y.tab.c

install:: $(LANG)
	echo "not a delivrable"

clean::
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output *~
