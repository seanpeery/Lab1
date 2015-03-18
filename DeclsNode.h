// DeclsNode.h
// Author: Sean Peery

#pragma once

#include <list>
#include "VarNode.h"
#include "cAstNode.h"
#include "DeclNode.h"
#include "cSymbol.h"

using std::list;

class DeclsNode : public cAstNode
{
    public:
        DeclsNode()
		{}
		
        string toString()
		{
			string tempStr = "DECLS:\n{\n";
			
			for(DeclNode * decl : m_decls)
				tempStr += decl->toString()+ "\n";
			
			tempStr += "}\n";
			
			return tempStr;
		}
		
        void Add(DeclNode* data = nullptr)
		{
			m_decls.push_back(data);
		}
		
		int ComputeOffsets(int base)
		{
			m_offset = base;
			for(DeclNode * decl : m_decls)
				m_offset = decl->ComputeOffsets(CeilMod4(m_offset));
			
			base = m_offset;
			return base;
		}
		int CalculateOffset(int offset)
		{
			for(DeclNode * decl : m_decls)
				offset += decl->GetCalculatedOffset();
			
			return offset;
		}
		
		int FindSymbolOffset(cSymbol* symbol)
		{
			int tempInt = 0;
			for(DeclNode * decl : m_decls)
			{
				VarNode* var = dynamic_cast<VarNode*>(decl);
				if(var != nullptr)
				{
					if(var->GetSymbol() == symbol)
						return var->GetCalculatedOffset();
				}
			}
			
			return tempInt;
		}
		
		int GetSize()
		{
			int tempInt = 0;
			for(DeclNode * decl : m_decls)
			{
				tempInt = CeilMod4(tempInt);
				tempInt += decl->GetSize();
			}
			
			return tempInt;
		}
		
		void GenerateCode()
		{
			for(DeclNode * decl : m_decls)
				decl->GenerateCode();
		}
		
    private:
        list<DeclNode*> m_decls;
};