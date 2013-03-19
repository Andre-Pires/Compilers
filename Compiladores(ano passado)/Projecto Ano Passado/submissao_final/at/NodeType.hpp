#ifndef _NODETYPE_HH_
#define _NODETYPE_HH_

#include "NodeUnary.hpp"

class NodeType : public NodeUnary {
public:
	inline NodeType(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODETYPE_HH_ */
