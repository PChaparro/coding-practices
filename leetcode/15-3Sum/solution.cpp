#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    set<vector<int>> uniqueTriplets;
    set<int> seen;

    for (int i = 0; i < nums.size() - 2; i++)
    {
      int currNum = nums[i];

      if (seen.find(currNum) != seen.end())
        continue;

      int complSum = 0 - currNum;

      int left = i + 1, right = nums.size() - 1;

      while (left < right)
      {
        int currNumLeft = nums[left], currNumRight = nums[right];
        int currSum = currNumLeft + currNumRight;

        if (currSum == complSum)
        {
          uniqueTriplets.insert({currNum, currNumLeft, currNumRight});
          ++left;
          --right;
        }

        else if (currSum > complSum)
          --right;

        else
          ++left;
      }

      seen.insert(currNum);
    }

    vector<vector<int>> res(uniqueTriplets.begin(), uniqueTriplets.end());
    return res;
  }
};
