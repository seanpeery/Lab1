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
			string tempStr = "(PARAMS:";
			
			for(ParamSpecNode * param : m_params)
				tempStr += param->toString() + " ";
			
			tempStr += ")\n";
			
			return tempStr;
		}

        void Add(ParamSpecNode* param = nullptr)
		{
			m_params.push_back(param);
		}

		int ComputeOffsets(int base)
		{
			
			m_offset = base;
			for(ParamSpecNode * param : m_params)
			{
				m_offset = param->ComputeOffsets(m_offset);
			}
			base = m_offset;
			return base;
		}
		
		void GenerateCode()
		{
			for(ParamSpecNode * param : m_params)
				param->GenerateCode();
		}
        
    private:
        list<ParamSpecNode*> m_params;
};