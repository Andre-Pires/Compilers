#ifndef _NODEBLOCK_HH_
#define _NODEBLOCK_HH_

#include "NodeBinary.hpp"

class NodeBlock : public NodeBinary {
public:
	inline NodeBlock(Node& arg1, Node& arg2, int lineno = 0) :
		NodeBinary (arg1, arg2, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEBLOCK_HH_ */
