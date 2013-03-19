#include "NodeOr.hpp"

void NodeOr::accept(Compiler& c) { c.nodeOr(*this); }
void NodeOr::print(std::ostream *out) {
	if (out) (*out) << "NodeOr: ";
	NodeBinary::print(out);
}
