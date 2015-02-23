// FuncCallNode.h
// Author: Sean Peery

#pragma once

#include "cSymbol.h"
#include "ParamsNode.h"
#include "StmtNode.h"
#include "ExprNode.h"

class FuncCallNode : public StmtNode, public ExprNode
{
    public:
        FuncCallNode(cSymbol* identifier = nullptr, ParamsNode* params = nullptr)
		    :m_identifier(identifier), m_params(params)
		{}

        string toString()
		{
			string retVal = "(FUNC CALL: " + m_identifier->toString();
			
			if(m_params != nullptr)
				retVal += m_params->toString();
				
			retVal += ")\n";
			
			return retVal;
		}
		
        string GetType()
		{
			return m_identifier->GetType();
		}

        string GetBaseType()
		{
			return GetType();
		}
    
    private:
        cSymbol* m_identifier;
        ParamsNode* m_params;
};