#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int ROWS, COLS;
  bool **seen;

  bool isWater(char c)
  {
    return c == '0';
  }

public:
  void setUpState(vector<vector<char>> &grid)
  {
    this->ROWS = grid.size();
    this->COLS = grid[0].size();

    this->seen = new bool *[this->ROWS];

    for (int i = 0; i < this->ROWS; i++)
    {
      this->seen[i] = new bool[this->COLS];
      fill(this->seen[i], this->seen[i] + this->COLS, false);
    }
  }

  void dfs(int row, int col, vector<vector<char>> &grid)
  {
    bool rowOutOfRange = row < 0 || row >= this->ROWS;
    bool colOutOfRange = col < 0 || col >= this->COLS;
    if (rowOutOfRange || colOutOfRange)
      return;

    if (this->isWater(grid[row][col]))
      return;

    // Prevent unnecessary computing
    if (this->seen[row][col])
      return;

    this->seen[row][col] = true;

    dfs(row, col - 1, grid); // top
    dfs(row, col + 1, grid); // bottom
    dfs(row - 1, col, grid); // left
    dfs(row + 1, col, grid); // right
  }

  int numIslands(vector<vector<char>> &grid)
  {
    this->setUpState(grid);

    int islandsCount = 0;

    for (int i = 0; i < this->ROWS; i++)
    {
      for (int j = 0; j < this->COLS; j++)
      {
        if (this->isWater(grid[i][j]))
          continue;

        if (!this->seen[i][j])
        {
          dfs(i, j, grid);
          islandsCount++;
        }
      }
    }

    return islandsCount;
  }
};

int main()
{

  vector<vector<char>>
      test = {
          {'1', '1', '1', '1', '0'},
          {'1', '1', '0', '1', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '0', '0', '0'}};

  Solution s;
  cout << s.numIslands(test) << endl;
  return 0;
}