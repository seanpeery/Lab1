// IntExprNode.h
// Author: Sean Peery

#pragma once

#include "ExprNode.h"

class IntExprNode : public ExprNode
{
    public:
        IntExprNode(int val = -1)
		    :m_val(val)
		{}
        string toString()
		{
			return "(EXPR: " + std::to_string(m_val) + ")";
		}

        string GetType()
		{
			if(m_val >= -128 && m_val <= 127)
				return "char";
			return "int";
		}
		
        string GetBaseType()
		{
			return GetType();
		}
    
    private:
        int m_val;
};