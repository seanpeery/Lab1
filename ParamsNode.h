// ParamsNode.h
// Author: Sean Peery

#pragma once

#include "StmtNode.h"
#include "ParamNode.h"

class ParamsNode : public StmtNode
{
    public:
        ParamsNode()
		{m_parOffset = 0;}
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
        
		void GenerateCode()
		{
			for(ParamNode *param : m_params)
			{
				param->GenerateCode();
				m_parOffset += param->GetSize();
			}
		}
		
		int GetParamsOffset()
		{
			return m_parOffset;
		}
		
    private:
        list<ParamNode*> m_params;
		int m_parOffset;
};
