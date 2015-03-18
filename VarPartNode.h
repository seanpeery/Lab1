// VarPartNode.h
// Author: Sean Peery

#pragma once

#include "ExprNode.h"
#include "ArrayValNode.h"
#include "cSymbol.h"

class VarPartNode : public ExprNode
{
    public:
        VarPartNode(cSymbol* identifier = nullptr, ArrayValNode* newArray = nullptr)
		    :m_identifier(identifier), m_array(newArray)
		{ }
		
        string toString()
		{
			string tempStr = m_identifier->toString();
			
			if(m_array != nullptr)
				tempStr += "[" + m_array->toString() + "]";
			
			return tempStr;
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
			if(m_array != nullptr)
				return m_identifier->GetBaseType();
			else
				return GetType();
		}

        string GetSymbol()
		{
			return m_identifier->GetSymbol();
		}
        double GetValue()
		{
			return 0;
		}
    private:
        cSymbol* m_identifier;
        ArrayValNode* m_array;
};
