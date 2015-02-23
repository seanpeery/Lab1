// WhileNode.h
// Author: Sean Peery

#pragma once

#include "StmtNode.h"
#include "ExprNode.h"

class WhileNode: public StmtNode
{
    public:
        WhileNode(ExprNode* expr = nullptr, StmtNode* stmt = nullptr)
		    :m_expr(expr), m_stmt(stmt)
		{}
        string toString()
		{
			return "(WHILE: " + m_expr->toString() + "\n" + m_stmt->toString() + "\n)";
		}
    
    private:
        ExprNode* m_expr;
        StmtNode* m_stmt;
};