// FloatExprNode.h
// Author: Sean Peery

#pragma once

#include "ExprNode.h"

class FloatExprNode : public ExprNode
{
    public:
        FloatExprNode(double val = 0.0)
		    :m_val(val)
		{m_size = 8;}

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
		
		void GenerateCode()
		{
			generate->EmitString(std::to_string(m_val));
		}

		double GetValue()
		{
			return m_val;
		}
				
    private:
        double m_val;
};
