#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int nRows = matrix.size(),
        nCols = matrix[0].size();

    int left = 0,
        right = nRows * nCols - 1,
        mid,
        midRow,
        midCol,
        numAtMid;

    while (left <= right)
    {
      mid = (left + right) / 2;
      midRow = mid / nCols;
      midCol = mid % nCols;

      numAtMid = matrix[midRow][midCol];

      if (numAtMid == target)
        return true;
      else if (numAtMid < target)
        left = mid + 1;
      else
        right = mid - 1;
    }

    return false;
  }
};