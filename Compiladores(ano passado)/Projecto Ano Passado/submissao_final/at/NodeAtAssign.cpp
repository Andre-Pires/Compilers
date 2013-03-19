#include "NodeAtAssign.hpp"

void NodeAtAssign::accept(Compiler& c) { c.nodeAtAssign(*this); }
void NodeAtAssign::print(std::ostream *out) {
	if (out) (*out) << "NodeAtAssign: ";
	NodeUnary::print(out);
}
