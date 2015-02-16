#pragma once
//***********************************************************************
// Purpose: Node for a scan statement
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <string>

#include "cAstNode.h"
#include "cSymbol.h"

class cScanNode : public cAstNode
{
  public:
    // lval is where the scanned value is to be stored
    cScanNode(cAstNode *lval) 
    {
        mLval = lval;
    }

    virtual std::string toString()
    {
        std::string result("SCAN: ");
        result += mLval->toString();
        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cAstNode *mLval;        // destination for scanned value
	bool mError;
};

