// ReturnNode.h
// Author: Sean Peery

#pragma once

#include "StmtNode.h"
#include "ExprNode.h"

class ReturnNode: public StmtNode
{
    public:
        ReturnNode(ExprNode* expr = nullptr)
		    :m_expr(expr)
		{ }
		
        string toString()
		{
			return "RETURN: " + m_expr->toString();
		}

		int ComputeOffsets(int base)
		{
			m_expr->ComputeOffsets(base);
			return base;
		}
			
    private:
        ExprNode* m_expr;
};