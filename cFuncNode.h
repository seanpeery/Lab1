#pragma once
//***********************************************************************
// Purpose: Function declaration/definition
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

class cFuncNode : public cAstNode
{
  public:
    // id is name of function
    // params are the formal parameters
    cFuncNode(cSymbol *id, cAstNode *parms) 
    {
        mId = id;
        mParms = parms;
        mDecls = NULL;
        mStmts = NULL;
    }

    // Add the decls and statements to the function
    // In other words, turn a declaration into a definition
    void SetDetails(cAstNode *decls, cAstNode *stmts)
    {
        mDecls = decls;
        mStmts = stmts;
    }

    virtual std::string toString()
    {
        std::string result("(FUNC: ");
        result += mId->toString();
        if (mParms != NULL) 
            result += mParms->toString();
        else
            result += "()";
        if (mDecls != NULL) result += "\n" + mDecls->toString();
        if (mStmts != NULL) result += "\n" + mStmts->toString();
        result += "\n)";
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cSymbol *mId;           // name of function
    cAstNode *mParms;       // formal parameters
    cAstNode *mDecls;       // local variable declarations
    cAstNode *mStmts;       // statements
	bool mError;
};

