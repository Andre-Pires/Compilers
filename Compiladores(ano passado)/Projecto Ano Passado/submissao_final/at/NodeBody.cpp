#include "NodeBody.hpp"

void NodeBody::accept(Compiler& c) { c.nodeBody(*this); }
void NodeBody::print(std::ostream *out) {
	if (out) (*out) << "NodeBody: ";
	NodeQuad::print(out);
}
