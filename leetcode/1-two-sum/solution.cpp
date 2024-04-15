#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> prev_nums_idx;
    vector<int> res(2);

    for (int i = 0; i < nums.size(); i++)
    {
      int curr_num = nums[i];
      int complementary_num = target - curr_num;

      if (prev_nums_idx.find(complementary_num) != prev_nums_idx.end())
      {
        res[0] = prev_nums_idx[complementary_num];
        res[1] = i;
        break;
      }

      prev_nums_idx[curr_num] = i;
    }

    return res;
  }
};
