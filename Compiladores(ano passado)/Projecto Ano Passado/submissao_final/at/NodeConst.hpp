#ifndef _NODECONST_HH_
#define _NODECONST_HH_

#include "Node.hpp"

class NodeConst : public Node {

public:
	inline NodeConst(int lineno = 0) : Node(lineno){}
	~NodeConst();
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODECONST_HH_ */
