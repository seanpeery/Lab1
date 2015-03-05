// IfNode.h
// Author: Sean Peery

#pragma once

#include "StmtNode.h"
#include "ExprNode.h"

class IfNode: public StmtNode
{
    public:
        IfNode(ExprNode* expr = nullptr, StmtNode* stmt1 = nullptr, StmtNode* stmt2 = nullptr)
		    :m_expr(expr), m_stmt1(stmt1), m_stmt2(stmt2)
		{}
        string toString()
		{
			string tempStr = "(IF: " + m_expr->toString() + "\n" + m_stmt1->toString() + "\n";
			
			if(m_stmt2 != nullptr)
				tempStr += "ELSE:\n" + m_stmt2->toString() + "\n";
			
			tempStr += ")";
			
			return tempStr;
		}
		
		int ComputeOffsets(int base)
		{
			m_expr->ComputeOffsets(base);
			m_stmt1->ComputeOffsets(base);
			m_stmt2->ComputeOffsets(base);
			return base;
		}
    
    private:
        ExprNode* m_expr;
        StmtNode* m_stmt1;
        StmtNode* m_stmt2;
};