#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int left = 0, right = numbers.size() - 1;

    while (left < right)
    {
      int currentSum = numbers[left] + numbers[right];

      if (currentSum == target)
        return {left + 1, right + 1};

      else if (currentSum > target)
        --right;

      else
        ++left;
    }

    return {-1, -1};
  }
};

int main()
{
  Solution s;
  vector<int> t = {5, 25, 75};
  vector<int> res = s.twoSum(t, 100);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}