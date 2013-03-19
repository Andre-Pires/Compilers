#include "NodeStop.hpp"

void NodeStop::accept(Compiler& c) { c.nodeStop(*this); }
NodeStop::~NodeStop() { }
void NodeStop::print(std::ostream *out) {
	if (out) (*out) << "NodeStop: ";
	Node::print(out);
}
