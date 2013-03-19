#include "NodeAlloc.hpp"

void NodeAlloc::accept(Compiler& c) { c.nodeAlloc(*this); }
void NodeAlloc::print(std::ostream *out) {
	if (out) (*out) << "NodeAlloc: ";
	NodeBinary::print(out);
}
