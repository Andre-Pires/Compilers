#ifndef _NODELIT_HH_
#define _NODELIT_HH_

#include "NodeUnary.hpp"

class NodeLit : public NodeUnary {
public:
	inline NodeLit(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODELIT_HH_ */
