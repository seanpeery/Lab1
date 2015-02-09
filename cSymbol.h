// cSymbol.h
// Created by Sean Peery
// 
// Header file for symbols

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using std::string;

class cSymbol
{
	public:
		cSymbol(string symbol, bool type = false);
		string toString();
		bool IsTyped();
		string GetSymbol();
		void SetTyped();
    
	protected:
		string m_symbol;
		int m_label;
		static int totalSymbols;
		bool m_setType;
};