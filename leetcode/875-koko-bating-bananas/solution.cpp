#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int maxPileHeight = INT_MIN;
    for (int pileHeight : piles)
      maxPileHeight = max(maxPileHeight, pileHeight);

    int l = 1,
        r = maxPileHeight,
        pileHeightAtMid;

    long long minK = LONG_LONG_MAX,
              currK,
              neededHours;

    while (l <= r)
    {
      currK = (l + r) / 2;
      neededHours = 0;

      for (int pileHeight : piles)
      {
        neededHours += (pileHeight + currK - 1) / currK;
        if (neededHours > h)
          break;
      }

      if (neededHours > h)
        l = currK + 1;
      else
      {
        r = currK - 1;
        minK = min(minK, currK);
      }
    }

    return minK;
  }
};
