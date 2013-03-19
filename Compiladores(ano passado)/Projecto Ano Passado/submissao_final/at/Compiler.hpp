#ifndef _COMPILER_HH_
#define _COMPILER_HH_

#include <string>
#define String std::string

// forward declarations
class Node;
class NodeInteger;
class NodeVariable;
class NodeString;
class NodeReal;
class NodeList;
class NodePrint;
class NodeUnary;
class NodeBinary;
class NodeTernary;
class NodeQuad;
class NodePrintLine;
class NodeIf;
class NodeIfelse;
class NodeAssign;
class NodeUminus;
class NodeUplus;
class NodeAdd;
class NodeSub;
class NodeMul;
class NodeDiv;
class NodeMod;
class NodeGt;
class NodeLt;
class NodeGe;
class NodeLe;
class NodeNe;
class NodeEq;
class NodeAnd;
class NodeOr;
class NodeNot;
class NodePow;
class NodeAddr;
class NodeFor;

class NodeVar;
class NodeVarAt;
class NodeFunc;
class NodeQui;
class NodeType;
class NodeAlloc;
class NodeInd;
class NodeIndLst;
class NodeAccess;
class NodeStop;
class NodeReturn;
class NodeNext;
class NodeIfLst;
class NodeSect;
class NodeSectList;
class NodeQual;
class NodeCallFunc;
class NodeBlock;
class NodeBody;
class NodeElif;
class NodeAtRec;
class NodeAtAssign;
class NodeAtLoad;
class NodeTrue;
class NodeConst;
class NodeIfLstFin;
class NodeLit;

class Compiler {
	Node *syntax;
protected:
	inline void tree(Node *t) { syntax = t; }
public:
	static inline String
		extension(String filename, String ext) {
		int pos = filename.find_last_of('.');
		if (pos == String::npos) return filename + "." + ext;
		else return filename.substr(0, pos) + ext;
	}
	inline Node *tree() { return syntax; }

	virtual bool parse() = 0;
	virtual bool generate() = 0;

	// Visitor functions called by the tree nodes
	virtual void node(Node& n) = 0;
	virtual void nodeInteger(NodeInteger& n) = 0;
	virtual void nodeString(NodeString& n) = 0;
	virtual void nodeVariable(NodeVariable& n) = 0;
	virtual void nodeReal(NodeReal& n) = 0;
	virtual void nodeList(NodeList& n) = 0;
	virtual void nodePrint(NodePrint& n) = 0;
	virtual void nodeUnary(NodeUnary& n) = 0;
	virtual void nodeBinary(NodeBinary& n) = 0;
	virtual void nodeTernary(NodeTernary& n) = 0;
	virtual void nodeQuad(NodeQuad& n) = 0;
	virtual void nodePrintLine(NodePrintLine& n) = 0;
	virtual void nodeIf(NodeIf& n) = 0;
	virtual void nodeIfelse(NodeIfelse& n) = 0;
	virtual void nodeAssign(NodeAssign& n) = 0;
	virtual void nodeUminus(NodeUminus& n) = 0;
	virtual void nodeUplus(NodeUplus& n) = 0;
	virtual void nodeAdd(NodeAdd& n) = 0;
	virtual void nodeSub(NodeSub& n) = 0;
	virtual void nodeMul(NodeMul& n) = 0;
	virtual void nodeDiv(NodeDiv& n) = 0;
	virtual void nodeMod(NodeMod& n) = 0;
	virtual void nodeGt(NodeGt& n) = 0;
	virtual void nodeLt(NodeLt& n) = 0;
	virtual void nodeGe(NodeGe& n) = 0;
	virtual void nodeLe(NodeLe& n) = 0;
	virtual void nodeNe(NodeNe& n) = 0;
	virtual void nodeEq(NodeEq& n) = 0;
	virtual void nodeAnd(NodeAnd& n) = 0;
	virtual void nodeOr(NodeOr& n) = 0;
	virtual void nodeNot(NodeNot& n) = 0;
	virtual void nodePow(NodePow& n) = 0;
	virtual void nodeAddr(NodeAddr& n) = 0;
	virtual void nodeFor(NodeFor& n) = 0;
	virtual void nodeVar(NodeVar& n) = 0;
	virtual void nodeVarAt(NodeVarAt& n) = 0;
	virtual void nodeFunc(NodeFunc& n) = 0;
	virtual void nodeQui(NodeQui& n) = 0;
	virtual void nodeType(NodeType& n) = 0;
	virtual void nodeAlloc(NodeAlloc& n) = 0;
	virtual void nodeAccess(NodeAccess& n) = 0;
	virtual void nodeInd(NodeInd& n) = 0;
	virtual void nodeIndLst(NodeIndLst& n) = 0;
	virtual void nodeStop(NodeStop& n) = 0;
	virtual void nodeReturn(NodeReturn& n) = 0;
	virtual void nodeNext(NodeNext& n) = 0;
	virtual void nodeIfLst(NodeIfLst& n) = 0;
	virtual void nodeSect(NodeSect& n) = 0;
	virtual void nodeSectList(NodeSectList& n) = 0;
	virtual void nodeCallFunc(NodeCallFunc& n) = 0;
	virtual void nodeQual(NodeQual& n) = 0;
	virtual void nodeBlock(NodeBlock& n) = 0;
	virtual void nodeBody(NodeBody& n) = 0;
	virtual void nodeElif(NodeElif& n) = 0;
	virtual void nodeAtRec(NodeAtRec& n) = 0;
	virtual void nodeAtAssign(NodeAtAssign& n) = 0;
	virtual void nodeAtLoad(NodeAtLoad& n) = 0;
	virtual void nodeTrue(NodeTrue& n) = 0;
	virtual void nodeConst(NodeConst& n) = 0;
	virtual void nodeIfLstFin(NodeIfLstFin& n) = 0;
	virtual void nodeLit(NodeLit& n) = 0;
	
};
#endif /* _COMPILER_HH_ */
