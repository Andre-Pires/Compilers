#include "At.hpp"
#include "Node.hpp"
#include "NodeInteger.hpp"
#include "NodeString.hpp"
#include "NodeVariable.hpp"
#include "NodeReal.hpp"
#include "NodeUnary.hpp"
#include "NodeBinary.hpp"
#include "NodeTernary.hpp"
#include "NodeQuad.hpp"
#include "NodeQui.hpp"
#include "NodeList.hpp"

#include "NodePrint.hpp"
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
#include "NodeConst.hpp"
#include "NodeInd.hpp"
#include "NodeIndLst.hpp"
#include "NodeIfLstFin.hpp"
#include "NodeLit.hpp"

#include "SymbolNode.hpp"

bool At::parse() {
	if (parser->parse() == 0)
		tree(parser->syntax());
	return parser->errors() == 0;
}

bool At::generate() {
	if (parser->errors() > 0) return false;
	pf->TEXT();
	pf->ALIGN();
	pf->GLOBLfunc("_main");
	pf->LABEL("_main");
	pf->START();
	tree()->accept(*this);
	pf->INT(0);
	pf->POP();
	pf->LEAVE();
	pf->RET();
	// import library functions
	pf->EXTRN("readi");
	pf->EXTRN("printi");
	pf->EXTRN("prints");
	pf->EXTRN("println");
	pf->flush();
	return true;
}
void At::node(Node& n) {}
void At::nodeInteger(NodeInteger& n) { 
	pf->INT(n.integer()); 
}

void At::nodeString(NodeString& n) {
	String lbl = pf->label();
	pf->RODATA();			// strings are DATA readonly
	pf->ALIGN();			// make sure we are aligned
	pf->LABEL(lbl);			// give the string a name
	pf->STR(n.text());		// output string characters
	// make the call
	pf->TEXT();			// return to the TEXT segment
	pf->ADDR(lbl);			// the string to be printed
	pf->CALL("prints");		// call the print rotine
	pf->CALL("println");		// print a newline
	pf->TRASH(4);			// remove the string argument
}

void At::nodeVariable(NodeVariable& n) {
	if (vars.containsKey(n.text())) {
		pf->ADDR(n.text());
		pf->LOAD();
	}
}

void At::nodeReal(NodeReal& n) {} // No reals
void At::nodeList(NodeList& n) {
	for (int i = 0; i < n.size(); i++)
		n.elementAt(i).accept(*this);
}
void At::nodePrint(NodePrint& n) {
	n.first().accept(*this);
	pf->CALL("printi");		// call the print function
	pf->TRASH(4);			// delete the printed value
}

void At::nodePrintLine(NodePrintLine& n) {
	n.first().accept(*this);
	pf->CALL("printi");		// call the print function
	pf->CALL("println");		// print a newline
	pf->TRASH(4);			// delete the printed value
}

void At::nodeUnary(NodeUnary& n) {}
void At::nodeBinary(NodeBinary& n) { }
void At::nodeTernary(NodeTernary& n) {}
void At::nodeQuad(NodeQuad& n) {}
void At::nodeQui(NodeQui& n) {}
void At::nodeIf(NodeIf& n) {
	String lbl1 = pf->label();
	n.first().accept(*this);
	pf->JZ(lbl1);
	n.second().accept(*this);
	pf->LABEL(lbl1);
}

void At::nodeIfelse(NodeIfelse& n) {
	String lbl1 = pf->label(), lbl2 = pf->label();
	n.first().accept(*this);
	pf->JZ(lbl1);
	n.second().accept(*this);
	pf->JMP(lbl2);
	pf->LABEL(lbl1);
	n.third().accept(*this);
	pf->LABEL(lbl2);
}

void At::nodeAssign(NodeAssign& n) {
	String name = ((NodeString*)&n.first())->text();
	if (!vars.containsKey(name)) {	// variable not found ?
		pf->DATA();		// variables are DATA
		pf->ALIGN();		// make sure we are aligned
		pf->LABEL(name);		// name variable location
		pf->CONST(0);		// initialize it to 0 (zero)
		pf->TEXT();		// return to the TEXT segment
		vars.put(name, new SymbolNode());	// create the var
	}
	n.second().accept(*this);	// determine the new value
	pf->ADDR(name);			// where to store the value
	pf->STORE();			// store the value at address
}

void At::nodeUminus(NodeUminus& n) {
	n.first().accept(*this);		// determine the new value
	pf->NEG();				// make the 2-compliment
}

void At::nodeUplus(NodeUplus& n) {
	n.first().accept(*this);		// determine the new value
}

void At::nodeAdd(NodeAdd& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->ADD();
}

void At::nodeSub(NodeSub& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->SUB();
}

void At::nodeMul(NodeMul& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->MUL();
}

void At::nodeDiv(NodeDiv& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->DIV();
}

void At::nodeMod(NodeMod& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->MOD();
}

void At::nodeLt(NodeLt& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->LT();
}

void At::nodeGt(NodeGt& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->GT();
}

void At::nodeGe(NodeGe& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->GE();
}

void At::nodeLe(NodeLe& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->LE();
}

void At::nodeNe(NodeNe& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->NE();
}

void At::nodeEq(NodeEq& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->EQ();
}

void At::nodeAnd(NodeAnd& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->AND();
}

void At::nodeOr(NodeOr& n) {
	n.first().accept(*this);
	n.second().accept(*this);
	pf->OR();
}

void At::nodeNot(NodeNot& n) {
	n.first().accept(*this);
	pf->NOT();
}

void At::nodePow(NodePow& n) {		
	String lbl1 = pf->label();
	String lbl2 = pf->label();
	n.first().accept(*this);				
	n.second().accept(*this);
	pf->ADDR(".powDECR");		// Guardo o expoente numa zona específica
	pf->STORE();
	pf->ADDR(".powCPY");		// Guardo uma cópia da base, nunca modificada
	pf->STORE();
	pf->INT(1);			// Variável inicial. A partir do 1, é multiplicao pela sua base quantas vezes for o número do expoente
	pf->LABEL(lbl1);		// Início do "while"
	pf->ADDR(".powCPY");		// Tira a cópia da base, para multiplicar
	pf->LOAD();
	pf->MUL();			// Multiplica a variável da copy pelo valor já existente (e modificado na pilha)
	pf->ADDR(".powDECR");
	pf->LOAD();
	pf->INT(1);			// Subtrai 1 ao expoente, sendo depois guardado no .powDECR 
	pf->SUB();
	pf->JZ(lbl2);			// Caso na subtracção, o expoente fique a 0, sairá do "while" e o valor do expoente é retirado 
	pf->ADDR(".powDECR");		// Caso contrário, o .powDECR pegará no valor do expoente e guardá-lo-á para o próximo ciclo
	pf->STORE();
	pf->JMP(lbl1);
	pf->LABEL(lbl2);		// Final do ciclo
}

void At::nodeAddr(NodeAddr& n) {
	String name = ((NodeString*)&n.first())->text();
	if (vars.containsKey(name)) {
		pf->ADDR(name);			// Devolve o endereço
	}
	else					// Caso contrário, devolve erro de variável não encontrada
		std::cerr << name + ": variable not found";
}

void At::nodeFor(NodeFor& n) {
	String lbl1 = pf->label(), lbl2 = pf->label();
	n.first().accept(*this);
	pf->LABEL(lbl1);
	n.second().accept(*this);
	pf->JZ(lbl2);
	n.fourth().accept(*this);
	n.third().accept(*this);
	pf->JMP(lbl1);
	pf->LABEL(lbl2);
}

void At::nodeVar(NodeVar& n) {							// ...
							
}

void At::nodeVarAt(NodeVarAt& n) {						// ...
	
}

void At::nodeFunc(NodeFunc& n) {						// ...
	n.fifth().accept(*this);
	
/*	String name = ((NodeString*)&n.first())->text();
	pf->TEXT();
	pf->ALIGN();
	pf->GLOBL(name);
	pf->LABEL(name);
	
	n.fourth().accept(*this);
*/	
}

void At::nodeType(NodeType& n) {}						// Deve-se mudar

void At::nodeAlloc(NodeAlloc& n) {}						// Mais Tarde

void At::nodeAccess(NodeAccess& n) {}						// Mais Tarde

void At::nodeIndLst(NodeIndLst& n) {}						// Mais Tarde
			
void At::nodeInd(NodeInd& n) {}							// Mais Tarde

void At::nodeStop(NodeStop& n) {						// Falta isto
		
}

void At::nodeReturn(NodeReturn& n) {
	pf->RET();
}

void At::nodeNext(NodeNext& n) {						// Falta isto
	
}

void At::nodeIfLst(NodeIfLst& n) {
	String lbl1 = pf->label();
	n.first().accept(*this);
	pf->DUP();
	pf->JZ(lbl1);
	n.second().accept(*this);
	pf->LABEL(lbl1);
	n.third().accept(*this);
	pf->OR();
}

void At::nodeSect(NodeSect& n) {
	String lbl1 = pf->label();
	n.first().accept(*this);
	pf->JZ(lbl1);
	n.second().accept(*this);
	pf->LABEL(lbl1);
}

void At::nodeSectList(NodeSectList& n) {
	String lbl1 = pf->label();
	n.first().accept(*this);
	pf->JZ(lbl1);
	n.second().accept(*this);
	pf->LABEL(lbl1);
	n.third().accept(*this);
}

void At::nodeQual(NodeQual& n) {}		// Deve-se mudar

void At::nodeBlock(NodeBlock& n) {
	n.first().accept(*this);
	n.second().accept(*this);
}

void At::nodeBody(NodeBody& n) {
	n.first().accept(*this);
	n.second().accept(*this);		// Falta guardar variáveis e passar para o quarto (CASO seja o quarto e aí sai do Body, função e tudo isso)
	n.third().accept(*this);
	n.fourth().accept(*this);
}

void At::nodeElif(NodeElif& n) {
	String lbl1 = pf->label();
	String lbl2 = pf->label();
	n.first().accept(*this);
	pf->DUP();			//guardar variável
	pf->JZ(lbl1);
	n.second().accept(*this);
	pf->LABEL(lbl1);
	n.third().accept(*this);
	pf->OR();			//juntar valor do primeiro if com o resto dos ifs.
	pf->INT(0);			
	pf->EQ();			//comparar o caso verdadeiro com o resultado anterior.
	pf->JZ(lbl2);			//Caso o OR tenha dado 1 (verdadeiro) então ele, ao comparar, passa à frente do else.
	n.fourth().accept(*this);
	pf->LABEL(lbl2);
	
}

void At::nodeAtRec(NodeAtRec& n) {
	// Como pôr um raio de uma string guardada na criação de uma função? <.<
}

void At::nodeAtAssign(NodeAtAssign& n) {
	n.first().accept(*this);
	pf->ADDR(".at");
	pf->STORE();
	pf->RET();
}

void At::nodeAtLoad(NodeAtLoad& n) {
	pf->CALL("readi");
	pf->PUSH();
	pf->ADDR(".at");
	pf->STORE();
}

void At::nodeCallFunc(NodeCallFunc& n) {
	String name = ((NodeString*)&n.first())->text();
	pf->CALL(name);
	n.second().accept(*this);
}

void At::nodeTrue(NodeTrue& n) {
	pf->INT(1);
}

void At::nodeConst(NodeConst& n) {
	pf->INT(1);
}

void At::nodeIfLstFin(NodeIfLstFin& n) {
	String lbl1 = pf->label();
	n.first().accept(*this);
	pf->DUP();
	pf->JZ(lbl1);
	n.second().accept(*this);
	pf->LABEL(lbl1);
	n.third().accept(*this);
	pf->TRASH(8);			// Eliminar os resultados, visto estarmos no primeiro if a testar e ultimo a verificar.
}

void At::nodeLit(NodeLit& n) {
	n.first().accept(*this);
	pf->ADDR(".at");
	pf->STORE();
}
