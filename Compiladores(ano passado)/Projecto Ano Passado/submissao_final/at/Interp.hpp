#include <cmath>
#include <stack>

#include "Compiler.hpp"
#include "Parser.hpp"
#include "Tabid.hpp"


class Interp : public Compiler {
	Parser *parser;
	std::stack<int> stk;
	Tabid vars;
protected:
	inline int pop() { int val = stk.top(); stk.pop(); return val; }
public:
	inline Interp(std::istream *in) { parser = new Parser(); }
	inline Interp(String infile) {
		parser = new Parser(new std::ifstream(infile.c_str()));
	}
	bool parse();
	bool generate();

	void node(Node& n);
	void nodeInteger(NodeInteger& n);
	void nodeVariable(NodeVariable& n);
	void nodeString(NodeString& n);
	void nodeReal(NodeReal& n);
	void nodeList(NodeList& n);
	void nodePrint(NodePrint& n);
	void nodeUnary(NodeUnary& n);
	void nodeBinary(NodeBinary& n);
	void nodeTernary(NodeTernary& n);
	void nodeQuad(NodeQuad& n);
	void nodePrintLine(NodePrintLine& n);
	void nodeIf(NodeIf& n);
	void nodeIfelse(NodeIfelse& n);
	void nodeAssign(NodeAssign& n);
	void nodeUplus(NodeUplus& n);
	void nodeUminus(NodeUminus& n);
	void nodeAdd(NodeAdd& n);
	void nodeSub(NodeSub& n);
	void nodeMul(NodeMul& n);
	void nodeDiv(NodeDiv& n);
	void nodeMod(NodeMod& n);
	void nodeGt(NodeGt& n);
	void nodeLt(NodeLt& n);
	void nodeGe(NodeGe& n);
	void nodeLe(NodeLe& n);
	void nodeNe(NodeNe& n);
	void nodeEq(NodeEq& n);
	void nodeAnd(NodeAnd& n);
	void nodeOr(NodeOr& n);
	void nodeNot(NodeNot& n);
	void nodePow(NodePow& n);
	void nodeAddr(NodeAddr& n);
	void nodeFor(NodeFor& n);
	void nodeVar(NodeVar& n);
	void nodeVarAt(NodeVarAt& n);
	void nodeFunc(NodeFunc& n);
	void nodeQui(NodeQui& n);
	void nodeType(NodeType& n);
	void nodeAlloc(NodeAlloc& n);
	void nodeInd(NodeInd& n);
	void nodeIndLst(NodeIndLst& n);
	void nodeAccess(NodeAccess& n);
	void nodeStop(NodeStop& n);
	void nodeReturn(NodeReturn& n);
	void nodeNext(NodeNext& n);
	void nodeIfLst(NodeIfLst& n);
	void nodeSect(NodeSect& n);
	void nodeCallFunc(NodeCallFunc& n);
	void nodeSectList(NodeSectList& n);
	void nodeQual(NodeQual& n);
	void nodeBlock(NodeBlock& n);
	void nodeBody(NodeBody& n);
	void nodeElif(NodeElif& n);
	void nodeAtRec(NodeAtRec& n);
	void nodeAtAssign(NodeAtAssign& n);
	void nodeAtLoad(NodeAtLoad& n);
	void nodeTrue(NodeTrue& n);
	void nodeConst(NodeConst& n);
	void nodeIfLstFin(NodeIfLstFin& n);
	void nodeLit(NodeLit& n);
};
