#include "NodeQual.hpp"

void NodeQual::accept(Compiler& c) { c.nodeQual(*this); }
void NodeQual::print(std::ostream *out) {
	if (out) (*out) << "NodeQual: ";
	NodeUnary::print(out);
}
