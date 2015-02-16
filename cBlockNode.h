#pragma once
//***********************************************************************
// Purpose: Definition of Block node
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <string>

#include "cAstNode.h"

class cBlockNode : public cAstNode
{
  public:
    cBlockNode(cAstNode *decls, cAstNode *stmts) 
    {
        mDecls = decls;
        mStmts = stmts;
    }

    virtual std::string toString()
    {
        std::string result("BLOCK: \n{\n");
        if (mDecls != NULL) result += mDecls->toString();
        if (mStmts != NULL) result += mStmts->toString();
        result += "}\n";
        
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cAstNode *mDecls;       // Declarations
    cAstNode *mStmts;       // Statements
	bool mError;
};

