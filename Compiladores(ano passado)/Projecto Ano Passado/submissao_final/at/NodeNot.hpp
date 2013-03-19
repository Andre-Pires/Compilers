#ifndef _NODENOT_HH_
#define _NODENOT_HH_

#include "NodeUnary.hpp"

class NodeNot : public NodeUnary {
public:
	inline NodeNot(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODENOT_HH_ */
