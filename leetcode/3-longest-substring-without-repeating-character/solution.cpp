#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() == 0)
      return 0;

    unordered_set<char> seen;

    int l = 0,
        res = 0;

    char currChar;

    for (int r = 0; r < s.size(); r++)
    {
      currChar = s[r];

      while (seen.find(currChar) != seen.end())
      {
        seen.erase(s[l]);
        l++;
      }

      seen.insert(currChar);
      res = max(res, (r - l) + 1);
    }

    return res;
  }
};