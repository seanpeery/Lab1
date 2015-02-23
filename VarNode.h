// VarNode.h
// Author: Sean Peery

#pragma once

#include "DeclNode.h"
#include "cSymbol.h"

class VarNode : public DeclNode
{
    public:
        VarNode(cSymbol* typeId = nullptr, cSymbol* identifier = nullptr)
		    :m_typeId(typeId), m_identifier(identifier)
		{}
        string toString()
		{
			string retVal = "VAR: ";
			
			retVal += m_typeId->toString() + " " + m_identifier->toString();
			
			return retVal;
		}
        cSymbol* GetSymbol()
        {
            return m_identifier;
        }
    
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
};