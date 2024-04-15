#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    // The max heights to the left and right will act as the walls of the container
    int left = 0,
        maxHeightLeft = height[left],
        right = height.size() - 1,
        maxHeightRight = height[right];

    int trappedWater = 0;

    while (left < right)
    {
      /* We always want to move the pointer that has the smaller max height
       * because we want to try to find a higher wall to trap more water. There's
       * no point in moving the pointer that has the higher wall because it's our
       * current optimal wall (+height = +trapped water).
       * */
      if (maxHeightLeft < maxHeightRight)
      {
        trappedWater += maxHeightLeft - height[left];
        ++left;
        maxHeightLeft = max(maxHeightLeft, height[left]);
      }
      else
      {
        trappedWater += maxHeightRight - height[right];
        --right;
        maxHeightRight = max(maxHeightRight, height[right]);
      }
    }

    return trappedWater;
  }
};