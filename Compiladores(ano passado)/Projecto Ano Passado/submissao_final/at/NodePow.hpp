#ifndef _NODEPOW_HH_
#define _NODEPOW_HH_

#include "NodeBinary.hpp"

class NodePow : public NodeBinary {
public:
	inline NodePow(Node& arg1, Node& arg2, int lineno = 0) :
		NodeBinary(arg1, arg2, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEPOW_HH_ */
