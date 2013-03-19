#ifndef _NODEATASSIGN_HH_
#define _NODEATASSIGN_HH_

#include "NodeUnary.hpp"

class NodeAtAssign : public NodeUnary {
public:
	inline NodeAtAssign(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEATASSIGN_HH_ */
