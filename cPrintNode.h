#pragma once
//***********************************************************************
// Purpose: Node for a print statement
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

class cPrintNode : public cAstNode
{
  public:
    // expr is the value to be printed
    cPrintNode(cAstNode *expr) 
    {
        mExpr = static_cast<cExprNode *>(expr);
    }

    virtual std::string toString()
    {
        std::string result("PRINT: ");
        result += mExpr->toString();
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cExprNode *mExpr;       // expression to be printed
	bool mError;
};

