// ScanNode.h
// Author: Sean Peery

#pragma once


#include "StmtNode.h"
#include "ExprNode.h"

class ScanNode: public StmtNode
{
    public:
        ScanNode(ExprNode* expr = nullptr)
		    :m_expr(expr)
		{}
        string toString()
		{
			return "SCAN: " + m_expr->toString();
		}

		int ComputeOffsets(int base)
		{
		    m_expr->ComputeOffsets(base);
			return base;
		}
    
    private:
        ExprNode* m_expr;
};