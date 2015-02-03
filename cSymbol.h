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
		cSymbol(string symbol); //constructor
		string toString(); //output
    
	protected:
		string m_symbol;
		int m_label;
		static int totalSymbols;
};