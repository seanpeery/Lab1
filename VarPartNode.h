// VarPartNode.h
// Author: Sean Peery

#pragma once

#include "ExprNode.h"
#include "ArrayValNode.h"
#include "cSymbol.h"

class VarPartNode : public ExprNode
{
    public:
        VarPartNode(cSymbol* identifier = nullptr, ArrayValNode* ary = nullptr)
		    :m_identifier(identifier), m_ary(ary)
		{}
		
        string toString()
		{
			string retVal = m_identifier->toString();
			
			if(m_ary != nullptr)
				retVal += "[" + m_ary->toString() + "]";
			
			return retVal;
		}

        string GetType()
		{
			return m_identifier->GetType();
		}
		
        cSymbol* GetIdentifier()
		{
			return m_identifier;
		}
		
        DeclNode* GetTypeRef()
		{
			return m_identifier->GetRef();
		}

        void SetIdentifier(cSymbol* identifier)
		{
			m_identifier = identifier;
		}
		
        string GetBaseType()
		{
			if(m_ary != nullptr)
				return m_identifier->GetBaseType();
			else
				return GetType();
		}

        string GetSymbol()
		{
			return m_identifier->GetSymbol();
		}
        
    private:
        cSymbol* m_identifier;
        ArrayValNode* m_ary;
};
