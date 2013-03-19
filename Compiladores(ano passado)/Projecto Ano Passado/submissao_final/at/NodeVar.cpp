#include "NodeVar.hpp"

void NodeVar::accept(Compiler& c) { c.nodeVar(*this); }
void NodeVar::print(std::ostream *out) {
	if (out) (*out) << "NodeVar: ";
	NodeQuad::print(out);
}
