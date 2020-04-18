/*
    Design and implement a program to produce a permuted index from the 
    following input. A permuted index is one in which each phrase is indexed
    by every word in the phrase.

            The quick      brown fox 
        jumped over the     fence
        The quick brown     fox 
                            jumped over the fence
                jumped     over the fence
                    The     quick brown fox 
            jumped over     the fence
                            The quick brown fox

    More info in:
     * The AWK Programming Language by Aho, Kernighan, and Weinberger, pp.122-124
     * https://everything2.com/title/permuted+index
     * https://en.wikipedia.org/wiki/Key_Word_in_Context
*/

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

using namespace std;

int main() 
{
    vector<Title> titles;

    string s;
    while (getline(cin, s))
    {
        for (string::size_type i = 0; i != s.size(); ++i)
        {
            Title t;

            if (isspace(s[i]))
            {
                t.begining = s.substr(0, i);
                t.end      = s.substr(i + 1, s.size() - 1);

                titles.push_back(t);
            }

            if (i == s.size() - 1 && !isspace(s[i]))
            {
                t.begining = "";
                t.end      = s;

                titles.push_back(t);
            }        
        }
    }

    sort(titles.begin(), titles.end(), compare);

    const string::size_type padding = max_begining_for(titles);

    for (vector<Title>::size_type i = 0; i != titles.size(); ++i)
    {
        cout << setw(padding) << titles[i].begining << "   " << titles[i].end << endl;
    }

    return 0;
}
