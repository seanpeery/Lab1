// ParamsNode.h
// Author: Sean Peery

#pragma once

#include "StmtNode.h"
#include "ParamNode.h"

class ParamsNode : public StmtNode
{
    public:
        ParamsNode()
		{}
        string toString()
		{
			if(m_params.size() > 0)
			{
				string retVal = "(PARAM:";
			
				for(auto &param : m_params)
					retVal += param->toString()+" ";
				
				retVal += ")\n";
				return retVal;
			}
			
			return "";
		}
        void Add(ParamNode* param = nullptr)
		{
			if(param != nullptr)
				m_params.push_back(param);
		}
        
    private:
        list<ParamNode*> m_params;
};
