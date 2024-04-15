#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_set<int> unique_nums;

    for (int i = 0; i < nums.size(); i++)
    {
      int current_number = nums[i];

      if (unique_nums.find(current_number) != unique_nums.end())
        return true;

      unique_nums.insert(current_number);
    }

    return false;
  }
};