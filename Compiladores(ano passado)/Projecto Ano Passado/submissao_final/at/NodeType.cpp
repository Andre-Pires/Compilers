#include "NodeType.hpp"

void NodeType::accept(Compiler& c) { c.nodeType(*this); }
void NodeType::print(std::ostream *out) {
	if (out) (*out) << "NodeType: ";
	NodeUnary::print(out);
}
