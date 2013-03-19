#ifndef _NODEADDR_HH_
#define _NODEADDR_HH_

#include "NodeUnary.hpp"

class NodeAddr : public NodeUnary {
public:
	inline NodeAddr(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEADDR_HH_ */
