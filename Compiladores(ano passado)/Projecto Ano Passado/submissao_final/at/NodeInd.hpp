#ifndef _NODEIND_HH_
#define _NODEIND_HH_

#include "NodeUnary.hpp"

class NodeInd : public NodeUnary {
public:
	inline NodeInd(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEIND_HH_ */
