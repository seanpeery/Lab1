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
			string tempStr = "STMTS:\n{\n";
			for(StmtNode * stmt : m_stmts)
				tempStr += stmt->toString()+ "\n";
			tempStr += "}\n";
			return tempStr;
		}

        void Add(StmtNode* data = nullptr)
		{
			m_stmts.push_back(data);
		}
		int ComputeOffsets(int base)
		{
		    m_offset = base;
			for(StmtNode * stmt : m_stmts)
				m_offset = stmt->ComputeOffsets(m_offset);

			return base;
		}
        void GenerateCode()
		{
			for(StmtNode *stmt : m_stmts)
				stmt->GenerateCode();
		}
    private:
        list<StmtNode*> m_stmts;        
};