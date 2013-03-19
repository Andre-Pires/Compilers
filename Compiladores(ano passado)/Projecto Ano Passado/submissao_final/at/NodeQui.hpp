#ifndef __NODEQUI_HH_
#define __NODEQUI_HH_

#include "NodeQuad.hpp"

class NodeQui : public NodeQuad {
protected:
	Node *arg;
public:
	inline NodeQui(Node& arg1, Node& arg2, Node& arg3, Node& arg4, Node& arg5, int lineno = 0)
		: NodeQuad(arg1, arg2, arg3, arg4, lineno) { arg = &arg5; }
	~NodeQui();
	inline Node& fifth() { return *arg; }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* __NODEQUI_HH_ */
