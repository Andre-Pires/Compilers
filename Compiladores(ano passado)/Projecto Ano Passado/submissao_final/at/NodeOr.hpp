#ifndef _NODEOR_HH_
#define _NODEOR_HH_

#include "NodeBinary.hpp"

class NodeOr : public NodeBinary {
public:
	inline NodeOr(Node& arg1, Node& arg2, int lineno = 0) :
		NodeBinary (arg1, arg2, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEOR_HH_ */
