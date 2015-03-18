// ExprNode.h
// Author: Sean Peery

#pragma once

#include <string>
#include "cAstNode.h"
#include "DeclNode.h"
using std::string;

class ExprNode : public cAstNode
{
  public:
    virtual string GetType() = 0;
    virtual string GetBaseType() = 0;
	virtual double GetValue() = 0;
	int GetOffset() {return m_offset;}
    virtual DeclNode* GetTypeRef()
    {
      return nullptr;
    }
	virtual	int ComputeOffsets(int base)
	{
		return base;
	}
	virtual int GetSize()
	{
		return m_size;
	}
};