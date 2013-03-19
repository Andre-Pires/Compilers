#include "NodeQuad.hpp"

void NodeQuad::accept(Compiler& c) { c.nodeQuad(*this); }
NodeQuad::~NodeQuad() { delete arg; }
void NodeQuad::print(std::ostream *out) {
	if (out) (*out) << "NodeQuad: ";
	NodeTernary::print(out);
	arg->print(out);;
}
