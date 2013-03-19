#include "NodeNext.hpp"

void NodeNext::accept(Compiler& c) { c.nodeNext(*this); }
NodeNext::~NodeNext() { }
void NodeNext::print(std::ostream *out) {
	if (out) (*out) << "NodeNext: ";
	Node::print(out);
}
