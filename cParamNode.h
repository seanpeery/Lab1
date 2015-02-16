#pragma once
//***********************************************************************
// Purpose: List of actual arguments in a function call
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <string>

#include "cAstNode.h"
#include "cAstList.h"

class cParamNode: public cAstNode
{
  public:
    // param is expression for first agrument
    cParamNode(cAstNode *param) 
    {
        mList = new cAstList(false);
        mList->AddNode(param);
    }

    // Add a parameter to the list
    // param is an expression
    void AddNode(cAstNode *param) 
    {
        mList->AddNode(param);
    }

    virtual std::string toString()
    {
        std::string result("(PARAM:");
        result += mList->toString();
        result += ")\n";

        return result;
    }

	bool SemanticError()
	{
		return mError;
	}
	
  protected:
    cAstList *mList;    // list of expressions. 
	bool mError;
};

