// ArraySpecNode.h
// Author: Sean Peery
#pragma once

#include <list>
#include <string>
using std::list;
using std::string;

class ArraySpecNode
{
    public:
        ArraySpecNode()
		{}

        string toString()
		{
			string tempStr = "(ARRAYSPEC:";
			
			for(int i : m_array)
				tempStr += " " + std::to_string(i);

			tempStr += ")";
			return tempStr;
		}
		
        void Add(int val = -1)
		{
			m_array.push_back(val);
		}

		int ComputeOffsets(int base)
		{
			return base;
		}
		
		int GetSize()
		{
			int tempInt = 0;
			list<int>::iterator it = m_array.begin();
			if(it != m_array.end())
				tempInt = *it;
			for(++it; it != m_array.end(); ++it)
				tempInt *= *it;
			
			return tempInt;
		}

    private:
        list<int> m_array;
};