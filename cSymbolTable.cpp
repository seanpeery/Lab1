//***********************************************************************
// Purpose: Implementation of the Symbol Table
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************
#include <assert.h>
#include "cSymbol.h"
#include "cScope.h"
#include "cSymbolTable.h"


int cSymbol::totalSymbols = 0;              // total symbols created

//*******************************************
cSymbolTable::cSymbolTable() 
{
    mScope = new cScope(NULL);
}
//*******************************************
// create and return new symbol.
// If symbol already exists, return pointer to that symbol instead of creating
// a new one.
cSymbol *cSymbolTable::Insert(std::string name)
{
    // only check if symbol is in local table.
    // If we are defining a symbol that exists in an outer scope,
    // we still want to define a symbol in this scope.
    cSymbol *symbol = LocalLookup(name);

	
    // if symbol doesn't already exist, create a new one
    if (symbol == NULL)
    {
        symbol = new cSymbol(name);
        assert(symbol != NULL);

        mScope->Insert(name, symbol);
    }
	//else
		//semantic_error(name);
	// Could use an else to return a NULL if symbol already exists
    return symbol;
}
//*******************************************
// Look for a symbol. Return NULL if not found
cSymbol *cSymbolTable::LocalLookup(std::string name)
{
    return mScope->Lookup(name);
}
//*******************************************
// Look for a symbol. Return NULL if not found
cSymbol *cSymbolTable::Lookup(std::string name)
{
    cScope *scope = mScope;
    cSymbol *symbol = NULL;
    while (symbol == NULL && scope != NULL)
    {
        symbol = scope->Lookup(name);
        scope = scope->Parent();
    }

    return symbol;
}
//*******************************************
// Increase the scoping level. Save pointer to old (outer) scoping level.
// Return pointer to new symtab
void cSymbolTable::IncreaseScope()
{
    mScope = new cScope(mScope);
}
//*******************************************
// Decrease scoping level.
// DON'T destroy the current table because the parse tree will have
// references to the symbols stored here.
void cSymbolTable::DecreaseScope()
{
    // MEMORY LEAK:
    // we aren't deleteing the current table because parse tree has references
    // to our symbols
    
    mScope = mScope->Parent();
}
//*******************************************
// create default symbol table including definitions for default types
cSymbolTable *cSymbolTable::CreateDefaultTable()
{
    cSymbolTable *defaultTable = new cSymbolTable();
    defaultTable->Insert("char");
    defaultTable->Insert("int");
    defaultTable->Insert("float");
	//defaultTable->Insert("array");

    return defaultTable;
}

