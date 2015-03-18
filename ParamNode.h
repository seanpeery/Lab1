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
		
		void GenerateCode()
		{
			if(m_expr->GetBaseType() == "float")
				generate->EmitString("FLOAT_VAL(Stack_Pointer) = ");
			else
				generate->EmitString("INT_VAL(Stack_Pointer) = ");
			
			m_expr->GenerateCode();
			generate->EmitString(";\n");
			m_size = m_expr->GetSize();
			generate->StackSizeUp(m_size);
		}
		int GetSize ()
		{
			return m_size;
		}
    private:
        ExprNode* m_expr;
		int m_size;
};