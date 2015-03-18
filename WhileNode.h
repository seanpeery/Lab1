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

		int ComputeOffsets(int base)
		{
			m_expr->ComputeOffsets(base);
			return base;
		}
		void GenerateCode()
		{
			string tempStr = generate->GenerateLabel();
			string endStr = generate->GenerateLabel();
			generate->EmitString(tempStr + ":\n");
			generate->EmitString("if(!");
			m_expr->GenerateCode();
			generate->EmitString(") goto " + endStr + ";\n");
			m_stmt->GenerateCode();
			generate->EmitString("goto " + tempStr + ";\n");
			generate->EmitString(endStr + ":\n");
			
		}
    
    private:
        ExprNode* m_expr;
        StmtNode* m_stmt;
};