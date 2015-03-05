// BinaryExprNode.h
// Author: Sean Peery

#pragma once

#include <math.h>
#include "ExprNode.h"

class BinaryExprNode : public ExprNode
{
    public:
        BinaryExprNode(ExprNode* lhs = nullptr, char oper = '-', ExprNode* rhs = nullptr)
		    :m_lhs(lhs), m_oper(oper), m_rhs(rhs)
		{}
        string toString()
		{
			return "(EXPR: " + m_lhs->toString() + " " + m_oper + " " + m_rhs->toString() + ")";
		}

        string GetType()
		{
			if(m_lhs->GetType() == "float" || m_rhs->GetType() == "float")
				return "float";
				
			return m_lhs->GetType();
		}
		
        string GetBaseType()
		{
			return GetType();
		}
		
		int ComputeOffsets(int base)
		{
			m_lhs->ComputeOffsets(base);
			m_rhs->ComputeOffsets(base);
			
			return base;
		}
    
    private:
        ExprNode* m_rhs;
        char m_oper;
        ExprNode* m_lhs;
        
};