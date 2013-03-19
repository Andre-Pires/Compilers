/* boot.c
 * bootstrap code to use with a C compiler.
 */
#ifdef underscore
#define env _env
#define prints _prints
#define readb _readb
#endif

extern char **env;
main(int argc)
{
  env = (char**)&argc;
  return _main();
}
void prints(char *s) { printf("%s", s); }
int readb() { return getchar(); }
