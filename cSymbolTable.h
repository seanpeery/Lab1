// cSymbolTable.h
// Author: Sean Peery
// Symbol table

#pragma once

#include "cSymbol.h"
#include <string>
#include <iostream>
#include <map>
#include <list>

using std::string;
using std::map;
using std::list;

class cSymbolTable 
{
    public:
        static cSymbolTable* GetInstance();
        map<string,cSymbol*>* IncreaseScope();
        void DecreaseScope();
        cSymbol* InsertSymbol(string symbol, bool type = false);
        cSymbol* Lookup(string symbol);
        bool LocalLookUp(string symbol);
        void RemoveSymbol(cSymbol* symbol);

    private:
        cSymbolTable();
        list<map<string,cSymbol*>*> m_tables;
        static cSymbolTable* m_symbols;
};