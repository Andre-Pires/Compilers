#include "NodeFor.hpp"

void NodeFor::accept(Compiler& c) { c.nodeFor(*this); }
void NodeFor::print(std::ostream *out) {
	if (out) (*out) << "NodeFor: ";
	NodeQuad::print(out);
}
