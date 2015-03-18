// ParamSpecNode.h
// Author: Sean Peery

#pragma once

#include <string>
#include "VarNode.h"
#include "StmtNode.h"
using std::string;

class ParamSpecNode
{
    public:
        ParamSpecNode(VarNode* node = nullptr)
		    :m_param(node)
		{}
        string toString()
		{
			return m_param->toString();
		}

		int ComputeOffsets(int base)
		{
			return m_param->ComputeOffsets(base);
		}
		
		void GenerateCode()
		{
			m_param->GenerateCode();
		}
    
    private:
        VarNode* m_param;
    
};