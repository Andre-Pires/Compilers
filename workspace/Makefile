# Makefile do factorial - primeira fase

LANG=factorial
EXT=fac

all: clean $(LANG)

$(LANG): $(LANG).y $(LANG).l
	byacc -dv factorial.y
	flex -l $(LANG).l
	gcc -o $(LANG) -I../lib lex.yy.c y.tab.c


tests: clean_tests
	./yak < ../testes/1.yak > ../testes/1.out
	./yak < ../testes/2.yak > ../testes/2.out
	./yak < ../testes/3.yak > ../testes/3.out
	./yak < ../testes/4.yak > ../testes/4.out
	./yak < ../testes/ack.yak > ../testes/ack.out
	./yak < ../testes/bubble.yak > ../testes/bubble.out
	./yak < ../testes/cmp.yak > ../testes/cmp.out
	./yak < ../testes/div.yak > ../testes/div.out
	./yak < ../testes/fib.yak > ../testes/fib.out
	./yak < ../testes/fit.yak > ../testes/fit.out
	./yak < ../testes/gcd.yak > ../testes/gcd.out
	./yak < ../testes/hello.yak > ../testes/hello.out
	./yak < ../testes/histograma.yak > ../testes/histograma.out
	./yak < ../testes/powfunc.yak > ../testes/powfunc.out
	./yak < ../testes/sort.yak > ../testes/sort.out
	./yak < ../testes/testfit.yak > ../testes/testfit.out
	./yak < ../testes/tri.yak > ../testes/tri.out


clean_tests:
	rm -f ../testes/*.out


clean:	clean_tests
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output *.$(EXT)

clean_zip: 
	rm -f proj.zip

zip: 	clean_zip
	zip proj.zip Makefile yak.l yak.y

