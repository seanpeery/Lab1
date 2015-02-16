#pragma once
//***********************************************************************
// Purpose: Node for variable reference
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
#include "cError.h"

class cVarRefNode : public cAstNode
{
  public:
    // arrayPart is NULL if this isn't an array reference
    cVarRefNode(cSymbol *var, cAstNode *arrayPart) 
    {
		std:: string temp;
		if (symbolTableRoot->Lookup(var->getName()) != NULL)
		{
			//If the variable has not been set in the code yet trigger this
			if (symbolTableRoot->Lookup(var->getName())->mFirst)
			{
				temp = "Symbol " + var->getName() + " not defined";
				semantic_error(temp);
			}
		}
		else
		{
			temp = "Symbol " + var->getName() + " not defined";
			semantic_error(temp);
		}
		
        mId = var;
        mArrayPart = arrayPart;
        mList = NULL;
    }

    // if this is a struct reference, this adds a field specifier
    void AddNode(cAstNode *structRef) 
    {
        if (mList == NULL) 
        {
            mList = new cAstList(false);
            mList->AddNode(structRef);
        }
        else
            mList->AddNode(structRef);
    }

    virtual std::string toString()
    {
        std::string result("(VarRef: ");
        result += mId->toString();
        if (mArrayPart != NULL) result += "[" + mArrayPart->toString() + "]";
        if (mList != NULL) result += "\n" + mList->toString();
        result += ")";

        return result;
    }

	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}
	
  protected:
    cSymbol *mId;           // name of variable being referenced
    cAstNode *mArrayPart;   // Array specification (NULL if not an array ref)
    cAstList *mList;        // List of fields if this is a struct reference
	bool mError;
};

