#pragma once
//*******************************************************
// Purpose: Defines the node for an array specification
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//*******************************************************
#include <assert.h>
#include <string>

#include "cAstNode.h"

class cArraySpecNode: public cAstNode
{
  public:
    // value is the size for the current index
    cArraySpecNode(int value)
    {
        mDepth = 0;
        mSizes[mDepth] = value;
        mDepth++;

        assert(mDepth <= MAX_INDICES);
    }

    // add a dimention to the array.
    // value is the size of this dimention
    void AddNode(int value)
    {
        mSizes[mDepth] = value;
        mDepth++;

        assert(mDepth <= MAX_INDICES);
    }

    // output string representation
    virtual std::string toString()
    {
        std::string result("(ARRAYSPEC:");
        for (int ii=0; ii<mDepth; ii++)
        {
            result += " " + std::to_string((long long)mSizes[ii]);
        }
        result += ")";

        return result;
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}

  protected:
    static const int MAX_INDICES = 20;      // HACK: limit depth of arrays
    int mDepth;                             // How many dimentions
    int mSizes[MAX_INDICES];                // list of dimentions' sizes
	bool mError;
};

