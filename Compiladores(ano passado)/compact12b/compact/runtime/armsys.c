/* armsys.c
 * bootstrap code to use with gnuarm.
 *
 * arm-elf-as -mfloat-abi=soft ex.asm -o ex.o
 * arm-elf-gcc -Dunderscore ../runtime/lib.c ../runtime/armsys.c div.o -o div.exe
 * arm-elf-run div.exe
 */
#ifdef underscore
#define env _env
#define prints _prints
#define readb _readb
#endif

int printf(const char*, ...), getchar();

extern char **_env;
main(int argc)
{
  _env = (char**)&argc;
  return _main();
}
void prints(char *s) { printf("%s", s); }
int readb() { return getchar(); }
int _mod(int a, int b) { return b % a; }
int _div(int a, int b) { return b / a; }
