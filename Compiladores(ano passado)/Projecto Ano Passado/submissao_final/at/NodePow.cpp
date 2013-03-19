#include "NodePow.hpp"

void NodePow::accept(Compiler& c) { c.nodePow(*this); }
void NodePow::print(std::ostream *out) {
	if (out) (*out) << "NodePow: ";
	NodeBinary::print(out);
}
