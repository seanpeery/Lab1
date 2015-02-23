#pragma once

#include <list>
#include <string>
#include "ExprNode.h"
using std::list;
using std::string;

class ArrayValNode
{
    public:
        ArrayValNode()
		{}
		
        void Add(ExprNode* val = nullptr)
		{
			m_val.push_back(val);
		}
		
        string toString()
		{
			string retVal = "(ARRAYVAL:";
			
			for(auto &expr : m_val)
				retVal += " " + expr->toString();
			
			retVal += ")";
			
			return retVal;
		}
        
    private:
        list<ExprNode*> m_val;
};