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
        
        
    protected:
        bool m_semanticError;
};