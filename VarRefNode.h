// VarRefNode.h
// Author: Sean Peery

#pragma once

#include "VarPartNode.h"
#include "ExprNode.h"
#include "StructDeclNode.h"
#include "cSymbolTable.h"

extern cSymbolTable* symbolTableRoot;

class VarRefNode : public ExprNode
{
    public:
        VarRefNode()
		    :m_error("")
		{ }
        string toString()
		{
			string tempStr = "";
			list<VarPartNode*>::iterator it;
			
			for(it = m_varParts.begin(); it != m_varParts.end(); ++it )
			{
				tempStr += "(VarRef: " + (*it)->toString() + " ";
			}
			
			for(size_t i = 0; i < m_varParts.size() - 1; ++i)
				tempStr += ")";
			
			tempStr += "size: " + std::to_string(m_size);
			tempStr += " offset: " + std::to_string(m_offset);
			tempStr += ")";
			
			return tempStr;
		}
		
        void Add(VarPartNode* varPart = nullptr)
		{
			m_semanticError = false;
			if(m_varParts.size() == 0)
			{
				if(!varPart->GetIdentifier()->IsDeclared())
				{
					m_error = "Symbol " + varPart->GetIdentifier()->GetSymbol() + " not defined";
					m_semanticError = true;
				}
			}
			else
				m_semanticError = FindSymbolInParent(varPart);
			
			if(!m_semanticError)
				m_varParts.push_back(varPart);
			
		}

        string GetType()
		{
			return (*m_varParts.rbegin())->GetType();
		}

        DeclNode* GetTypeRef()
		{
			return (*m_varParts.rbegin())->GetTypeRef();
		}
		
        string GetErrorMsg()
		{
			return m_error;
		}
		
        string Vref()
		{
			string vref = "";
			int count = m_varParts.size() - 1;
			for(list<VarPartNode*>::iterator i = m_varParts.begin(); i != m_varParts.end(); ++i, --count)
			{
				if(count == 0)
					vref += (*i)->GetIdentifier()->GetSymbol();
				else
					vref += (*i)->GetIdentifier()->GetSymbol() + ".";
			}
			
			return vref;
		}
        bool FindSymbolInParent(VarPartNode* part)
		{
			cSymbol* sym = nullptr;
			VarPartNode* vp = *(m_varParts.rbegin());
			StructDeclNode* struc = nullptr;
			try
			{
				//Try to downcast parent to struct decl
				struc = dynamic_cast<StructDeclNode*>(vp->GetTypeRef());
			}
			catch(int e)
			{}
			
			if(struc != nullptr)
				sym = struc->Find(part->GetIdentifier()->GetSymbol());
			else
			{
				m_error = Vref() + " is not a struct";
				return true;
			}

			if(sym != nullptr)
			{
				symbolTableRoot->RemoveSymbol(part->GetIdentifier());
				part->SetIdentifier(sym);
			}
			else if(!m_semanticError)
			{
				m_error = part->GetIdentifier()->GetSymbol() + " is not a field of " + Vref();
				return true;
			}
			
			return false;
		}

        string GetBaseType()
		{
			return (*m_varParts.rbegin())->GetBaseType();
		}

        string GetSymbol()
		{
			return (*m_varParts.rbegin())->GetSymbol();
		}

		int ComputeOffsets(int base)
		{    
//		std::cout<< "\nbase"<< (*m_varParts.rbegin())->GetTypeRef()->GetCalculatedOffset() << "\n";
			m_size = (*m_varParts.rbegin())->GetTypeRef()->GetCalculatedSize();
			m_offset = (*m_varParts.begin())->GetTypeRef()->GetCalculatedOffset();

			if(m_varParts.size() > 1)
			{
				DeclNode* decl = (*m_varParts.begin())->GetTypeRef();
				m_offset = decl->GetCalculatedOffset();
				list<VarPartNode*>::iterator iter = m_varParts.begin();
				for(++iter; iter != m_varParts.end(); ++iter)
				{
					StructDeclNode* strucDecl = dynamic_cast<StructDeclNode*>(decl);

					if(strucDecl != nullptr)
						m_offset += strucDecl->FindSymbolOffset((*iter)->GetIdentifier());
					else
						m_offset += decl->GetCalculatedOffset();
					decl = (*iter)->GetTypeRef();
				}
			}
			return base;
		}
			
    private:
        list<VarPartNode*> m_varParts;
        string m_error;
};