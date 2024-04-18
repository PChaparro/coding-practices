#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int l = nums.size(), c;
    vector<int> res(l, -1);
    stack<int> pending;

    for (int ci = 0; ci < (l * 2) - 1; ci++)
    {
      int i = ci % l;
      c = nums[i];

      while (!pending.empty() && nums[pending.top()] < c)
      {
        res[pending.top()] = c;
        pending.pop();
      }

      pending.push(i);
    }

    return res;
  }
};