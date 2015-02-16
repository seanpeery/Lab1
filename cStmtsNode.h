#pragma once
//***********************************************************************
// Purpose: List of statements
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

class cStmtsNode : public cAstNode
{
  public:
    // stmt is the first statement in the list
    cStmtsNode(cAstNode *stmt) 
    {
        mList = new cAstList(true);
        mList->AddNode(stmt);
    }

    // Add a statement to the list
    void AddNode(cAstNode *stmt) 
    {
        mList->AddNode(stmt);
    }

    virtual std::string toString()
    {
        std::string result("STMTS:\n{\n");
        result += mList->toString();
        result += "}\n";

        return result;
    }

	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}
	
  protected:
    cAstList *mList;    // list of statements
	bool mError;
};

