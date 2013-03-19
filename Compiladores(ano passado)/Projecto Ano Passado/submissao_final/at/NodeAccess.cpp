#include "NodeAccess.hpp"

void NodeAccess::accept(Compiler& c) { c.nodeAccess(*this); }
void NodeAccess::print(std::ostream *out) {
	if (out) (*out) << "NodeAccess: ";
	NodeBinary::print(out);
}
