#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int l = nums.size();
    int prefix_product[l], suffix_product[l];

    for (int i = 0; i < l; i++)
    {
      if (i == 0)
      {
        prefix_product[i] = 1;
        suffix_product[l - i - 1] = 1;
        continue;
      }

      prefix_product[i] = prefix_product[i - 1] * nums[i - 1];
      suffix_product[l - i - 1] = suffix_product[l - i] * nums[l - i];
    }

    for (int i = 0; i < l; i++)
    {
      nums[i] = prefix_product[i] * suffix_product[i];
    }

    return nums;
  }
};
