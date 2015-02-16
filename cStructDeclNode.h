#pragma once
//***********************************************************************
// Purpose: Node for a struct declaration
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
#include "cScope.h"

class cStructDeclNode : public cAstNode
{
  public:
    // symTab is the symbol table for the struct.
    // decls is the list of fields
    // id is the name of the struct
    cStructDeclNode(cScope *symTab, cAstNode *decls, cSymbol *id) 
    {
        mSymTab = symTab;
        mId = id;
        mDecls = decls;
        id->SetType(this);
    }

    // Return name of the struct
    cSymbol *GetType()
    {
        return mId;
    }

    virtual std::string toString()
    {
        std::string result("STRUCT: ");
        result += mDecls->toString();
        result += " " + mId->toString();

        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    cScope *mSymTab;            // symbol table for the struct
    cAstNode *mDecls;           // field list
    cSymbol *mId;               // name of the struct
	bool mError;
};

