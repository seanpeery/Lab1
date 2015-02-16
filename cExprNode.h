#pragma once
//***********************************************************************
// Purpose: Represent an Expression
// Note: This should probably be a base class with subclasses for the
//       various expression forms
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <string>

#include "cAstNode.h"

class cExprNode : public cAstNode
{
  public:
    // create an integer expression
    cExprNode(int value)
    {
        mIntVal = value;
        mIsInt = true;
        mIsFloat = false;
        mIsBinaryOp = false;
        mLeftExpr = NULL;
        mRightExpr = NULL;
    }

    // Create a float expression
    cExprNode(double value)
    {
        mFloatVal = value;
        mIsInt = false;
        mIsFloat = true;
        mIsBinaryOp = false;
        mLeftExpr = NULL;
        mRightExpr = NULL;
    }

    // Create a binary expression
    cExprNode(cAstNode *left, char op, cAstNode *right)
    {
        mIsInt = false;
        mIsFloat = false;
        mIsBinaryOp = true;
        mLeftExpr = static_cast<cExprNode *>(left);
        mOperator = op;
        mRightExpr = static_cast<cExprNode *>(right);
    }

	bool SemanticError()
	{
		return mError;
	}
	
	
    virtual std::string toString()
    {
        std::string result("(EXPR: ");
        if (mIsInt)
            result += std::to_string(static_cast<long long>(mIntVal));
        else if (mIsFloat)
            result += std::to_string(static_cast<long double>(mFloatVal));
        else
            result += mLeftExpr->toString() + " " 
                   + mOperator + " " 
                   + mRightExpr->toString();
        result += ")";

        return result;
    }

  protected:
    int mIntVal;                // value for integer literals
    double mFloatVal;           // value for float literals
    cExprNode *mLeftExpr;       // left operand for binary expressions
    cExprNode *mRightExpr;      // right operand for binary expressios
    char mOperator;             // operator for binary expressions
    bool mIsInt;                // flags indicating form of expression
    bool mIsFloat;
    bool mIsBinaryOp;
	bool mError;
};

