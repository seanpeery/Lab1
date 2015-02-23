#pragma once

#include "DeclNode.h"
#include "ArraySpecNode.h"
#include "cSymbol.h"

class ArrayDeclNode : public DeclNode
{
    public:
        ArrayDeclNode(cSymbol* typeId = nullptr, cSymbol* identifier = nullptr, ArraySpecNode* array = nullptr)
            :m_typeId(typeId), m_identifier(identifier), m_array(array)
		{}

		string toString()
		{
			string retVal = "ARRAY: ";
			
			retVal += m_typeId->toString() + " " + m_identifier->toString();
			if(m_array != nullptr)
				retVal += " " + m_array->toString();
			
			return retVal;
		}
		
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
        ArraySpecNode* m_array;
};