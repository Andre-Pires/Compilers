#include "NodeQui.hpp"

void NodeQui::accept(Compiler& c) { c.nodeQui(*this); }
NodeQui::~NodeQui() { delete arg; }
void NodeQui::print(std::ostream *out) {
	if (out) (*out) << "NodeQui: ";
	NodeQuad::print(out);
	arg->print(out);;
}
