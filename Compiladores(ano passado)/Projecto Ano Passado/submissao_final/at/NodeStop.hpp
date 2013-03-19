#ifndef _NODESTOP_HH_
#define _NODESTOP_HH_

#include "Node.hpp"

class NodeStop : public Node {

public:
	inline NodeStop(int lineno = 0) : Node(lineno){}
	~NodeStop();
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODESTOP_HH_ */
