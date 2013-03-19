#include "NodeUplus.hpp"

void NodeUplus::accept(Compiler& c) { c.nodeUplus(*this); }
void NodeUplus::print(std::ostream *out) {
	if (out) (*out) << "NodeUplus: ";
	NodeUnary::print(out);
}
