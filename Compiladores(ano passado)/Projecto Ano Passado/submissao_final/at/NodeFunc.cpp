#include "NodeFunc.hpp"

void NodeFunc::accept(Compiler& c) { c.nodeFunc(*this); }
void NodeFunc::print(std::ostream *out) {
	if (out) (*out) << "NodeVarAt: ";
	NodeQui::print(out);
}
