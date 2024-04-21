#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
public:
  int minimumOperations(vector<vector<int>> &grid)
  {
    int ROWS = grid.size(),
        COLS = grid[0].size();

    vector<unordered_map<int, int>> numberInColCount(COLS);
    for (int i = 0; i < ROWS; i++)
    {
      for (int j = 0; j < COLS; j++)
      {
        numberInColCount[j][grid[i][j]]++;
      }
    }

    // We gonna save {number, cost_to_change_to_number}
    vector<vector<pii>> costs(COLS);

    for (int col = 0; col < COLS; col++)
    {
      for (int n = 0; n < 10; n++)
      {
        int costOfChangingColToN = ROWS - numberInColCount[col][n],
            minCostOfPrevCol = 0;

        if (col > 0)
        {
          bool minOfPrevColIsN = costs[col - 1][0].first == n;

          /**If the min costs of the previous col is obtained by changing the col to n,
           * we take the second min cost of the previous col to make this col different
           * from the previous one.
           */
          minCostOfPrevCol = minOfPrevColIsN ? costs[col - 1][1].second : costs[col - 1][0].second;
        }

        costs[col].push_back({n, costOfChangingColToN + minCostOfPrevCol});
      }

      sort(costs[col].begin(), costs[col].end(), [](const pii a, const pii b)
           { return a.second < b.second; });
    }

    return costs[COLS - 1][0].second;
  }
};