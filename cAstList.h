#pragma once
//***********************************************************************
// Purpose: A list of AST nodes. Used for statements, decls, etc.
// Note: Should probably make this a generic
// Note 2: an STL implementation would be even better
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include "cAstNode.h"

class cAstList : public cAstNode
{
  public:
    // lineFeeds specifies whether a linefeed should be output between each
    // element when toStringing
    cAstList(bool lineFeeds)
    {
        mNext = NULL; 
        mLast = this; 
        mLineFeeds = lineFeeds;
        mNode = NULL;
    }

    virtual std::string toString()
    {
        // output the first element
        std::string result("");
        if (mNode != NULL) result += mNode->toString();
        if (mLineFeeds) result += "\n";

        // loop outputs the rest of the elements
        cAstList *next = mNext;
        while (next != NULL)
        {
            if (!mLineFeeds) result += " ";
            result += next->mNode->toString();
            if (mLineFeeds) result += "\n";

            next = next->mNext;
        }

        return result;
    }

    // Add a node to the list
    void AddNode(cAstNode *node)
    {
        // first node?
        if (mNode == NULL)
            mNode = node;
        else
        {
            // extend the list
            mLast->mNext = new cAstList(mLineFeeds);
            mLast->mNext->mNode = node;
            mLast = mLast->mNext;
        }
    }
	
	//Returns bool true if semantic error encountered
	bool SemanticError()
	{
		return mError;
	}
	
  protected:
    cAstList *mLast;        // end of the list
    cAstList *mNext;        // next element of the list
    cAstNode *mNode;        // value of current node
    bool mLineFeeds;        // add linefeeds between elements in toString
	bool mError;
};
