#pragma once
//***********************************************************************
// Purpose: Node for a return statement
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

class cReturnNode : public cAstNode
{
  public:
    // expr is the value to be returned
    cReturnNode(cAstNode *expr) 
    {
        mExpr = static_cast<cExprNode *>(expr);
    }

    virtual std::string toString()
    {
        std::string result("RETURN: ");
        result += mExpr->toString();
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cExprNode *mExpr;       // value to be returned
	bool mError;
};

