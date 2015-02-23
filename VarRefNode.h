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
		{}
        string toString()
		{
			string retVal = "";
			
			list<VarPartNode*>::iterator it;
			
			for(it = m_parts.begin(); it != m_parts.end(); ++it )
			{
				retVal += "(VarRef: " + (*it)->toString() + " ";
			}
			
			for(size_t i = 0; i < m_parts.size(); ++i)
				retVal += ")";
			
			return retVal;
		}
		
        void Add(VarPartNode* part = nullptr)
		{
			m_semanticError = false;
			
			if(m_parts.size() == 0)
			{
				if(!part->GetIdentifier()->IsDeclared())
				{
					m_error = "Symbol " + part->GetIdentifier()->GetSymbol() + " not defined";
					m_semanticError = true;
				}
			}
			else
				m_semanticError = FindSymbolInParent(part);
			
			if(!m_semanticError)
				m_parts.push_back(part);
			
		}

        string GetType()
		{
			return (*m_parts.rbegin())->GetType();
		}

        DeclNode* GetTypeRef()
		{
			return (*m_parts.rbegin())->GetTypeRef();
		}
		
        string GetErrorMsg()
		{
			return m_error;
		}
		
        string Vref()
		{
			string vref = "";
			int count = m_parts.size() - 1;
			for(list<VarPartNode*>::iterator i = m_parts.begin(); i != m_parts.end(); ++i, --count)
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
			VarPartNode* vp = *(m_parts.rbegin());
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
			return (*m_parts.rbegin())->GetBaseType();
		}

        string GetSymbol()
		{
			return (*m_parts.rbegin())->GetSymbol();
		}
			
    private:
        list<VarPartNode*> m_parts;
        string m_error;
};