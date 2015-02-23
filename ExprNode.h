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
    virtual DeclNode* GetTypeRef()
    {
      return nullptr;
    }
};