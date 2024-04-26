#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    int N = matrix.size();

    vector<vector<int>> minIfChoosen(N, vector<int>(N));

    // We save: {accSum, idxInRow}
    vector<vector<pii>> topOfRow(N, vector<pii>(2, {INT_MAX, -1}));

    for (int row = N - 1; row >= 0; row--)
    {
      bool isLastRow = row == N - 1;

      for (int col = 0; col < N; col++)
      {
        pii lowerInRow = topOfRow[row][0],
            lowerInRow2 = topOfRow[row][1];

        if (isLastRow)
        {
          // The acc sum at the last row is the cell itself
          minIfChoosen[row][col] = matrix[row][col];
        }
        else
        {
          // Add the value of the current cell to the optimal value of the previous row
          bool currColIsDiffThanNextRowOptimal = col != topOfRow[row + 1][0].second;

          pii lowerInPrevRow = currColIsDiffThanNextRowOptimal
                                   ? topOfRow[row + 1][0]  // We can take the optimal of the previous row
                                   : topOfRow[row + 1][1]; // We have to take the second optimal of the previous row

          minIfChoosen[row][col] = matrix[row][col] + lowerInPrevRow.first;
        }

        // Update the optimal values of the current row if needed
        int curr = minIfChoosen[row][col];

        if (lowerInRow.first == INT_MAX || curr < lowerInRow.first)
        {
          topOfRow[row][1] = topOfRow[row][0];
          topOfRow[row][0] = {curr, col};
        }
        else if (lowerInRow2.first == INT_MAX || curr < lowerInRow2.first)
        {
          topOfRow[row][1] = {curr, col};
        }
      }
    }

    // Look for the smaller value of the first row (smaller accumulated sum)
    int res = INT_MAX;

    for (int j = 0; j < N; j++)
      res = min(res, minIfChoosen[0][j]);

    return res;
  }
};