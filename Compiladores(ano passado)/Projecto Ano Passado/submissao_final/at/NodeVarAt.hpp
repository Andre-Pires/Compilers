#ifndef _NODEVARAT_HH_
#define _NODEVARAT_HH_

#include "NodeQui.hpp"

class NodeVarAt : public NodeQui {
public:
	inline NodeVarAt(Node& arg1, Node& arg2, Node& arg3, Node& arg4, Node& arg5, int lineno = 0) :
		NodeQui (arg1, arg2, arg3, arg4, arg5, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEVARAT_HH_ */
