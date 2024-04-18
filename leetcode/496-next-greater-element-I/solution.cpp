#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> greaterThan;
    stack<int> decStack;

    for (int num : nums2)
    {
      while (!decStack.empty() &&
             decStack.top() < num)
      {
        int found = decStack.top();
        greaterThan[found] = num;
        decStack.pop();
      }

      decStack.push(num);
    }

    int resL = nums1.size();
    vector<int> res(resL);

    for (int i = 0; i < resL; i++)
    {
      if (greaterThan.find(nums1[i]) == greaterThan.end())
        res[i] = -1;
      else
        res[i] = greaterThan[nums1[i]];
    }

    return res;
  }
};