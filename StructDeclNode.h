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
		{}
		
		string toString()
		{
			string retVal = "STRUCT: ";
			
			retVal += m_decls->toString() + " " + m_identifier->toString();
			
			return retVal;
		}
		
        void PrintSymbolTable()
		{
			std::cout << "My table for " << m_identifier->GetSymbol() << " holds" << std::endl;
			for(auto &sym : *m_symTable)
				std::cout << sym.second->GetSymbol() << std::endl;
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
    
    private:
        map<string,cSymbol*>* m_symTable;
        DeclsNode* m_decls;
        cSymbol* m_identifier;
        
};