#ifndef _NODEQUAL_HH_
#define _NODEQUAL_HH_

#include "NodeUnary.hpp"

class NodeQual : public NodeUnary {
public:
	inline NodeQual(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEQUAL_HH_ */
