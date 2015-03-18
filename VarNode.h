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
		{ }
        string toString()
		{
			string tempStr = "VAR: ";
			
			tempStr += m_typeId->toString() + " " + m_identifier->toString();
			tempStr += " size: " + std::to_string(m_size);
			tempStr += " offset: " + std::to_string(m_offset);
			return tempStr;
		}
        cSymbol* GetSymbol()
        {
            return m_identifier;
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
};