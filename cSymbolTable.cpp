// cSymbolTable.cpp
// Created by Sean Peery

#include "cSymbolTable.h"

// Constructor
cSymbolTable::cSymbolTable()
{}

// Pushes another table on a stack
void cSymbolTable::IncreaseScope()
{
	m_tables.push_front(new unordered_map<string,cSymbol*>());
}

// Removes the current table from the stack
void cSymbolTable::DecreaseScope()
{
	m_tables.pop_front();
}

// Inserts symbol into the table
cSymbol* cSymbolTable::InsertSymbol(string symbol)
{
	cSymbol * temp;
	
	unordered_map<string,cSymbol*>::iterator it = m_tables.front()->find(symbol);
	
	if(it == m_tables.front()->end())
	{
		temp = new cSymbol(symbol);
		m_tables.front()->insert(std::pair<string,cSymbol*>(symbol, temp));
	}
	else
		temp = it->second;
	
	return temp;
}
