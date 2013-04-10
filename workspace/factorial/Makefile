LANG=factorial
EXT=fac

LEX=flex -l
YACC=byacc -dv

$(LANG): $(LANG).y $(LANG).l
	$(YACC) -dv $(LANG).y
	$(LEX) -l $(LANG).l
	make -C ../lib
	gcc -o $(LANG) -DYYDEBUG=1 -I../lib lex.yy.c y.tab.c ../lib/libutil.a

install:: $(LANG)
	cp $(LANG) ..

clean::
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output *~
