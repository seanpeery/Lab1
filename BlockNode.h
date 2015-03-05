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
		{ }

        string toString()
		{
			string tempStr = "BLOCK:";
			tempStr += " size: " + std::to_string(m_size) + "\n{\n";
			if(m_decls != nullptr)
				tempStr += m_decls->toString();
			if(m_stmts != nullptr)
				tempStr += m_stmts->toString();
			
			tempStr += "\n}\n";
			return tempStr;
		}
		
		int ComputeOffsets(int base)
		{
		    m_offset = base;
			
			if(m_decls != nullptr)
			{
				m_offset = m_decls->ComputeOffsets(m_offset);
			}
			if(m_stmts != nullptr)
			{
				m_offset = m_stmts->ComputeOffsets(m_offset);
			}
			m_size = m_offset - base;
			
			return base;
		}

    
    private:
        map<string,cSymbol*>* m_symTable;
        DeclsNode * m_decls;
        StmtsNode * m_stmts;

};