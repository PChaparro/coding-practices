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
}