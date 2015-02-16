#pragma once
//***********************************************************************
// Purpose: Formal parameters for a function declaration
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

class cParamsNode: public cAstNode
{
  public:
    // param is declaration of first parameter
    cParamsNode(cAstNode *param) 
    {
        mList = new cAstList(false);
        mList->AddNode(param);
    }

    // Add a parameter to the list
    void AddNode(cAstNode *param) 
    {
        mList->AddNode(param);
    }

    virtual std::string toString()
    {
        std::string result("(PARAMS:");
        result += mList->toString();
        result += ")\n";

        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cAstList *mList;        // list of parameters
	bool mError;
};

