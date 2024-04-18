#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> finalPrices(vector<int> &prices)
  {
    int l = prices.size(),
        currPrice,
        currIdxToApplyDiscount;

    vector<int> res(l);
    stack<int> pendingIndices;

    for (int i = 0; i < l; i++)
    {
      currPrice = prices[i];

      while (!pendingIndices.empty() &&
             currPrice <= prices[pendingIndices.top()])
      {
        currIdxToApplyDiscount = pendingIndices.top();
        res[currIdxToApplyDiscount] = prices[currIdxToApplyDiscount] - currPrice;
        pendingIndices.pop();
      }

      pendingIndices.push(i);
    }

    while (!pendingIndices.empty())
    {
      currIdxToApplyDiscount = pendingIndices.top();
      res[currIdxToApplyDiscount] = prices[currIdxToApplyDiscount];
      pendingIndices.pop();
    }

    return res;
  }
};