#include "NodeNot.hpp"

void NodeNot::accept(Compiler& c) { c.nodeNot(*this); }
void NodeNot::print(std::ostream *out) {
	if (out) (*out) << "NodeNot: ";
	NodeUnary::print(out);
}
