#include "cSymbol.h"

int cSymbol::totalSymbols = 0;

cSymbol::cSymbol(string symbol, bool type)
    :m_symbol(symbol), m_label(++totalSymbols), m_setType(type)
{}

string cSymbol::toString()
{
    return "sym: "+ m_symbol + " " + std::to_string(m_label);
}

bool cSymbol::IsTyped()
{
    return m_setType;
}

string cSymbol::GetSymbol()
{
    return m_symbol;
}

void cSymbol::SetTyped()
{
    m_setType = true;
}