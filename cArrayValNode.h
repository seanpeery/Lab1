#pragma once
//***********************************************************************
// Purpose: Node for array_val
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

class cArrayValNode: public cAstNode
{
  public:
    // param is expresion specifying index
    cArrayValNode(cAstNode *param) 
    {
        mList = new cAstList(false);
        mList->AddNode(param);
    }

    // add an index. param is expression specifying index
    void AddNode(cAstNode *param) 
    {
        mList->AddNode(param);
    }

    // string representation of node
    virtual std::string toString()
    {
        std::string result("(ARRAYVAL:");
        result += mList->toString();
        result += ")";

        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cAstList *mList;        // list of expressions specifying index values
	bool mError;
};

