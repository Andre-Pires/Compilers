#ifndef _NODENEXT_HH_
#define _NODENEXT_HH_

#include "Node.hpp"

class NodeNext : public Node {

public:
	inline NodeNext(int lineno = 0) : Node(lineno){}
	~NodeNext();
	void accept(Compiler& c);
	void print(std::ostream *out = 0);
};
#endif /* _NODENEXT_HH_ */
