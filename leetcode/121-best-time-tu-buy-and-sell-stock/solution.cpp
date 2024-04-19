#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int DEFAULT_PROFIT = 0;

public:
  int maxProfit(vector<int> &prices)
  {
    int maxProfit = this->DEFAULT_PROFIT;

    int l = 0,
        r = l + 1;

    while (r < prices.size())
    {
      maxProfit = max(maxProfit, prices[r] - prices[l]);

      if (prices[l] > prices[r])
        l = r;

      r++;
    }

    return maxProfit;
  }
};