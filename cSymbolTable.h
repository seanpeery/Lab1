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
        cSymbolTable();
        void IncreaseScope(); //scope control
        void DecreaseScope();
        cSymbol* InsertSymbol(string symbol);

    private:
        list<unordered_map<string,cSymbol*>*> m_tables;
};