// ParamSpecNode.h
// Author: Sean Peery

#pragma once

#include <string>
#include "VarNode.h"
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
    
    private:
        VarNode* m_param;
    
};