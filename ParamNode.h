// ParamNode.h
// Author: Sean Peery


#pragma once

#include "ExprNode.h"

class ParamNode
{
    public:
        ParamNode(ExprNode* expr = nullptr)
		    :m_expr(expr)
		{}
        string toString()
		{
			return m_expr->toString();
		}

		int ComputeOffsets(int base)
		{
		    m_expr->ComputeOffsets(base);
			return base;
		}
    
    private:
        ExprNode* m_expr;
};