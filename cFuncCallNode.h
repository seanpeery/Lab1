#pragma once
//***********************************************************************
// Purpose: Node representing a function call
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

class cFuncCallNode : public cAstNode
{
  public:
    // id is name of function
    // params is the list of actual arguments (NULL if there are none)
    cFuncCallNode(cSymbol *id, cAstNode *params) 
    {
        mId = id;
        mParams = params;
    }

    virtual std::string toString()
    {
        std::string result("(FUNC CALL: " + mId->toString());
        if (mParams != NULL) result += mParams->toString();
        result += ")";
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cSymbol *mId;           // name of function
    cAstNode *mParams;      // actual arguments
	bool mError;
};

