#ifndef _NODEFUNC_HH_
#define _NODEFUNC_HH_

#include "NodeQui.hpp"

class NodeFunc : public NodeQui {
public:
	inline NodeFunc(Node& arg1, Node& arg2, Node& arg3, Node& arg4, Node& arg5, int lineno = 0) :
		NodeQui (arg1, arg2, arg3, arg4, arg5, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEFUNC_HH_ */
