#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int left = 0;
        int right = s.length();

        vector<int> res;
        for (auto c : s)
        {
            if (c == 'I')
            {
                res.push_back(left);
                ++left;
            }
            else
            {
                res.push_back(right);
                --right;
            }
        }

        res.push_back(left);
        return res;
    }
};