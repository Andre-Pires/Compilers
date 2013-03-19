#ifndef _NODEINDLST_HH_
#define _NODEINDLST_HH_

#include "NodeBinary.hpp"

class NodeIndLst : public NodeBinary {
protected:
	Node *arg;
public:
	inline NodeIndLst(Node& arg1, Node& arg2, int lineno = 0) :
		NodeBinary(arg1, arg2, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEINDLST_HH_ */
