#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "DeclNode.h"
using std::string;

class cSymbol
{
  public:
    cSymbol(string symbol, bool type = false);
    string toString();
    bool IsType();
    string GetSymbol();
    void SetTypeFlag();
    void SetDeclared();
    bool IsDeclared();
    void SetTypeRef(string typeRef, string baseType, DeclNode* decl = nullptr);
    string GetType();
    string GetBaseType();
    DeclNode* GetRef();
    void ReduceSymbolCount();
    int GetSize();
	void InitializeSize(int size);
	
  private:
    string m_symbol;
    int m_sequence;
    static int symbolCount;
    bool m_type;
    bool m_declared;
    string m_typeRef;
    DeclNode* m_decl;
    string m_baseType;
	int m_size;
};