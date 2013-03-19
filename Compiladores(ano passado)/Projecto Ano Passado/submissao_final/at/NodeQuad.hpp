#ifndef __NODEQUAD_HH_
#define __NODEQUAD_HH_

#include "NodeTernary.hpp"

class NodeQuad : public NodeTernary {
protected:
	Node *arg;
public:
	inline NodeQuad(Node& arg1, Node& arg2, Node& arg3, Node& arg4, int lineno = 0)
		: NodeTernary(arg1, arg2, arg3, lineno) { arg = &arg4; }
	~NodeQuad();
	inline Node& fourth() { return *arg; }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* __NODEQUAD_HH_ */
