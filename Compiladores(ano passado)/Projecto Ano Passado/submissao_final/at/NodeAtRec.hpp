#ifndef _NODEATREC_HH_
#define _NODEATREC_HH_

#include "NodeUnary.hpp"

class NodeAtRec : public NodeUnary {
public:
	inline NodeAtRec(Node& arg1, int lineno = 0) : NodeUnary(arg1, lineno)
		{ }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEATREC_HH_ */
