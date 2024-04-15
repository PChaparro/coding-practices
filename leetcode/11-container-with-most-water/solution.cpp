#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int maxAreaSoFar = INT_MIN;

    int left = 0,
        right = height.size() - 1;

    while (left < right)
    {
      int leftH = height[left],
          rightH = height[right];

      int b = right - left,
          h = min(leftH, rightH);

      int currArea = b * h;
      maxAreaSoFar = max(maxAreaSoFar, currArea);

      if (leftH < rightH)
        ++left;
      else
        --right;
    }

    return maxAreaSoFar;
  }
};

int main()
{
  Solution s;
  vector<int> test = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << s.maxArea(test) << endl;

  return 0;
}