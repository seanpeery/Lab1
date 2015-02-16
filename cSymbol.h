#pragma once
//***********************************************************************
// Purpose: Defines a symbol
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include <string>
#include "cAstNode.h"


class cSymbol
{
    public:
		bool mFirst;
        // create a Symbol for the given name n
        cSymbol(std::string n) 
        {
            name = n; 
            sequence = ++totalSymbols;
            mType = NULL;
            mIsType = false;
            mIsFunc = false;
			mFirst = true;
        }

        // return the name of the symbol
        std::string getName() {return name;}

        // set the type of the symbol
        // NOTE: for functions, use SetFuncType
        void SetType(cAstNode *typeSpec)
        {
            mType = typeSpec;
            mIsType = true;
        }

        // set the type of a symbol that represents a function
        void SetFuncType(cAstNode *typeSpec)
        {
            mType = typeSpec;
            mIsFunc = true;
        }

        // return the type of the symbol
        cAstNode *GetType()
        {
            if (mIsType || mIsFunc) return mType;
            return NULL;
        }

        // Return true if the symbol represents a type
        bool IsType()
        { return mIsType; }

        // return a string representation of the symbol
        virtual std::string toString()
        {
            std::string result("sym: ");
            result += name + " ";
            result += std::to_string(static_cast<long long>(sequence));

            return result;
        }

    protected:
        std::string name;           // name of the symbol
        int sequence;               // unique ID for symbol
        cAstNode *mType;            // AstNode for the type of the symbol
        bool mIsType;               // True if this is a type
        bool mIsFunc;               // True if this is a function
        static int totalSymbols;    // STATIC: keeps track of total number of
                                    // symbols that have been created. Used
                                    // to assign sequence: unique ID
};
