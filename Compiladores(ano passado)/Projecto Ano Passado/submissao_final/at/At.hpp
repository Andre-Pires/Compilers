#ifndef _AT_HH_
#define _AT_HH_

#include <string>
#define String std::string
#include "Compiler.hpp"
#include "Parser.hpp"
#include "PFi386.hpp"
#include "Tabid.hpp"

class At : public Compiler {
	Parser *parser;
	Postfix *pf;
	Tabid vars;
public:
	/*
	static void main(String args[]) throws IOException {
		Compact lang;

		if (args.length > 1)
			lang = new Compact(args);
		else
			lang = new Compact(args[0]);

		lang.parser.yyparse();
		if (lang.parser.errors() == 0)
			lang.generate();
	}
	Compact(String args[]) throws IOException {
		String in = null, out = null;
		boolean lexdeb = false, syndeb = false, treeprt = false;
		boolean debug = false;
		int files;

		for (int i; i < args.length; i++)
			if (args[i].charAt(0) == '-') {
				if (args[i].equals("-lexical")) lexdeb = true;
				if (args[i].equals("-syntax")) syndeb = true;
				if (args[i].equals("-tree")) treeprt = true;
			        if (args[i].equals("-debug")) debug = true;
			}
			else {
				if (++files == 1) in = args[i];
				if (files == 2) out = args[i];
				if (files > 2)
					System.err.println(args[i] + ": too many arguments.");
			}

		if (in == null) {
			System.err.println("No input file.");
			System.exit(1);
		}
		parser = new Parser(new FileReader(in), syndeb);
		if (debug)
		  	pf = new PFdebug(out == null ? extension(in, ".stk") : out);
		else
		  	pf = new PFi386(out == null ? extension(in, ".asm") : out);
		vars = new Tabid();
	}
	*/
	At(String in, bool debug = false) {
		parser = new Parser(new std::ifstream(in.c_str()));
		pf = new PFi386(extension(in, ".asm"));
	}
	~At() {
	  	delete parser;
		delete pf;
	}
	bool parse();
	bool generate();
	void node(Node& n);
	void nodeInteger(NodeInteger& n);
	void nodeString(NodeString& n);
	void nodeVariable(NodeVariable& n);
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
	void nodeSectList(NodeSectList& n);
	void nodeCallFunc(NodeCallFunc& n);
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
#endif /* _AT_HH_ */
