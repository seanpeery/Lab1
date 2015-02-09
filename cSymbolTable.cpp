// cSymbolTable.cpp
// Created by Sean Peery

#include "cSymbolTable.h"

//Initialize a symbol table
cSymbolTable* cSymbolTable::m_symbols = nullptr;

// Constructor
cSymbolTable::cSymbolTable()
{
	m_tables.push_front(new unordered_map<string,cSymbol*>());
	m_tables.front()->insert(std::pair<string,cSymbol*>("char", new cSymbol("char", true)));
	m_tables.front()->insert(std::pair<string,cSymbol*>("int", new cSymbol("int", true)));
	m_tables.front()->insert(std::pair<string,cSymbol*>("float", new cSymbol("float", true)));
}

//Returns the contents of a symbol table
cSymbolTable* cSymbolTable::GetInstance()
{
	if(m_symbols == nullptr)
		m_symbols = new cSymbolTable();
	
	return m_symbols;
}

// Pushes another table on a stack
unordered_map<string,cSymbol*>* cSymbolTable::IncreaseScope()
{
	m_tables.push_front(new unordered_map<string,cSymbol*>());
	return m_tables.front();
}

// Removes the current table from the stack
void cSymbolTable::DecreaseScope()
{	
	m_tables.pop_front();
}

// Inserts symbol into the table
cSymbol* cSymbolTable::InsertSymbol(string symbol, bool type)
{
	cSymbol * temp;
	unordered_map<string,cSymbol*>::iterator it = m_tables.front()->find(symbol);
	
	if(it == m_tables.front()->end())
	{
		temp = new cSymbol(symbol, type);
		m_tables.front()->insert(std::pair<string,cSymbol*>(symbol, temp));
	}
	else
		temp = it->second;
	
	return temp;
}

//Searches for a symbol by name
cSymbol* cSymbolTable::Lookup(string symbol)
{
	list<unordered_map<string,cSymbol*>*>::iterator tbl;
	for(tbl = m_tables.begin(); tbl != m_tables.end(); ++tbl)
	{
		unordered_map<string,cSymbol*>::iterator temp = (*tbl)->find(symbol);
		
		if(temp != (*tbl)->end())
			return temp->second;
	}
	
	return nullptr;
}