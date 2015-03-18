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
		    :m_header(header), m_paramsSpec(params), m_decls(nullptr), m_stmts(nullptr)
		{ }
		
        string toString()
		{
			string tempStr = "(FUNC: " + m_header->toString();
			
			if(m_paramsSpec != nullptr)
				tempStr += m_paramsSpec->toString();
			else
				tempStr += "()";
				
			if(m_decls != nullptr)
				tempStr += "\n" + m_decls->toString();
			
			if(m_stmts != nullptr)
				tempStr += "\n" + m_stmts->toString();
			
			tempStr += "\nsize: " + std::to_string(m_size);
			
			tempStr += "\n)";
			
			return tempStr;
		}
		
        void SetStmts(StmtsNode* stmts = nullptr)
		{
			m_stmts = stmts;
		}

        void SetDecls(DeclsNode* decls = nullptr)
		{
			m_decls = decls;
		}

		int ComputeOffsets(int base)
		{
			m_offset = 0;
			//int tempHolder = 0;
			if(m_paramsSpec != nullptr)
			{
			   m_paramSize = m_paramsSpec->ComputeOffsets(m_offset);
			   //m_offset = tempHolder;
			}
			if(m_decls != nullptr)
				m_offset = m_decls->ComputeOffsets(m_paramSize);

			if(m_stmts != nullptr)
				m_offset = m_stmts->ComputeOffsets(m_offset);

			m_size = m_offset - m_paramSize;
			return base;
		}
		int GetSize()
		{
			return m_header->GetSize();
		}
		
		void GenerateCode()
		{
			generate->StartFunctionOutput();
			generate->EmitString("int " + m_header->GetSymbol() + "()\n{\n");
			if(m_decls != nullptr)
				m_decls->GenerateCode();
			if(m_stmts != nullptr)
				m_stmts->GenerateCode();
			generate->StackSizeDown(m_size + m_paramSize);
			generate->EmitString("}\n");
			generate->EndFunctionOutput();
		}
		int GetParamsSize()
		{
			return m_paramSize;
		}

			
    private:
        cSymbol* m_header;
        ParamsSpecNode* m_paramsSpec;
        DeclsNode*  m_decls;
        StmtsNode*  m_stmts;
		int m_paramSize;
};