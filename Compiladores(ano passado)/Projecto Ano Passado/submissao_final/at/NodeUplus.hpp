#ifndef _NODEUPLUS_HH_
#define _NODEUPLUS_HH_

#include "NodeUnary.hpp"

class NodeUplus : public NodeUnary {
public:
	inline NodeUplus(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEUPLUS_HH_ */
