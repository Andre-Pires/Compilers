#include "NodeSectList.hpp"

void NodeSectList::accept(Compiler& c) { c.nodeSectList(*this); }
void NodeSectList::print(std::ostream *out) {
	if (out) (*out) << "NodeSectList: ";
	NodeTernary::print(out);
}
