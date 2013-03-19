LANG=compact
EXT=cpt
.SUFFIXES: .$(EXT) .asm .obj .exe

$(LANG): $(LANG).y $(LANG).l $(LANG).brg
	byacc -dv $(LANG).y
	flex -l $(LANG).l
	pburg -R -p code $(LANG).brg code.c
	gcc -o $(LANG) -Wall -DYYDEBUG -I../lib lex.yy.c y.tab.c code.c ../lib/libutil.a

$(LANG).exe: $(LANG).y $(LANG).l $(LANG).brg
	byacc -dv $(LANG).y
	flex -l $(LANG).l
	pburg -R -p code $(LANG).brg code.c
	cl /nologo /Fe$(LANG).exe /DWIN32 /Zi /MLd /DYYDEBUG /I..\\lib lex.yy.c y.tab.c code.c ..\\lib\\util.lib

%:%.$(EXT)
	./$(LANG) $<
	nasm -felf $*.asm
	ld -o $@ $*.o -L../runtime -lrun

.$(EXT).exe:
	./$(LANG) $<
	nasm -fwin32 $*.asm
	link /nologo /out:$@ $*.obj /LIBPATH:..\\runtime run.lib KERNEL32.LIB


clean:
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output code.c *.asm *.$(EXT) *~ *.obj *.exe *.ilk *.pdb
