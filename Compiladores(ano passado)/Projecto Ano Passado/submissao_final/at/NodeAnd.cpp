#include "NodeAnd.hpp"

void NodeAnd::accept(Compiler& c) { c.nodeAnd(*this); }
void NodeAnd::print(std::ostream *out) {
	if (out) (*out) << "NodeAnd: ";
	NodeBinary::print(out);
}
