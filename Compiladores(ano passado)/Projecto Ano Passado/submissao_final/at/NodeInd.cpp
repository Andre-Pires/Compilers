#include "NodeInd.hpp"

void NodeInd::accept(Compiler& c) { c.nodeInd(*this); }
void NodeInd::print(std::ostream *out) {
	if (out) (*out) << "NodeInd: ";
	NodeUnary::print(out);
}
