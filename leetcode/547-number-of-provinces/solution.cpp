#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int ROWS = isConnected.size(),
        COLS = isConnected[0].size();

    unordered_map<int, vector<int>> neighbors;

    for (int i = 0; i < ROWS; i++)
    {
      for (int j = 0; j < COLS; j++)
      {
        if (isConnected[i][j] == 1 && i != j)
          neighbors[i].push_back(j);
      }
    }

    int provincesCount = 0;

    vector<bool> seen(ROWS, false);

    auto neighborsDFS = [&](auto neighborsDFS, int currNode) -> void
    {
      seen[currNode] = true;

      for (int neighbor : neighbors[currNode])
        if (!seen[neighbor])
          neighborsDFS(neighborsDFS, neighbor);
    };

    for (int i = 0; i < ROWS; i++)
    {
      if (!seen[i])
      {
        neighborsDFS(neighborsDFS, i);
        provincesCount++;
      }
    }

    return provincesCount;
  }
};