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
				//When creating new node set semantic error based on wether
				//LHS memory size can hold RHS
			m_semanticError = CanAssign();
		}
		
        string toString()
		{
			return "(ASSIGN: " + m_lhs->toString() + " = " + m_rhs->toString() + ")" ;
		}

        bool CanAssign()
		{
			bool retVal = true;
			
			//If lhs size is larger than rhs size return false or
			//If lhs is char and rhs is IntExpr test to see if value is in range
			//Otherwise return semantic error
			if(m_lhs->GetType() != m_rhs->GetType())
			{
				// std::cout << "Types do not match checking base types" << std::endl;
				// std::cout << "LHS: " << m_lhs->GetSymbol() << " RHS: " << ((VarPart*)m_rhs)->GetSymbol() << std::endl;
				// std::cout << "LHS bType: " << m_lhs->GetBaseType() << " RHS bType: " << m_rhs->GetBaseType() << std::endl;
				//If base types match return false otherwise check datatypes
				//std::cout << "Comparing: " << m_lhs->GetBaseType() << " to " << m_rhs->GetBaseType() << std::endl;
				if(m_lhs->GetBaseType() != m_rhs->GetBaseType())
				{
					switch(m_lhs->GetBaseType()[0])
					{
						case 'c': //char
							break;
						case 'f': //float
							if(m_rhs->GetBaseType() == "int" || m_rhs->GetBaseType() == "char")
								retVal = false;
							break;
						case 'i': //int
							if(m_rhs->GetBaseType() == "char")
								retVal = false;
							break;
					}
				}
				else
					retVal = false;
			}
			else
				retVal = false;
				
			return retVal;
		}
		
        bool CharInRange(ExprNode* node = nullptr);
    
    private:
        VarRefNode* m_lhs;
        ExprNode* m_rhs;
};