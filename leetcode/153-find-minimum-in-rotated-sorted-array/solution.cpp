#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int l = 0,
        r = nums.size() - 1,
        res = INT_MAX,
        mid, numAtMid;

    while (l <= r)
    {
      mid = (l + r) / 2;
      numAtMid = nums[mid];

      if (numAtMid > nums[r])
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }

      res = min(res, numAtMid);
    }

    return res;
  }
};