#ifndef _NODEATLOAD_HH_
#define _NODEATLOAD_HH_

#include "Node.hpp"

class NodeAtLoad : public Node {

public:
	inline NodeAtLoad(int lineno = 0) : Node(lineno){}
	~NodeAtLoad();
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEATLOAD_HH_ */
