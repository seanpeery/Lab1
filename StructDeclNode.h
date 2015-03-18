// StructDeclNode.h
// Author: Sean Peery

#pragma once

#include <map>
#include "DeclNode.h"
#include "DeclsNode.h"
#include "cSymbol.h"
using std::map;

class StructDeclNode : public DeclNode
{
    public:
        StructDeclNode(map<string,cSymbol*>* symTable = nullptr, DeclsNode* decls = nullptr, cSymbol* identifier = nullptr)
            :m_symTable(symTable), m_decls(decls), m_identifier(identifier)
		{
			m_identifier->InitializeSize(m_decls->GetSize());
		}
		
		string toString()
		{
			string tempStr = "STRUCT: ";
			
			tempStr += m_decls->toString() + " " + m_identifier->toString();
			tempStr += " size: " + std::to_string(m_size);
			return tempStr;
		}
		
        cSymbol* Find(string symbol)
		{
			cSymbol* retVal = nullptr;
		  
			if(m_symTable != nullptr)
			{
				map<string,cSymbol*>::iterator it = m_symTable->find(symbol);
				if(it != m_symTable->end())
					retVal = it->second;
			}
			
			return retVal;
		}

		int ComputeOffsets(int base)
		{    
			m_offset = 0;
			m_size = m_decls->ComputeOffsets(m_offset);
			
			m_offset = m_decls->CalculateOffset(base);
        
			return base;
		}
		int FindSymbolOffset(cSymbol* symbol)
		{
			return m_decls->FindSymbolOffset(symbol);
		}
		int GetSize()
		{
			return m_identifier->GetSize();
		}
		
		void GenerateCode()
		{
			if(m_decls != nullptr)
				m_decls->GenerateCode();
		}
    private:
        map<string,cSymbol*>* m_symTable;
        DeclsNode* m_decls;
        cSymbol* m_identifier;
        
};