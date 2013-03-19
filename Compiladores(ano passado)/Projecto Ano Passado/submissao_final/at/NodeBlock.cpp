#include "NodeBlock.hpp"

void NodeBlock::accept(Compiler& c) { c.nodeBlock(*this); }
void NodeBlock::print(std::ostream *out) {
	if (out) (*out) << "NodeBlock: ";
	NodeBinary::print(out);
}
