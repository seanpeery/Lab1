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
			string retVal = "(ARRAYSPEC:";
			
			for(auto &i : m_array)
				retVal += " " + std::to_string(i);

			retVal += ")";
			return retVal;
		}
		
        void Add(int val = -1)
		{
			m_array.push_back(val);
		}

    
    private:
        list<int> m_array;
};