#include "NodeSect.hpp"

void NodeSect::accept(Compiler& c) { c.nodeSect(*this); }
void NodeSect::print(std::ostream *out) {
	if (out) (*out) << "NodeSect: ";
	NodeBinary::print(out);
}
