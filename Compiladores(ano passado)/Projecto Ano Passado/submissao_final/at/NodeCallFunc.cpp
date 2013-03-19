#include "NodeCallFunc.hpp"

void NodeCallFunc::accept(Compiler& c) { c.nodeCallFunc(*this); }
void NodeCallFunc::print(std::ostream *out) {
	if (out) (*out) << "NodeCallFunc: ";
	NodeBinary::print(out);
}
