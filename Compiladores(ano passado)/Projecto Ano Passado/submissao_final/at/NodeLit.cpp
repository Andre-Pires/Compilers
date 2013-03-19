#include "NodeLit.hpp"

void NodeLit::accept(Compiler& c) { c.nodeLit(*this); }
void NodeLit::print(std::ostream *out) {
	if (out) (*out) << "NodeLit: ";
	NodeUnary::print(out);
}
