#include "NodeReturn.hpp"

void NodeReturn::accept(Compiler& c) { c.nodeReturn(*this); }
NodeReturn::~NodeReturn() { }
void NodeReturn::print(std::ostream *out) {
	if (out) (*out) << "NodeReturn: ";
	Node::print(out);
}
