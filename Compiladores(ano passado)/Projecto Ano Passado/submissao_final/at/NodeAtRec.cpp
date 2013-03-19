#include "NodeAtRec.hpp"

void NodeAtRec::accept(Compiler& c) { c.nodeAtRec(*this); }
void NodeAtRec::print(std::ostream *out) {
	if (out) (*out) << "NodeAtRec: ";
	NodeUnary::print(out);
}
