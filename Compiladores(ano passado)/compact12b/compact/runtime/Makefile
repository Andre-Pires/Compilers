LIB=run
OS=$(ELF32)
SYS=elf32
CFLAGS=-g # -fno-stack-protector # em Ubunto
BOOT=libboot.a # bootstrap runtime for a C compiler
RUNTIME=lib$(LIB).a # stand-alone runtime

ELF32=linux.o apart.o sys.o
ELF64=linux64.o apart64.o sys64.o
WIN32=win.obj apart.obj

NASM=nasm -f$(SYS)
YACC=byacc
LEX=flex -l

all: $(RUNTIME) $(BOOT)

$(RUNTIME): dbl.o $(OS)
	ar crl $@ $?

$(BOOT): dbl.o lib.o boot.o
	ar crl $@ $?

dbl.o: dbl.c
	$(CC) $(CFLAGS) -DPOSTFIX -c $<

.SUFFIXES: .asm .obj
.asm.obj:
	$(NASM) $<
.asm.o:
	$(NASM) $<
clean:
	rm -f $(RUNTIME) $(BOOT) *.o a.out core
