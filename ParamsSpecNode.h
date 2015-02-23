// ParamsSpecNode.h
// Author: Sean Peery

#pragma once

#include "StmtNode.h"
#include "ParamSpecNode.h"

class ParamsSpecNode : public StmtNode
{
    public:
        ParamsSpecNode()
		{}
		
        string toString()
		{
			string retVal = "(PARAMS:";
			
			for(auto &param : m_params)
				retVal += " " +param->toString();
			
			retVal += ")\n";
			
			return retVal;
		}

        void Add(ParamSpecNode* param = nullptr)
		{
			m_params.push_back(param);
		}
        
    private:
        list<ParamSpecNode*> m_params;
};