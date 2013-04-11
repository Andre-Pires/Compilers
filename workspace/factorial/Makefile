LANG=factorial
EXT=fac

LEX=flex -l
YACC=byacc -dv

$(LANG): $(LANG).y $(LANG).l
	$(YACC) -dv $(LANG).y
	$(LEX) -l $(LANG).l
	make -C ../lib
	gcc -o $(LANG) -DYYDEBUG=1 -I../lib lex.yy.c y.tab.c ../lib/libutil.a

examples: clean_examples run_examples

run_examples: clean_examples
	-./factorial ../examples/ack.fac > ../examples/ack.out
	-./factorial ../examples/add.fac > ../examples/add.out
	-./factorial ../examples/args.fac > ../examples/args.out
	-./factorial ../examples/break.fac > ../examples/break.out
	-./factorial ../examples/chrindex.fac > ../examples/chrindex.out
	-./factorial ../examples/cont.fac > ../examples/cont.out
	-./factorial ../examples/decl.fac > ../examples/decl.out
	-./factorial ../examples/div.fac > ../examples/div.out
	-./factorial ../examples/downto.fac > ../examples/downto.out
	-./factorial ../examples/fib.fac > ../examples/fib.out
	-./factorial ../examples/gcd.fac > ../examples/gcd.out
	-./factorial ../examples/gt.fac > ../examples/gt.out
	-./factorial ../examples/hello.fac > ../examples/hello.out
	-./factorial ../examples/if.fac > ../examples/if.out
	-./factorial ../examples/intindex.fac > ../examples/intindex.out
	-./factorial ../examples/local.fac > ../examples/local.out
	-./factorial ../examples/logic.fac > ../examples/logic.out
	-./factorial ../examples/pi.fac > ../examples/pi.out
	-./factorial ../examples/printi.fac > ../examples/printi.out
	-./factorial ../examples/strtest.fac > ../examples/strtest.out	
	-./factorial ../examples/tri.fac > ../examples/tri.out
	-./factorial ../examples/upto.fac > ../examples/upto.out
	-./factorial ../examples/while.fac > ../examples/while.out
	
diff_examples: run_examples
	-diff ../examples/ack.out ../examples/empty.out 
	-diff ../examples/add.out ../examples/empty.out
	-diff ../examples/args.out ../examples/empty.out
	-diff ../examples/break.out ../examples/empty.out
	-diff ../examples/chrindex.out ../examples/empty.out
	-diff ../examples/cont.out ../examples/empty.out
	-diff ../examples/decl.out ../examples/empty.out
	-diff ../examples/div.out ../examples/empty.out
	-diff ../examples/downto.out ../examples/empty.out
	-diff ../examples/fib.out ../examples/empty.out
	-diff ../examples/gcd.out ../examples/empty.out
	-diff ../examples/gt.out ../examples/empty.out
	-diff ../examples/hello.out ../examples/empty.out
	-diff ../examples/if.out ../examples/empty.out
	-diff ../examples/intindex.out ../examples/empty.out
	-diff ../examples/local.out ../examples/empty.out
	-diff ../examples/logic.out ../examples/empty.out
	-diff ../examples/pi.out ../examples/empty.out
	-diff ../examples/printi.out ../examples/empty.out
	-diff ../examples/strtest.out ../examples/empty.out
	-diff ../examples/tri.out ../examples/empty.out
	-diff ../examples/upto.out ../examples/empty.out
	-diff ../examples/while.out ../examples/empty.out	

clean_examples:
	rm -f ../examples/ack.out
	rm -f ../examples/add.out
	rm -f ../examples/args.out
	rm -f ../examples/break.out
	rm -f ../examples/chrindex.out
	rm -f ../examples/cont.out
	rm -f ../examples/decl.out
	rm -f ../examples/div.out
	rm -f ../examples/downto.out
	rm -f ../examples/fib.out
	rm -f ../examples/gcd.out
	rm -f ../examples/gt.out
	rm -f ../examples/hello.out
	rm -f ../examples/if.out
	rm -f ../examples/intindex.out
	rm -f ../examples/local.out
	rm -f ../examples/logic.out
	rm -f ../examples/pi.out
	rm -f ../examples/printi.out
	rm -f ../examples/strtest.out	
	rm -f ../examples/tri.out
	rm -f ../examples/upto.out
	rm -f ../examples/while.out

install:: $(LANG)
	cp $(LANG) ..

clean::	clean_examples
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output *~
