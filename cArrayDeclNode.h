#pragma once
//***********************************************************************
// Purpose: Node for variable declaration
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <string>

#include "cScope.h"
#include "cAstNode.h"
#include "cStructDeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"

class cArrayDeclNode : public cAstNode
{
  public:
    cArrayDeclNode(cSymbol *type, cSymbol *id, cAstNode *arraySpec)
    {
        // We may have an id from an outter scope. This will either
        // create a new symbol or return the already existing symbol 
        // in the current scope.
        id = symbolTableRoot->Insert(id->getName());

        mType = type;
        mId = id;
		mArraySpec = arraySpec;
		id->SetType(this);
    }
	
	cSymbol *GetType()
    {
        return mId;
    }
	
    virtual std::string toString()
    {
        std::string result("ARRAY: ");
        result += mType->toString();
        result += " " + mId->toString();
        if (mArraySpec != NULL) result += " " + mArraySpec->toString();

        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cSymbol *mType;         // type of the variable
    cSymbol *mId;           // name of variable
    cAstNode *mArraySpec;   // array specification (NULL if not an array)
	bool mError;
};
