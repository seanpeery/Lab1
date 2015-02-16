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

#include "cAstNode.h"
#include "cStructDeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"
#include "cError.h"

class cVarDeclNode : public cAstNode
{
  public:
    // arraySpec is NULL if this is not an array
    cVarDeclNode(cSymbol *type, cSymbol *id) 
    {
		std::string temp;
		mError = false;
        // We may have an id from an outter scope. This will either
        // create a new symbol or return the already existing symbol 
        // in the current scope.

		if (symbolTableRoot->LocalLookup(id->getName()) == NULL)
			id = symbolTableRoot->Insert(id->getName());
		else
		{
			if (!(symbolTableRoot->LocalLookup(id->getName()))->mFirst)
			{
				temp = "Symbol " + id->getName() + " already defined in current scope";
				semantic_error(temp);
			}
//			std::cout << symbolTableRoot->LocalLookup(id->getName());
		}

        mType = type;
        mId = id;
    }

    // Create a variable that is a struct
//    cVarDeclNode(cAstNode *struc, cSymbol *id) 
//    {
//		if (symbolTableRoot->Lookup(id->getName()) == NULL)
//			mError = true;
//		else
//			mError = false;
//        // We may have an id from an outter scope. This will either
//        // create a new symbol or return the already existing symbol 
//        // in the current scope.
//        id = symbolTableRoot->Insert(id->getName());
//
//        mType = static_cast<cStructDeclNode *>(struc)->GetType();
//        mId = id;
//
//    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}
	
    virtual std::string toString()
    {
        std::string result("VAR: ");
        result += mType->toString();
        result += " " + mId->toString();

        return result;
    }

  protected:
    cSymbol *mType;         // type of the variable
    cSymbol *mId;           // name of variable
	bool mError;			// Error variable
};

