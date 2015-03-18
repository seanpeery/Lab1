// AssignmentNode.h
// Author: Sean Peery
#pragma once

#include "StmtNode.h"
#include "ExprNode.h"
#include "VarRefNode.h"
#include "IntExprNode.h"

class AssignmentNode : public StmtNode
{
    public:
        AssignmentNode(VarRefNode* lhs = nullptr, ExprNode* rhs = nullptr)
		    :m_lhs(lhs), m_rhs(rhs)
		{
			m_semanticError = CanAssign();
		}
		
        string toString()
		{
			return "(ASSIGN: " + m_lhs->toString() + " = " + m_rhs->toString() + ")" ;
		}

        bool CanAssign()
		{
			bool validType = true;
			
			if(m_lhs->GetType() != m_rhs->GetType())
			{
				if(m_lhs->GetBaseType() != m_rhs->GetBaseType())
				{
					if (m_lhs->GetBaseType() == "float")
					{
						if(m_rhs->GetBaseType() == "int" || m_rhs->GetBaseType() == "char")
							validType = false;
					}
					else if (m_lhs->GetBaseType() == "int")
					{
						if(m_rhs->GetBaseType() == "char")
							validType = false;
					}
				}
				else
					validType = false;
			}
			else
				validType = false;
				
			return validType;
		}
		
    	int ComputeOffsets(int base)
		{
			m_lhs->ComputeOffsets(base);
			m_rhs->ComputeOffsets(base);
			return base;
		}

		void GenerateCode()
		{
			int offset = 0;
			offset = m_lhs->GetOffset();
			
			FuncCallNode* func = nullptr;
			try
			{
				func = dynamic_cast<FuncCallNode*>(m_rhs);
			}
			catch(int e)
			{
				//Not a function
			}
			
			if(func != nullptr)
				m_rhs->GenerateCode();

			if(m_lhs->GetBaseType() == "float")
				generate->EmitString("FLOAT_VAL(Frame_Pointer + " + std::to_string(offset) + ") = ");
			else
				generate->EmitString("INT_VAL(Frame_Pointer + "+ std::to_string(offset) + ") = ");
			

			if(func != nullptr)
			{
				if(func->GetBaseType() == "float")
					generate->EmitString("Temp_F");
				else
					generate->EmitString("Temp");
			}
			else
				m_rhs->GenerateCode();

			generate->EmitString(";\n");
		}
		
    private:
        VarRefNode* m_lhs;
        ExprNode* m_rhs;
};