#pragma once
//***********************************************************************
// Purpose: Definition of base class for all AST nodes
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <iostream>
#include <string>

class cAstNode
{
  public:
    cAstNode() {}

    // return a string representation of the class
    virtual std::string toString() = 0;
	virtual bool SemanticError() = 0;
};

