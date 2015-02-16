#pragma once
//***********************************************************************
// Purpose: Node for a while statement
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

class cWhileNode : public cAstNode
{
  public:
    cWhileNode(cAstNode *expr, cAstNode *statements) 
    {
        mExpr = static_cast<cExprNode *>(expr);
        mStmt = statements;
    }

    virtual std::string toString()
    {
        std::string result("(WHILE: ");
        result += mExpr->toString();
        result += "\n" + mStmt->toString();
        result += "\n)";
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cExprNode *mExpr;       // condition
    cAstNode *mStmt;        // statement
	bool mError;
};

