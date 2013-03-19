#include "NodeAddr.hpp"

void NodeAddr::accept(Compiler& c) { c.nodeAddr(*this); }
void NodeAddr::print(std::ostream *out) {
	if (out) (*out) << "NodeAddr: ";
	NodeUnary::print(out);
}
