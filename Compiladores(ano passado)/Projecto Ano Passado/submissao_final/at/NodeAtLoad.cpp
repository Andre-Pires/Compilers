#include "NodeAtLoad.hpp"

void NodeAtLoad::accept(Compiler& c) { c.nodeAtLoad(*this); }
NodeAtLoad::~NodeAtLoad() { }
void NodeAtLoad::print(std::ostream *out) {
	if (out) (*out) << "NodeAtLoad: ";
	Node::print(out);
}
