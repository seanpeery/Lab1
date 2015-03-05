//cAstNode.cpp
//Author: Sean Peery
//Last edited 02/16/2015

#pragma once
#include <iostream>
#include <string>
using std::string;

class cAstNode
{
    public:
        virtual string toString() = 0;
        virtual bool SemanticError()
        {
            return m_semanticError;
        }
		virtual int ComputeOffsets(int base)  = 0;

        int CeilMod4(int base)
        {//Raises the value to the next number divisible by 4
            while((base % 4) != 0)
                base++;
            return base;
        }
		
    protected:
        bool m_semanticError;
		int m_offset;
        int m_size;
};