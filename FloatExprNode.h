// FloatExprNode.h
// Author: Sean Peery

#pragma once

#include "ExprNode.h"

class FloatExprNode : public ExprNode
{
    public:
        FloatExprNode(double val = 0.0)
		    :m_val(val)
		{}

        string toString()
		{
			return "(EXPR: " + std::to_string(m_val) + ")";
		}

        string GetType()
		{
			return "float";
		}

        string GetBaseType()
		{
			return GetType();
		}
				
    private:
        double m_val;
};
