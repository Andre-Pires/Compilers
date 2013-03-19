#include "NodeIndLst.hpp"

void NodeIndLst::accept(Compiler& c) { c.nodeIndLst(*this); }
void NodeIndLst::print(std::ostream *out) {
	if (out) (*out) << "NodeIndLst: ";
	NodeUnary::print(out);
	arg->print(out);
}
