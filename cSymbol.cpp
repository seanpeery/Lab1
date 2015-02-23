#include "cSymbol.h"

int cSymbol::symbolCount = 0;

cSymbol::cSymbol(string symbol, bool type)
    :m_symbol(symbol), m_sequence(++symbolCount), m_type(type), m_declared(false), m_typeRef(""), m_decl(nullptr)
{}

string cSymbol::toString()
{
    return "sym: "+ m_symbol + " " + std::to_string(m_sequence);
}

bool cSymbol::IsType()
{
    return m_type;
}

string cSymbol::GetSymbol()
{
    return m_symbol;
}

void cSymbol::SetTypeFlag()
{
    m_type = true;
}

void cSymbol::SetDeclared()
{
    m_declared = true;
}

bool cSymbol::IsDeclared()
{
    return m_declared;
}

void cSymbol::SetTypeRef(string typeRef, string baseType, DeclNode* decl)
{
    m_typeRef = typeRef;
    m_baseType = baseType;
    m_decl = decl;
}

string cSymbol::GetType()
{
    return m_typeRef;
}

string cSymbol::GetBaseType()
{
    return m_baseType;
}

DeclNode* cSymbol::GetRef()
{
    return m_decl;
}

void cSymbol::ReduceSymbolCount()
{
    symbolCount--;
}
