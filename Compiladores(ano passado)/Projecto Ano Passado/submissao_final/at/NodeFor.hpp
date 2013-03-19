#ifndef _NODEFOR_HH_
#define _NODEFOR_HH_

#include "NodeQuad.hpp"

class NodeFor : public NodeQuad {
public:
	inline NodeFor(Node& arg1, Node& arg2, Node& arg3, Node& arg4, int lineno = 0) :
		NodeQuad(arg1, arg2, arg3, arg4, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEFOR_HH_ */
