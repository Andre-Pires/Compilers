#ifndef _NODEIFLSTFIN_HH_
#define _NODEIFLSTFIN_HH_

#include "NodeTernary.hpp"

class NodeIfLstFin : public NodeTernary {
public:
	inline NodeIfLstFin(Node& arg1, Node& arg2, Node& arg3, int lineno = 0)
		: NodeTernary(arg1, arg2, arg3, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEIFLSTFIN_HH_ */
