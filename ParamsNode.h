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
				string tempStr = "(PARAM:";
			
				for(ParamNode * param : m_params)
					tempStr += param->toString();
				
				tempStr += ")\n";
				return tempStr;
			}
			
			return "";
		}
        void Add(ParamNode* param = nullptr)
		{
			if(param != nullptr)
				m_params.push_back(param);
		}
		
		int ComputeOffsets(int base)
		{
			for(ParamNode * param : m_params)
				param->ComputeOffsets(base);
        
			return base;
		}
        
    private:
        list<ParamNode*> m_params;
};
