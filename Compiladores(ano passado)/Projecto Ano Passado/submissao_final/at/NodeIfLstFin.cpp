#include "NodeIfLstFin.hpp"

void NodeIfLstFin::accept(Compiler& c) { c.nodeIfLstFin(*this); }
void NodeIfLstFin::print(std::ostream *out) {
	if (out) (*out) << "NodeIfLstFin: ";
	NodeTernary::print(out);
}
