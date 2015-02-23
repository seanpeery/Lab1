#pragma once
#include <map>

#include "DeclsNode.h"
#include "StmtsNode.h"
#include "cSymbol.h"
#include "StmtNode.h"

using std::map;

class BlockNode : public StmtNode
{
    public:
        BlockNode(map<string,cSymbol*>* symTable = nullptr, DeclsNode* decls = nullptr, StmtsNode* stmts = nullptr)
		    :m_symTable(symTable), m_decls(decls), m_stmts(stmts)
		{}

        string toString()
		{
			string retVal = "BLOCK:\n{\n";
			if(m_decls != nullptr)
				retVal += m_decls->toString();
			if(m_stmts != nullptr)
				retVal += m_stmts->toString();
			
			retVal += "\n}";
			return retVal;
		}
    
    private:
        map<string,cSymbol*>* m_symTable;
        DeclsNode * m_decls;
        StmtsNode * m_stmts;
};