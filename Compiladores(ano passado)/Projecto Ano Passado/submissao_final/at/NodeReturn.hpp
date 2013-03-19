#ifndef _NODERETURN_HH_
#define _NODERETURN_HH_

#include "Node.hpp"

class NodeReturn : public Node {

public:
	inline NodeReturn(int lineno = 0) : Node(lineno){}
	~NodeReturn();
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODERETURN_HH_ */
