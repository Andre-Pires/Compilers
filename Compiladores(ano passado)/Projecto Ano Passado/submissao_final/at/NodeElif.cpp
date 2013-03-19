#include "NodeElif.hpp"

void NodeElif::accept(Compiler& c) { c.nodeElif(*this); }
void NodeElif::print(std::ostream *out) {
	if (out) (*out) << "NodeElif: ";
	NodeQuad::print(out);
}
