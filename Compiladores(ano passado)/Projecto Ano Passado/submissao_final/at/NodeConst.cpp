#include "NodeConst.hpp"

void NodeConst::accept(Compiler& c) { c.nodeConst(*this); }
NodeConst::~NodeConst() { }
void NodeConst::print(std::ostream *out) {
	if (out) (*out) << "NodeConst: ";
	Node::print(out);
}
