#include <bits/stdc++.h>
using namespace std;

#define u_set unordered_set

class Solution
{
public:
  int dfs(int row, int col, bool **seen, vector<vector<int>> &grid)
  {
    int perimeterAddedByCurrBlock = 0;

    // Return 1 if the block if the sand is limiting with void or water
    bool rowOutOfGrid = row < 0 || row >= grid.size();
    bool colOutOfGrid = col < 0 || col >= grid[0].size();

    if (rowOutOfGrid || colOutOfGrid || !grid[row][col])
      return 1;

    // Prevent duplicates
    if (seen[row][col])
      return 0;

    seen[row][col] = 1;

    // Calc any other direction
    perimeterAddedByCurrBlock += dfs(row - 1, col, seen, grid); // Top
    perimeterAddedByCurrBlock += dfs(row + 1, col, seen, grid); // Bottom
    perimeterAddedByCurrBlock += dfs(row, col - 1, seen, grid); // Left
    perimeterAddedByCurrBlock += dfs(row, col + 1, seen, grid); // Right

    return perimeterAddedByCurrBlock;
  }

  int islandPerimeter(vector<vector<int>> &grid)
  {
    bool **seen2 = new bool *[grid.size()];
    for (int i = 0; i < grid.size(); i++)
    {
      seen2[i] = new bool[grid[0].size()];
      fill(seen2[i], seen2[i] + grid[0].size(), false);
    }

    int perimeter = 0;

    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        // Ignore 'water blocks'
        if (!grid[i][j])
          continue;

        int res = dfs(i, j, seen2, grid);
        perimeter += res;
      }
    }

    return perimeter;
  }
};