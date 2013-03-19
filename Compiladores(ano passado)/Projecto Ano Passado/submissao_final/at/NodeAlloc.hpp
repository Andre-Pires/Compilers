#ifndef _NODEALLOC_HH_
#define _NODEALLOC_HH_

#include "NodeBinary.hpp"

class NodeAlloc : public NodeBinary {
public:
	inline NodeAlloc(Node& arg1, Node& arg2, int lineno = 0) :
		NodeBinary(arg1, arg2, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEALLOC_HH_ */
