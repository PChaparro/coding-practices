#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
private:
  int ROWS;
  int COLS;

  void setupState(vector<vector<int>> &land)
  {
    this->ROWS = land.size();
    this->COLS = land[0].size();
  }

  pii dfs(pii coords, vector<vector<int>> &land)
  {
    auto [row, col] = coords;

    bool rowOutOfRange = row >= this->ROWS;
    if (rowOutOfRange)
      return {row - 1, col};

    bool colOutOfRange = col >= this->COLS;
    if (colOutOfRange)
      return {row, col - 1};

    if (isNotFarmLand(land[row][col]))
      return {row - 1, col - 1};

    // Mark the land to avoid unnecessary computation
    land[row][col] = -1;

    // Return the max possible coord
    pii rightCoords = dfs({row, col + 1}, land);
    pii bottomCoords = dfs({row + 1, col}, land);

    return {
        max(rightCoords.first, bottomCoords.first),
        max(rightCoords.second, bottomCoords.second)};
  }

  bool isNotFarmLand(int val)
  {
    return val != 1;
  }

public:
  vector<vector<int>> findFarmland(vector<vector<int>> &land)
  {
    this->setupState(land);

    vector<vector<int>> farmlandsCoors;

    for (int i = 0; i < this->ROWS; i++)
    {
      for (int j = 0; j < this->COLS; j++)
      {
        if (isNotFarmLand(land[i][j]))
          continue;

        pii bottomRightCorner = dfs({i, j}, land);
        farmlandsCoors.push_back({i, j, bottomRightCorner.first, bottomRightCorner.second});
      }
    }

    return farmlandsCoors;
  }
};