// StmtsNode.h
// Author: Sean Peery

#pragma once

#include <list>
#include "cAstNode.h"
#include "StmtNode.h"
using std::list;

class StmtsNode : public cAstNode
{
    public:
        StmtsNode()
		{}
        string toString()
		{
			string retVal = "STMTS:\n{\n";
			for(auto &stmt : m_stmts)
				retVal += stmt->toString()+ "\n";
			retVal += "}";
			return retVal;
		}

        void Add(StmtNode* data = nullptr)
		{
			m_stmts.push_back(data);
		}
        
    private:
        list<StmtNode*> m_stmts;        
};