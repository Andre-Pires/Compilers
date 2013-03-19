#ifndef _NODEPRINTLINE_HH_
#define _NODEPRINTLINE_HH_

#include "NodeUnary.hpp"

class NodePrintLine : public NodeUnary {
public:
	inline NodePrintLine(Node& arg1, int lineno = 0) :
		NodeUnary(arg1, lineno) { }
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODEPRINTLINE_HH_ */
