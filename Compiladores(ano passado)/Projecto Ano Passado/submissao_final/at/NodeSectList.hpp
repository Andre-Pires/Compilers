#ifndef _NODESECTLIST_HH_
#define _NODESECTLIST_HH_

#include "NodeTernary.hpp"

class NodeSectList : public NodeTernary {
public:
	inline NodeSectList(Node& arg1, Node& arg2, Node& arg3, int lineno = 0) :
		NodeTernary (arg1, arg2, arg3, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODESECTLIST_HH_ */
