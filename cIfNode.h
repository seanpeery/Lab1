#pragma once
//***********************************************************************
// Purpose: Node for an IF statement
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

class cIfNode : public cAstNode
{
  public:
    cIfNode(cAstNode *expr, cAstNode *ifPart, cAstNode *elsePart) 
    {
        mExpr = static_cast<cExprNode *>(expr);
        mStmt = ifPart;
        mElse = elsePart;
    }

    virtual std::string toString()
    {
        std::string result("(IF: ");
        result += mExpr->toString();
        result += "\n" + mStmt->toString();
        if (mElse != NULL) result += "\nELSE:\n" + mElse->toString();
        result += "\n)";
        return result;
    }

	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}
	
  protected:
    cExprNode *mExpr;       // Condition
    cAstNode *mStmt;        // statement for TRUE brance
    cAstNode *mElse;        // statement for FALSE branch
	bool mError;
};

