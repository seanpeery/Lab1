// cSymbolTable.h
// Created by Sean Peery
// 
// Header file for symbol table

#pragma once
#include <string>
#include <iostream>
#include "cSymbol.h"
#include <unordered_map>
#include <list>

using std::string;
using std::unordered_map;
using std::list;

class cSymbolTable 
{
    public:
        static cSymbolTable* GetInstance();
        unordered_map<string,cSymbol*>* IncreaseScope(); //scope control
        void DecreaseScope();
        cSymbol* InsertSymbol(string symbol, bool type = false);
        cSymbol* Lookup(string symbol);

    private:
        cSymbolTable();
        list<unordered_map<string,cSymbol*>*> m_tables;
        static cSymbolTable* m_symbols;
};