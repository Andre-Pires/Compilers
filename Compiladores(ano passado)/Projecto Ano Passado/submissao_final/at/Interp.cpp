#include "Interp.hpp"
#include "Node.hpp"
#include "NodeInteger.hpp"
#include "NodeVariable.hpp"
#include "NodeString.hpp"
#include "NodeReal.hpp"
#include "NodeList.hpp"
#include "NodePrint.hpp"
#include "NodeUnary.hpp"
#include "NodeBinary.hpp"
#include "NodeTernary.hpp"
#include "NodeQuad.hpp"
#include "NodePrintLine.hpp"
#include "NodeIf.hpp"
#include "NodeIfelse.hpp"
#include "NodeAssign.hpp"
#include "NodeUminus.hpp"
#include "NodeUplus.hpp"
#include "NodeAdd.hpp"
#include "NodeSub.hpp"
#include "NodeMul.hpp"
#include "NodeDiv.hpp"
#include "NodeMod.hpp"
#include "NodeEq.hpp"
#include "NodeNe.hpp"
#include "NodeGt.hpp"
#include "NodeGe.hpp"
#include "NodeLt.hpp"
#include "NodeLe.hpp"
#include "NodeNe.hpp"
#include "NodeAnd.hpp"
#include "NodeOr.hpp"
#include "NodeNot.hpp"
#include "NodePow.hpp"
#include "NodeAddr.hpp"
#include "NodeFor.hpp"
#include "NodeVar.hpp"
#include "NodeVarAt.hpp"
#include "NodeFunc.hpp"
#include "NodeQui.hpp"
#include "NodeType.hpp"
#include "NodeAlloc.hpp"
#include "NodeAccess.hpp"
#include "NodeStop.hpp"
#include "NodeReturn.hpp"
#include "NodeNext.hpp"
#include "NodeIfLst.hpp"
#include "NodeSect.hpp"
#include "NodeSectList.hpp"
#include "NodeBlock.hpp"
#include "NodeCallFunc.hpp"
#include "NodeQual.hpp"
#include "NodeAtAssign.hpp"
#include "NodeAtRec.hpp"
#include "NodeAtLoad.hpp"
#include "NodeBody.hpp"
#include "NodeElif.hpp"
#include "NodeTrue.hpp"
#include "NodeQuad.hpp"
#include "NodeConst.hpp"
#include "NodeInd.hpp"
#include "NodeIndLst.hpp"
#include "NodeIfLstFin.hpp"
#include "NodeLit.hpp"

#include "SymbolNode.hpp"

bool Interp::parse() {
	if (parser->parse() == 0)
		tree(parser->syntax());
	// tree()->print(&cout);
	return parser->errors() == 0;
}
bool Interp::generate() {
	if (parser->errors() > 0) return false;
	tree()->accept(*this);
	vars.put("_at", new SymbolNode());
	return true;
}

void Interp::node(Node& n) {}
void Interp::nodeInteger(NodeInteger& n) { stk.push(n.integer()); }
void Interp::nodeString(NodeString& n) { std::cout << n.text() << "\n"; }
void Interp::nodeVariable(NodeVariable& n) {
	stk.push(((SymbolNode*)vars.get(n.text()))->integer());
}
void Interp::nodeReal(NodeReal& n) {}
void Interp::nodeList(NodeList& n) {
	for (int i = 0; i < n.size(); i++)
		n.elementAt(i).accept(*this);
}
void Interp::nodePrint(NodePrint& n) {
	n.first().accept(*this); // eval condition to TOS
	std::cout << pop();
}

void Interp::nodeUnary(NodeUnary& n) {}
void Interp::nodeBinary(NodeBinary& n) {}
void Interp::nodeTernary(NodeTernary& n) {}
void Interp::nodeQuad(NodeQuad& n) {}
void Interp::nodeQui(NodeQui& n) {}

void Interp::nodePrintLine(NodePrintLine& n) {
	n.first().accept(*this); // eval condition to TOS
	std::cout << pop() << "\n";
}

void Interp::nodeIf(NodeIf& n) {
	n.first().accept(*this); // eval condition to TOS
	if (pop() != 0)
		n.second().accept(*this); // eval instruction
}

void Interp::nodeIfelse(NodeIfelse& n) {
	n.first().accept(*this);
	if (pop() != 0)
		n.second().accept(*this);
	else
		n.third().accept(*this);
}	

void Interp::nodeAssign(NodeAssign& n) {
	n.second().accept(*this); // eval expression to TOS
	vars.put(((NodeString*)&n.first())->text(), new SymbolNode(pop()));
}

void Interp::nodeUminus(NodeUminus& n) {
	n.first().accept(*this); // eval condition to TOS
	stk.push(-pop());
}

void Interp::nodeUplus(NodeUplus& n) {
	n.first().accept(*this); // eval condition to TOS
	stk.push(+pop());
}

void Interp::nodeAdd(NodeAdd& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 + arg2);
}

void Interp::nodeSub(NodeSub& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 - arg2);
}

void Interp::nodeMul(NodeMul& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 * arg2);
}

void Interp::nodeDiv(NodeDiv& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 / arg2);
}

void Interp::nodeMod(NodeMod& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 % arg2);
}

void Interp::nodeLt(NodeLt& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 < arg2);
}

void Interp::nodeGt(NodeGt& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 > arg2);
}

void Interp::nodeGe(NodeGe& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 >= arg2);
}

void Interp::nodeLe(NodeLe& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 <= arg2);
}

void Interp::nodeNe(NodeNe& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 != arg2);
}

void Interp::nodeEq(NodeEq& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 == arg2);
}

void Interp::nodeAnd(NodeAnd& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 && arg2);
}

void Interp::nodeOr(NodeOr& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(arg1 || arg2);
}

void Interp::nodeNot(NodeNot& n) {
	n.first().accept(*this); // eval condition to TOS
	stk.push(!(pop()));
}

void Interp::nodePow(NodePow& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	stk.push(pow(arg1, arg2));
	
}

void Interp::nodeAddr(NodeAddr& n) {
	
}

void Interp::nodeFor(NodeFor& n) {
	n.first().accept(*this);
	pop();
	n.second().accept(*this);
	for(; pop() != 0; n.third().accept(*this)) {
		pop();		
		n.fourth().accept(*this);
		stk.push(pop());
		n.second().accept(*this);
	}
}

void Interp::nodeVar(NodeVar& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	n.first().accept(*this); // eval condition to TOS
	int arg3 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg4 = pop();
	
}

void Interp::nodeVarAt(NodeVarAt& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	n.third().accept(*this); // eval condition to TOS
	int arg3 = pop();
	n.fourth().accept(*this); // eval expression to TOS
	int arg4 = pop();
}

void Interp::nodeFunc(NodeFunc& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	n.third().accept(*this); // eval condition to TOS
	int arg3 = pop();
	n.fourth().accept(*this); // eval expression to TOS
	int arg4 = pop();
	n.fifth().accept(*this); // eval expression to TOS
	int arg5 = pop();
}

void Interp::nodeType(NodeType& n) {
}

void Interp::nodeAlloc(NodeAlloc& n) {
	
}

void Interp::nodeAccess(NodeAccess& n) {
	
}

void Interp::nodeInd(NodeInd& n) {}

void Interp::nodeIndLst(NodeIndLst& n) {}

void Interp::nodeStop(NodeStop& n) {}

void Interp::nodeReturn(NodeReturn& n) {}

void Interp::nodeNext(NodeNext& n) {}

void Interp::nodeIfLst(NodeIfLst& n) {
	n.first().accept(*this);
	if (pop() != 0)
		n.second().accept(*this);
	n.third().accept(*this);	
}

void Interp::nodeSect(NodeSect& n) {
	
}

void Interp::nodeSectList(NodeSectList& n) {
	
}

void Interp::nodeQual(NodeQual& n) {
	
}

void Interp::nodeBlock(NodeBlock& n) {
	
}

void Interp::nodeBody(NodeBody& n) {
	n.first().accept(*this); // eval condition to TOS
	int arg1 = pop();
	n.second().accept(*this); // eval expression to TOS
	int arg2 = pop();
	n.third().accept(*this); // eval condition to TOS
	int arg3 = pop();
	n.fourth().accept(*this); // eval expression to TOS
	int arg4 = pop();
}

void Interp::nodeElif(NodeElif& n) {
	
}

void Interp::nodeAtRec(NodeAtRec& n) {
	n.first().accept(*this);
}

void Interp::nodeAtAssign(NodeAtAssign& n) {
	n.first().accept(*this); // eval condition to TOS
}

void Interp::nodeAtLoad(NodeAtLoad& n) {
	int val;
	std::cin >> val;
	stk.push(val);
}

void Interp::nodeCallFunc(NodeCallFunc& n) {
	n.second().accept(*this);
}

void Interp::nodeTrue(NodeTrue& n) {
	stk.push(1);
}

void Interp::nodeConst(NodeConst& n) {

}

void Interp::nodeIfLstFin(NodeIfLstFin& n) {

}

void Interp::nodeLit(NodeLit& n) {

}
