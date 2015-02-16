#pragma once
//***********************************************************************
// Purpose: A single symbol table. A scope.
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include "cSymbol.h"
#include <unordered_map>

class cScope
{
  public:
    // p is the parent of the current scope. 
    // Used when decreasing scope
    cScope(cScope *p) : mSymTab()
    {
        mParent = p;
    }

    // Insert a symbol into the table
    void Insert(std::string name, cSymbol *symbol)
    {
        mSymTab[name] = symbol;
    }

    // Look for a symbol. Returns NULL if symbol is not found.
    cSymbol *Lookup(std::string name)
    {
        std::unordered_map<std::string, cSymbol*>::const_iterator found;
        found = mSymTab.find(name);
        if (found != mSymTab.end()) return found->second;

        return NULL;
    }

    // return the parent of this table. 
    // Used when decreasing scope
    cScope *Parent()
    {
        return mParent;
    }
  protected:
    // pointer to a hash table used to store info
    std::unordered_map<std::string, cSymbol*> mSymTab;

    cScope *mParent;      // Pointer to higher scope table
};
