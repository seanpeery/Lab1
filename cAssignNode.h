#pragma once
//***********************************************************************
// Purpose: Node for assignment statements
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <string>

#include "cAstNode.h"
#include "cExprNode.h"

class cAssignNode : public cAstNode
{
  public:
    cAssignNode(cAstNode *lval, cAstNode *expr) 
    {
        mLval = lval;
        mExpr = static_cast<cExprNode *>(expr);
    }

    virtual std::string toString()
    {
        std::string result("(ASSIGN: ");
        result += mLval->toString();
        result += " = ";
        result += mExpr->toString();
        result += ")";
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cExprNode *mExpr;   // expression for right hand side
    cAstNode *mLval;    // variable being assigned to
	bool mError;
};

