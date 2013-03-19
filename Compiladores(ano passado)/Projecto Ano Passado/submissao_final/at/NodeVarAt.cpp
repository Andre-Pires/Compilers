#include "NodeVarAt.hpp"

void NodeVarAt::accept(Compiler& c) { c.nodeVarAt(*this); }
void NodeVarAt::print(std::ostream *out) {
	if (out) (*out) << "NodeVarAt: ";
	NodeQui::print(out);
}
