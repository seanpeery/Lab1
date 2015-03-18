// PrintNode.h
// Author: Sean Peery

#pragma once

#include "StmtNode.h"
#include "ExprNode.h"

class PrintNode: public StmtNode
{
    public:
        PrintNode(ExprNode* expr = nullptr)
		    :m_expr(expr)
		{}
        string toString()
		{
			return "PRINT: " + m_expr->toString();
		}
		int ComputeOffsets(int base)
		{
		    m_expr->ComputeOffsets(base);
			return base;
		}
		
		void GenerateCode()
		{
			if(m_expr->GetBaseType() == "float")
				generate->EmitString("printf(\"%6.4f\\n\",");
			else
				generate->EmitString("printf(\"%d\\n\",");
			m_expr->GenerateCode();
			generate->EmitString(");\n");
		}
    private:
        ExprNode* m_expr;
};