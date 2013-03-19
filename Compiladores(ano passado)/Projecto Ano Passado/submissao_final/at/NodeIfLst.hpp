#ifndef _NODEIFLST_HH_
#define _NODEIFLST_HH_

#include "NodeTernary.hpp"

class NodeIfLst : public NodeTernary {
public:
	inline NodeIfLst(Node& arg1, Node& arg2, Node& arg3, int lineno = 0)
		: NodeTernary(arg1, arg2, arg3, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEIFLST_HH_ */
