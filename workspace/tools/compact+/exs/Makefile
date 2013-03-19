BIN=../final/compact
RUN=../run/librun.a
EXT=.cpt
#LD=-m elf_i386

.SUFFIXES: $(EXT) .asm
LOADLIBS=$(RUN)
NASM=nasm -felf32

all:
	for i in *$(EXT); do $(MAKE) $(MFLAGS) `basename $$i $(EXT)`; done

.asm.o:
	$(NASM) $< -o $@

%:%.o
	$(LD) $< $(RUN) -o $@

$(EXT).asm:
	$(BIN) $<

clean:
	rm -f *.o core a.out *.asm *~
	for i in *$(EXT); do rm -f `basename $$i $(EXT)`; done

.PHONY: all clean
