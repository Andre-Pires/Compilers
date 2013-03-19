#ifndef _NODEAND_HH_
#define _NODEAND_HH_

#include "NodeBinary.hpp"

class NodeAnd : public NodeBinary {
public:
	inline NodeAnd(Node& arg1, Node& arg2, int lineno = 0) :
		NodeBinary (arg1, arg2, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEAND_HH_ */
