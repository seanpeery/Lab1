// cSymbol.cpp
// Created by Sean Peery

#include "cSymbol.h"
// Keeps track of total number of symbols created in the instance
int cSymbol::totalSymbols = 0; 

// Constructor
// Increments number of symbols everytime called
cSymbol::cSymbol(string symbol)
    :m_symbol(symbol), m_label(++totalSymbols)
{}

// Returns a string value representing the interepreted data
string cSymbol::toString()
{
    return "sym: "+ m_symbol + " " + std::to_string(m_label);
}