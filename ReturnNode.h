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
		
		void GenerateCode()
		{
			if(m_expr->GetBaseType() == "float")
				generate->EmitString("Temp_F = ");
			else
				generate->EmitString("Temp = ");
			
			m_expr->GenerateCode();
			generate->EmitString(";\n");
		}
			
    private:
        ExprNode* m_expr;
};