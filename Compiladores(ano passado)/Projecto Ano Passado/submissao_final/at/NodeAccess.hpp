#ifndef _NODEACCESS_HH_
#define _NODEACCESS_HH_

#include "NodeBinary.hpp"

class NodeAccess : public NodeBinary {
public:
	inline NodeAccess(Node& arg1, Node& arg2, int lineno = 0) :
		NodeBinary(arg1, arg2, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEACCESS_HH_ */
