#include <string>
#include <vector>

#include "utils.h"

using namespace std;

bool compare (const Title& a, const Title& b)
{
    return a.end < b.end;
}

string::size_type max_begining_for (const vector<Title>& s)
{
    string::size_type max_length = 0;

    for (string::size_type i = 0; i != s.size(); ++i)
    {
        max_length = max(max_length, s[i].begining.size());
    }

    return max_length;
}
