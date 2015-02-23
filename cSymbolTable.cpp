// cSymbolTable.cpp
// Created by Sean Peery

#include "cSymbolTable.h"

//Initialize a symbol table
cSymbolTable* cSymbolTable::m_symbols = nullptr;

// Constructor
cSymbolTable::cSymbolTable()
{
    m_tables.push_front(new map<string,cSymbol*>());
        
    cSymbol* global = new cSymbol("char", true);
    global->SetTypeRef("char", "char", nullptr);
    m_tables.front()->insert(std::pair<string,cSymbol*>("char", global));
    
    global = new cSymbol("int", true);
    global->SetTypeRef("int", "int", nullptr);
    m_tables.front()->insert(std::pair<string,cSymbol*>("int", global));
    
    global = new cSymbol("float", true);
    global->SetTypeRef("float","float",nullptr);
    m_tables.front()->insert(std::pair<string,cSymbol*>("float", global));
}

cSymbolTable* cSymbolTable::GetInstance()
{
    if(m_symbols == nullptr)
        m_symbols = new cSymbolTable();
    
    return m_symbols;
}

map<string,cSymbol*>* cSymbolTable::IncreaseScope()
{
    map<string,cSymbol*> * newMap = new map<string,cSymbol*>();
    //Add symbol table to list
    m_tables.push_front(newMap);
    return newMap;
}

void cSymbolTable::DecreaseScope()
{
    m_tables.pop_front();
}

// Inserts symbol into the table
cSymbol* cSymbolTable::InsertSymbol(string symbol, bool type)
{
	cSymbol * temp;
	map<string,cSymbol*>::iterator it = m_tables.front()->find(symbol);
	
	if(it == m_tables.front()->end())
	{
		temp = new cSymbol(symbol, type);
		m_tables.front()->insert(std::pair<string,cSymbol*>(symbol, temp));
	}
	else
		temp = it->second;
	
	return temp;
}

//Lookups a symbol from all symbol tables currently in list
cSymbol* cSymbolTable::Lookup(string symbol)
{
    list<map<string,cSymbol*>*>::iterator tbl;
    for(tbl = m_tables.begin(); tbl != m_tables.end(); ++tbl)
    {
        map<string,cSymbol*>::iterator temp = (*tbl)->find(symbol);
        
        if(temp != (*tbl)->end())
            return temp->second;
    }
    
    return nullptr;
}

bool cSymbolTable::LocalLookUp(string symbol)
{
    map<string,cSymbol*>::iterator it = m_tables.front()->find(symbol);
    
    if(it != m_tables.front()->end())
        return true;
    
    return false;
}

void cSymbolTable::RemoveSymbol(cSymbol* symbol)
{
    symbol->ReduceSymbolCount();
    m_tables.front()->erase(symbol->GetSymbol());
}