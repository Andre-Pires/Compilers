#include "NodePrintLine.hpp"

void NodePrintLine::accept(Compiler& c) { c.nodePrintLine(*this); }
void NodePrintLine::print(std::ostream *out) {
	if (out) (*out) << "NodePrintLine: ";
	NodeUnary::print(out);
}
