LANG=factorial
EXT=fac

LEX=flex -l
YACC=byacc -dv

$(LANG): $(LANG).y $(LANG).l
	$(YACC) $(LANG).y
	$(LEX) $(LANG).l
	make -C ../lib
	gcc -o $(LANG) -DYYDEBUG=1 -I../lib lex.yy.c y.tab.c ../lib/libutil.a

examples: clean_examples run_examples

exampleack: clean_examples
	-YYDEBUG=1 ./factorial ../examples/ack.fac > ../examples/ack.out

exampleint: clean_examples
	-YYDEBUG=1 ./factorial ../examples/intindex.fac > ../examples/intindex.out

run_examples: 
	-YYDEBUG=1 ./factorial ../examples/ack.fac > ../examples/ack.out
	-YYDEBUG=1 ./factorial ../examples/add.fac > ../examples/add.out
	-YYDEBUG=1 ./factorial ../examples/args.fac > ../examples/args.out
	-YYDEBUG=1 ./factorial ../examples/break.fac > ../examples/break.out
	-YYDEBUG=1 ./factorial ../examples/chrindex.fac > ../examples/chrindex.out
	-YYDEBUG=1 ./factorial ../examples/cont.fac > ../examples/cont.out
	-YYDEBUG=1 ./factorial ../examples/decl.fac > ../examples/decl.out
	-YYDEBUG=1 ./factorial ../examples/div.fac > ../examples/div.out
	-YYDEBUG=1 ./factorial ../examples/downto.fac > ../examples/downto.out
	-YYDEBUG=1 ./factorial ../examples/fib.fac > ../examples/fib.out
	-YYDEBUG=1 ./factorial ../examples/gcd.fac > ../examples/gcd.out
	-YYDEBUG=1 ./factorial ../examples/gt.fac > ../examples/gt.out
	-YYDEBUG=1 ./factorial ../examples/hello.fac > ../examples/hello.out
	-YYDEBUG=1 ./factorial ../examples/if.fac > ../examples/if.out
	-YYDEBUG=1 ./factorial ../examples/intindex.fac > ../examples/intindex.out
	-YYDEBUG=1 ./factorial ../examples/local.fac > ../examples/local.out
	-YYDEBUG=1 ./factorial ../examples/logic.fac > ../examples/logic.out
	-YYDEBUG=1 ./factorial ../examples/pi.fac > ../examples/pi.out
	-YYDEBUG=1 ./factorial ../examples/printi.fac > ../examples/printi.out
	-YYDEBUG=1 ./factorial ../examples/strtest.fac > ../examples/strtest.out	
	-YYDEBUG=1 ./factorial ../examples/tri.fac > ../examples/tri.out
	-YYDEBUG=1 ./factorial ../examples/upto.fac > ../examples/upto.out
	-YYDEBUG=1 ./factorial ../examples/while.fac > ../examples/while.out
	
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

install: $(LANG)
	cp $(LANG) ..

clean:
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output *~
