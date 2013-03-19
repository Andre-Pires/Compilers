#include "NodeIfLst.hpp"

void NodeIfLst::accept(Compiler& c) { c.nodeIfLst(*this); }
void NodeIfLst::print(std::ostream *out) {
	if (out) (*out) << "NodeIfLst: ";
	NodeTernary::print(out);
}
