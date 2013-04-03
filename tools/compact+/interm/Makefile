LANG=compact
EXT=cpt

LEX=flex -l
YACC=byacc -dv

$(LANG): interm.y $(LANG).l
	$(YACC) -dv interm.y
	$(LEX) -l $(LANG).l
	make -C ../lib
	gcc -o $(LANG) -DYYDEBUG -I../lib lex.yy.c y.tab.c ../lib/libutil.a

install:: $(LANG)
	cp $(LANG) ..

clean::
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output *~
