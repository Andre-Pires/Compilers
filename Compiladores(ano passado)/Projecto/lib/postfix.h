/* $Id: postfix.h,v 1.4 2004/12/09 17:24:33 prs Exp $ */
#ifndef _postfix_h_
#define _postfix_h_

#ifndef pfDEBUG

#define pfNOP "; NOP\n\tnop\n"
#define pfIMM "; IMM\n\tpush\tdword %d\n"
#define pfADD "; ADD\n\tpop\teax\n\tadd\tdword [esp], eax\n"
#define pfSUB "; SUB\n\tpop\teax\n\tsub\tdword [esp], eax\n"
#define pfMUL "; MUL\n\tpop\teax\n\timul\tdword eax, [esp]\n\tmov\t[esp], eax\n"
#define pfDIV "; DIV\n\tpop\tecx\n\tpop\teax\n\tcdq\n\tidiv\tecx\n\tpush\teax\n"
#define pfMOD "; MOD\n\tpop\tecx\n\tpop\teax\n\tcdq\n\tidiv\tecx\n\tpush\tedx\n"
#define pfNEG "; NEG\n\tneg\tdword [esp]\n"
#define pfINCR "; INCR\n\tpop\teax\n\tadd\tdword [eax], %d\n"
#define pfDECR "; DECR\n\tpop\teax\n\tsub\tdword [eax], %d\n"
#define pfGT "; GT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetg\tcl\n\tmov\t[esp], ecx\n"
#define pfGE "; GE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetge\tcl\n\tmov\t[esp], ecx\n"
#define pfLT "; LT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetl\tcl\n\tmov\t[esp], ecx\n"
#define pfLE "; LE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetle\tcl\n\tmov\t[esp], ecx\n"
#define pfEQ "; EQ\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsete\tcl\n\tmov\t[esp], ecx\n"
#define pfNE "; NE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetne\tcl\n\tmov\t[esp], ecx\n"
#define pfAND "; AND\n\tpop\teax\n\tand\tdword [esp], eax\n"
#define pfOR "; OR\n\tpop\teax\n\tor\tdword [esp], eax\n"
#define pfXOR "; XOR\n\tpop\teax\n\txor\tdword [esp], eax\n"
#define pfNOT "; NOT\n\tnot\tdword [esp]\n"
#define pfROTL "; ROTL\n\tpop\tecx\n\trol\tdword [esp], cl\n"
#define pfROTR "; ROTR\n\tpop\tecx\n\tror\tdword [esp], cl\n"
#define pfSHTL "; SHTL\n\tpop\tecx\n\tsal\tdword [esp], cl\n"
#define pfSHTRU "; SHTRU\n\tpop\tecx\n\tshr\tdword [esp], cl\n"
#define pfSHTRS "; SHTRS\n\tpop\tecx\n\tsar\tdword [esp], cl\n"
#define pfLOCAL "; LOCAL\n\tlea\teax, [ebp+%d]\n\tpush\teax\n"
#define pfADDR "; ADDR\n\tpush\tdword $%s\n"
#define pfLOCV "; LOCV\n\tpush\tdword [ebp+%d]\n"
#define pfADDRV "; ADDRV\n\tpush\tdword [$%s]\n"
#define pfLOCA "; LOCA\n\tpop\teax\n\tmov\t[ebp+%d], eax\n"
#define pfADDRA "; ADDRA\n\tpop\teax\n\tmov\t[$%s], eax\n"
#define pfLOAD "; LOAD\n\tpop\teax\n\tpush\tdword [eax]\n"
#define pfSTORE "; STORE\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], eax\n"
#define pfLDCHR "; LDCHR\n\tpop\tecx\n\tmovsx\teax,byte [ecx]\n\tpush\teax\n"
#define pfSTCHR "; STCHR\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], al\n"
#define pfLD16 "; LD16\n\tpop\tecx\n\tmovsx\teax,word [ecx]\n\tpush\teax\n"
#define pfST16 "; ST16\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], ax\n"
#define pfENTER "; ENTER\n\tpush\tebp\n\tmov\tebp, esp\n\tsub\tesp, %d\n"
#define pfSTART "; START\n\tpush\tebp\n\tmov\tebp, esp\n"
#define pfALLOC "; ALLOC\n\tpop\teax\n\tsub\tesp, eax\n"
#define pfLEAVE "; LEAVE\n\tleave\n"
#define pfTRASH "; TRASH\n\tadd\tesp, %d\n"
#define pfCALL "; CALL\n\tcall\t$%s\n"
#define pfRET "; RET\n\tret\n"
#define pfRETN "; RETN\n\tret\t%d\n"
#define pfBRANCH "; BRANCH\n\tpop\teax\n\tcall\teax\n"
#define pfLEAP "; LEAP\n\tpop\teax\n\tjmp\teax\n"
#define pfJMP "; JMP\n\tjmp\tdword $%s\n"
#define pfJZ "; JZ\n\tpop\teax\n\tcmp\teax, byte 0\n\tje\tnear $%s\n"
#define pfJNZ "; JNZ\n\tpop\teax\n\tcmp\teax, byte 0\n\tjne\tnear $%s\n"
#define pfCOPY "; COPY\n\tpush\tdword [esp]\n"
#define pfSWAP "; SWAP\n\tpop\teax\n\tpop\tecx\n\tpush\teax\n\tmov\teax, ecx\n\tpush\teax\n"
#define pfSP "; SP\n\tpush\tesp\n"
#define pfPUSH "; PUSH\n\tpush\teax\n"
#define pfPOP "; POP\n\tpop\teax\n"
#define pfI2D "; I2D\n\tfild\tdword [esp]\n\tsub\tesp, byte 4\n\tfstp\tqword [esp]\n"
#define pfF2D "; F2D\n\tfld\tdword [esp]\n\tsub\tesp, byte 4\n\tfstp\tqword [esp]\n"
#define pfD2I "; D2I\n\tfld\tqword [esp]\n\tadd\tesp, byte 4\n\tfistp\tdword [esp]\n"
#define pfD2F "; D2F\n\tfld\tqword [esp]\n\tadd\tesp, byte 4\n\tfstp\tdword [esp]\n"
#define pfDADD "; DADD\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfaddp\tst1\n\tfstp\tqword [esp]\n"
#define pfDSUB "; DSUB\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfsubrp\tst1\n\tfstp\tqword [esp]\n"
#define pfDMUL "; DMUL\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfmulp\tst1\n\tfstp\tqword [esp]\n"
#define pfDDIV "; DDIV\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n\tfld\tqword [esp]\n\tfdivrp\tst1\n\tfstp\tqword [esp]\n"
#define pfDCMP "; DCMP\n\tfld\tqword [esp+8]\n\tfld\tqword [esp]\n\tadd\tesp, byte 12\n\tfsubp\tst1\n\tfxtract\n\tffree\tst1\n\tfistp\tdword [esp]\n"
#define pfDNEG "; DNEG\n\tfld\tqword [esp]\n\tfchs\n\tfstp\tqword [esp]\n"
#define pfLOAD2 "; LOAD2\n\tpop\teax\n\tpush\tdword [eax+4]\n\tpush\tdword [eax]\n"
#define pfSTORE2 "; STORE2\n\tpop\tecx\n\tpop\teax\n\tmov\t[ecx], eax\n\tpop\teax\n\tmov\t[ecx+4], eax\n"
#define pfCOPY2 "; COPY2\n\tpush\tdword [esp+4]\n\tpush\tdword [esp+4]\n"
#define pfDPUSH "; DPUSH\n\tsub\tesp, byte 8\n\tfstp\tqword [esp]\n"
#define pfDPOP "; DPOP\n\tfld\tqword [esp]\n\tadd\tesp, byte 8\n"
#define pfNIL "; NIL\n"
#define pfBEGIN "; BEGIN %s\n"
#define pfEND "; END\n"
#define pfTEXT "; TEXT\nsegment\t.text\n"
#define pfRODATA "; RODATA\nsegment\t.rodata\n"
#define pfDATA "; DATA\nsegment\t.data\n"
#define pfBSS "; BSS\nsegment\t.bss\n"
#define pfALIGN "; ALIGN\nalign\t4\n"
#define pfEXTRN "; EXTRN\nextern\t$%s\n"
#define pfCOMMON "; COMMON\Ncommon\t%d\n"
#define pfGLOBL "; GLOBL\nglobal\t$%s%s\n"
#define pfLABEL "; LABEL\n$%s:\n"
#define pfINTEGER "; INTEGER\n\tdd\t%d\n"
#define pfSHORT "; SHORT\n\tdw\t%d\n"
#define pfLONG "; LONG\n\tdq\t%d\n"
#define pfSTR "; STR\n\tdb\t'%s', 0\n"
#define pfCHAR "; CHAR\n\tdb\t0x%2.2X\n"
#define pfID "; ID\n\tdd\t$%s\n"
#define pfBYTE "; BYTE\n\tresb\t%d\n"
#define pfFLOAT "; FLOAT\n\tdd\t%e\n"
#define pfDOUBLE "; DOUBLE\n\tdq\t%e\n"
#define pfULDCHR "; ULDCHR\n\tmovzx\teax,byte [ecx]\n"
#define pfULD16 "; ULD16\n\tmovzx\teax,word [ecx]\n"
#define pfUDIV "; UDIV\n\tpop\tecx\n\tpop\teax\n\txor\tedx, edx\n\tidiv\tecx\n\tpush\teax\n"
#define pfUMOD "; UMOD\n\tpop\tecx\n\tpop\teax\n\txor\tedx, edx\n\tidiv\tecx\n\tpush\tedx\n"
#define pfUGT "; UGT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tseta\tcl\n\tmov\t[esp], ecx\n"
#define pfUGE "; UGE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetae\tcl\n\tmov\t[esp], ecx\n"
#define pfULT "; ULT\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetb\tcl\n\tmov\t[esp], ecx\n"
#define pfULE "; ULE\n\tpop\teax\n\txor\tecx, ecx\n\tcmp\t[esp], eax\n\tsetbe\tcl\n\tmov\t[esp], ecx\n"
#define pfJEQ "; JEQ\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tje\tnear $%s\n"
#define pfJNE "; JNE\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjne\tnear $%s\n"
#define pfJGT "; JGT\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjg\tnear $%s\n"
#define pfJGE "; JGE\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjge\tnear $%s\n"
#define pfJLT "; JLT\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjl\tnear $%s\n"
#define pfJLE "; JLE\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjle\tnear $%s\n"
#define pfJUGT "; JUGT\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tja\tnear $%s\n"
#define pfJUGE "; JUGE\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjae\tnear $%s\n"
#define pfJULT "; JULT\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjbe\tnear $%s\n"
#define pfJULE "; JULE\n\tpop\teax\n\tpop\tecx\n\tcmp\teax, ecx\n\tjb\tnear $%s\n"

#else

#define pfNOP "NOP\n"
#define pfIMM "IMM %d\n"
#define pfADD "ADD\n"
#define pfSUB "SUB\n"
#define pfMUL "MUL\n"
#define pfDIV "DIV\n"
#define pfMOD "MOD\n"
#define pfNEG "NEG\n"
#define pfINCR "INCR %d\n"
#define pfDECR "DECR %d\n"
#define pfGT "GT\n"
#define pfGE "GE\n"
#define pfLT "LT\n"
#define pfLE "LE\n"
#define pfEQ "EQ\n"
#define pfNE "NE\n"
#define pfAND "AND\n"
#define pfOR "OR\n"
#define pfXOR "XOR\n"
#define pfNOT "NOT\n"
#define pfROTL "ROTL\n"
#define pfROTR "ROTR\n"
#define pfSHTL "SHTL\n"
#define pfSHTRU "SHTRU\n"
#define pfSHTRS "SHTRS\n"
#define pfLOCAL "LOCAL %d\n"
#define pfADDR "ADDR %s\n"
#define pfLOCV "LOCV %d\n"
#define pfADDRV "ADDRV %s\n"
#define pfLOCA "LOCA %d\n"
#define pfADDRA "ADDRA %s\n"
#define pfLOAD "LOAD\n"
#define pfSTORE "STORE\n"
#define pfLDCHR "LDCHR\n"
#define pfSTCHR "STCHR\n"
#define pfLD16 "LD16\n"
#define pfST16 "ST16\n"
#define pfENTER "ENTER %d\n"
#define pfSTART "START\n"
#define pfALLOC "ALLOC\n"
#define pfLEAVE "LEAVE\n"
#define pfTRASH "TRASH %d\n"
#define pfCALL "CALL %s\n"
#define pfRET "RET\n"
#define pfRETN "RETN %d\n"
#define pfBRANCH "BRANCH\n"
#define pfLEAP "LEAP\n"
#define pfJMP "JMP %s\n"
#define pfJZ "JZ %s\n"
#define pfJNZ "JNZ %s\n"
#define pfCOPY "COPY\n"
#define pfSWAP "SWAP\n"
#define pfSP "SP\n"
#define pfPUSH "PUSH\n"
#define pfPOP "POP\n"
#define pfI2D "I2D\n"
#define pfF2D "F2D\n"
#define pfD2I "D2I\n"
#define pfD2F "D2F\n"
#define pfDADD "DADD\n"
#define pfDSUB "DSUB\n"
#define pfDMUL "DMUL\n"
#define pfDDIV "DDIV\n"
#define pfDCMP "DCMP\n"
#define pfDNEG "DNEG\n"
#define pfLOAD2 "LOAD2\n"
#define pfSTORE2 "STORE2\n"
#define pfCOPY2 "COPY2\n"
#define pfDPUSH "DPUSH\n"
#define pfDPOP "DPOP\n"
#define pfNIL "NIL\n"
#define pfBEGIN "BEGIN %s\n"
#define pfEND "END\n"
#define pfTEXT "TEXT\n"
#define pfRODATA "RODATA\n"
#define pfDATA "DATA\n"
#define pfBSS "BSS\n"
#define pfALIGN "ALIGN\n"
#define pfEXTRN "EXTRN %s\n"
#define pfCOMMON "COMMON %d\n"
#define pfGLOBL "GLOBL %s %s\n"
#define pfLABEL "LABEL %s\n"
#define pfINTEGER "INTEGER %d\n"
#define pfSHORT "SHORT %d\n"
#define pfLONG "LONG %d\n"
#define pfSTR "STR \"%s\"\n"
#define pfCHAR "CHAR 0x%2.2X\n"
#define pfID "ID %s\n"
#define pfBYTE "BYTE %d\n"
#define pfFLOAT "FLOAT %e\n"
#define pfDOUBLE "DOUBLE %e\n"
#define pfULDCHR "ULDCHR\n"
#define pfULD16 "ULD16\n"
#define pfUDIV "UDIV\n"
#define pfUMOD "UMOD\n"
#define pfUGT "UGT\n"
#define pfUGE "UGE\n"
#define pfULT "ULT\n"
#define pfULE "ULE\n"
#define pfJEQ "JEQ %s\n"
#define pfJNE "JNE %s\n"
#define pfJGT "JGT %s\n"
#define pfJGE "JGE %s\n"
#define pfJLT "JLT %s\n"
#define pfJLE "JLE %s\n"
#define pfJUGT "JUGT %s\n"
#define pfJUGE "JUGE %s\n"
#define pfJULT "JULT %s\n"
#define pfJULE "JULE %s\n"

#endif

/* Used as the 2nd argument of pfGLOBL */
#define pfNONE	""		/* unknown global label type */
#ifdef _WIN32
#define pfFUNC	""		/* no symbol types in win32-PE */
#define pfOBJ	""		/* no symbol types in win32-PE */
#else
#define pfFUNC	":function"	/* global label is a function */
#define pfOBJ	":object"	/* global label is data */
#endif /* _WIN32 */

/* old mnemonics */
#define pfCONST pfINTEGER
#define pfINT pfIMM
#define pfDUP pfCOPY
#define pfDUP2 pfCOPY2

#endif /* _postfix_h_ */