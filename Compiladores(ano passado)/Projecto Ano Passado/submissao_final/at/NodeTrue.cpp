#include "NodeTrue.hpp"

void NodeTrue::accept(Compiler& c) { c.nodeTrue(*this); }
NodeTrue::~NodeTrue() { }
void NodeTrue::print(std::ostream *out) {
	if (out) (*out) << "NodeTrue: ";
	Node::print(out);
}
