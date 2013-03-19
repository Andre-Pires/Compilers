#ifndef _NODETRUE_HH_
#define _NODETRUE_HH_

#include "Node.hpp"

class NodeTrue : public Node {

public:
	inline NodeTrue(int lineno = 0) : Node(lineno){}
	~NodeTrue();
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODETRUE_HH_ */
