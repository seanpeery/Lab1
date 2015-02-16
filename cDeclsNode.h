#pragma once
//***********************************************************************
// Purpose: List of Declarations
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

class cDeclsNode : public cAstNode
{
  public:
    // decl is first declaration in decls
    cDeclsNode(cAstNode *decl) 
    {
        mList = new cAstList(true);
        mList->AddNode(decl);
    }

    // Add a declaration to the list
    void AddNode(cAstNode *decl) 
    {
        mList->AddNode(decl);
    }

    virtual std::string toString()
    {
        std::string result("DECLS:\n{\n");
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
    cAstList *mList;        // list of declarations
	bool mError;
};

