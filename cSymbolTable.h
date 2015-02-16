#pragma once
//***********************************************************************
// Purpose: Definition of the Symbol Table
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include "cSymbol.h"
#include "cScope.h"

class cSymbolTable
{
  public:
    // create an empty symbol table
    cSymbolTable();

    // Insert a symbol into the table. If symbol already exists, returns
    // the preexisting symbol. Otherwise, return new symbol
    cSymbol *Insert(std::string);

    // Look for a symbol. Returns NULL if symbol is not found.
    cSymbol *Lookup(std::string name);

    // Increase the scoping level. 
    // A new table is created with a pointer to the old (higher scope) table 
    // Returns pointer to new table.
    void IncreaseScope();

    // Lower the scoping level.
    // Returns a pointer to the current (after decrease) table
    void DecreaseScope();

    // create a default table with symbols for base types
    static cSymbolTable *CreateDefaultTable();
//  protected:
    // pointer to a hash table used to store info
    cScope *mScope;

    // lookup a symbol in the local ST without looking at parent
    cSymbol *LocalLookup(std::string name);
};
