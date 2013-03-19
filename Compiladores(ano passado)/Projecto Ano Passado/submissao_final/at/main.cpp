#include <cstring>
#include <string>
#define String std::string
#include "Compiler.hpp"
#include "At.hpp"
#include "Interp.hpp"

int main(int argc, char *argv[]) {
  Compiler *compiler;
/*
  if (argc > 1)
  	compiler = new At(String(argv[1]));
	String(argv[2]) << compiler;
  else if(argc == 1)
  	compiler = new At(String(argv[1]));
  	 << compiler;
  else 
  	std::cout << compiler;
*/
  if (argc > 1 && strcmp(argv[1], "-I") == 0)
	if (argc > 2)
  		compiler = new Interp(String(argv[2]));
	else
		compiler = new Interp(&std::cin);
  else
  	compiler = new At(String(argv[1]));

  if (compiler->parse() == false) return 2;
  int ret = compiler->generate() == false;

  delete compiler;
  return ret;
}
