// FuncDeclNode.h
// Author: Sean Peery

#pragma once

#include "cSymbol.h"
#include "ParamsSpecNode.h"
#include "DeclNode.h"
#include "DeclsNode.h"
#include "StmtsNode.h"

class FuncDeclNode : public DeclNode
{
    public:
        FuncDeclNode(cSymbol* header = nullptr, ParamsSpecNode* params = nullptr)
		    :m_header(header), m_params(params), m_decls(nullptr), m_stmts(nullptr)
		{}
		
        string toString()
		{
			string retVal = "(FUNC: " + m_header->toString();
			
			if(m_params != nullptr)
				retVal += " " + m_params->toString();
			else
				retVal += "()";
				
			if(m_decls != nullptr)
				retVal += "\n" + m_decls->toString();
			
			if(m_stmts != nullptr)
				retVal += "\n" + m_stmts->toString();
			
			retVal += "\n)";
			
			return retVal;
		}
		
        void SetStmts(StmtsNode* stmts = nullptr)
		{
			m_stmts = stmts;
		}

        void SetDecls(DeclsNode* decls = nullptr)
		{
			m_decls = decls;
		}
			
    private:
        cSymbol* m_header;
        ParamsSpecNode* m_params;
        DeclsNode*  m_decls;
        StmtsNode*  m_stmts;
};