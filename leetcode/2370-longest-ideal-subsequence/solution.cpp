#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestIdealString(string s, int k)
  {
    int res = INT_MIN;

    vector<int> longestEndingWith(26, 0);

    for (char currChar : s)
    {
      int currCharASCII = currChar - 'a';
      int left = max(currCharASCII - k, 0);
      int right = min(currCharASCII + k, 25);

      int maxInRange = INT_MIN;

      for (; left <= right; left++)
        maxInRange = max(maxInRange, longestEndingWith[left]);

      longestEndingWith[currCharASCII] = maxInRange + 1;
      res = max(res, longestEndingWith[currCharASCII]);
    }

    return res;
  }
};