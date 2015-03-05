// DeclNode.h
// Author: Sean Peery

#pragma once
#include "cAstNode.h"
#include <string>
using std::string;

class DeclNode : public cAstNode
{
    public:
		virtual int GetSize() = 0;
        int GetCalculatedSize()
        {
            return m_size;
        }
        
        int GetCalculatedOffset()
        {
            return m_offset;
        }		
};