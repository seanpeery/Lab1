// DeclsNode.h
// Author: Sean Peery

#pragma once

#include <list>
#include "cAstNode.h"
#include "DeclNode.h"
using std::list;

class DeclsNode : public cAstNode
{
    public:
        DeclsNode()
		{}
        string toString()
		{
			string retVal = "DECLS:\n{\n";
			
			for(auto &decl : m_decls)
				retVal += decl->toString()+ "\n";
			
			retVal += "}\n";
			
			return retVal;
		}
        void Add(DeclNode* data = nullptr)
		{
			m_decls.push_back(data);
		}
				
    private:
        list<DeclNode*> m_decls;
};