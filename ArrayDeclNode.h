// ArrayDeclNode.h
// Author: Sean Peery

#pragma once

#include "DeclNode.h"
#include "ArraySpecNode.h"
#include "cSymbol.h"

class ArrayDeclNode : public DeclNode
{
    public:
        ArrayDeclNode(cSymbol* typeId = nullptr, cSymbol* identifier = nullptr, ArraySpecNode* array = nullptr)
            :m_typeId(typeId), m_identifier(identifier), m_array(array)
		{
			m_identifier->InitializeSize(m_typeId->GetSize() * m_array->GetSize());
		}

		string toString()
		{
			string tempStr = "ARRAY: ";
			
			tempStr += m_typeId->toString() + " " + m_identifier->toString();
			if(m_array != nullptr)
				tempStr += " " + m_array->toString();
				
			tempStr += " size: " + std::to_string(m_size);
			tempStr += " offset: " + std::to_string(m_offset);
		
			return tempStr;
		}
	
		int ComputeOffsets(int base)
		{
		    m_offset = base;
			m_size = m_identifier->GetSize();
			
			base = m_offset + m_size;
			return base;
		}
		int GetSize()
		{
			return m_identifier->GetSize();
		}
		
		void GenerateCode()
		{
			generate->StackSizeUp(m_size);
		}
		
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
        ArraySpecNode* m_array;
};