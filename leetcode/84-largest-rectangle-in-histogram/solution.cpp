#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    // Add a negative bar at the end to force the evaluation of all pending bars
    heights.push_back(-1);

    stack<pii> pendingHsToEvalWithLeftReachIdx;
    int maxA = INT_MIN;

    for (int i = 0; i < heights.size(); i++)
    {
      int currH = heights[i];

      /**
       * Right now, we don't know if the current bar can be expanded to the left (if
       * there is a bar with the same of higher height to the left).
       *
       * Let's say we have the bars `6` and `7`. The bar `7` cannot be expanded to the
       * left because the bar `6` is limiting its height (The rectangle formed by the two
       * bars would have a height of `6` and a width of `2`).
       */
      int leftReachIdx = i;

      while (!pendingHsToEvalWithLeftReachIdx.empty() &&
             pendingHsToEvalWithLeftReachIdx.top().first > currH)
      {
        int h = pendingHsToEvalWithLeftReachIdx.top().first;

        /**
         * If the previous bar is higher than the current one, we can expand the
         * current bar to the left because the previous bar isn't limiting its
         * height.
         *
         * Let's say we have the bars `6` and `5`. The bar `5` can be expanded to the
         * left because the bar `6` isn't limiting its height (The rectangle formed by
         * the two bars would have a height of `5` and a width of `2`).
         */
        leftReachIdx = pendingHsToEvalWithLeftReachIdx.top().second;
        pendingHsToEvalWithLeftReachIdx.pop();

        int a = h * (i - leftReachIdx);
        maxA = max(maxA, a);
      }

      pendingHsToEvalWithLeftReachIdx.push({currH, leftReachIdx});
    }

    return maxA;
  }
};