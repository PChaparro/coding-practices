#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
// #define umap unordered_map
#define uset unordered_set
// typedef pair<int,int> pii;
#define si short int

// Whether the input has multiple test cases
bool multi = false;

// Globals
si MAGNET_MARK = 0,
   MAGNET_NEIGHBOR_MARK = 1,
   FREE_MARK = 2;

char MAGNET = '#';

void markNeighbor(int r, int c, vector<vector<si>> &target)
{
  if (r < 0 || r >= target.size() ||
      c < 0 || c >= target[0].size())
    return;

  target[r][c] = MAGNET_NEIGHBOR_MARK;
}

void solve()
{
  int H, W;
  cin >> H >> W;

  vector<vector<char>> grid(H, vector<char>(W));

  // 0: Magnet, 1: Close to magnet, 2: Fully free
  vector<vector<si>> cellType(H, vector<si>(W, FREE_MARK));

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> grid[i][j];

      if (grid[i][j] == MAGNET)
      {
        cellType[i][j] = MAGNET_MARK;

        // Mark horizontal neighbors
        for (int offset = -1; offset <= 1; offset += 2)
          markNeighbor(i + offset, j, cellType);

        // Mark vertical neighbors
        for (int offset = -1; offset <= 1; offset += 2)
          markNeighbor(i, j + offset, cellType);
      }
    }
  }

  vector<vector<bool>> seen(H, vector<bool>(W, false));

  auto dfs = [&](auto f, int row, int col, uset<string> &group) -> void
  {
    string coord = to_string(row) + "," + to_string(col);
    group.insert(coord);
    // cout << coord << " was added to the group" << endl;

    if (cellType[row][col] == FREE_MARK)
      // Mark free cells that are part of the current group to avoid visiting 'em again
      seen[row][col] = true;
    else if (cellType[row][col] == MAGNET_NEIGHBOR_MARK)
      /** The cell can be added to the current group but we cannot move further and
       * it can be part of multiple groups so we don't mark it as seen
       */
      return;

    bool cgl = col > 0 && cellType[row][col - 1] != MAGNET_MARK,
         cgr = col < W - 1 && cellType[row][col + 1] != MAGNET_MARK,
         cgu = row > 0 && cellType[row - 1][col] != MAGNET_MARK,
         cgd = row < H - 1 && cellType[row + 1][col] != MAGNET_MARK;

    if (cgl && !seen[row][col - 1])
      f(f, row, col - 1, group);

    if (cgr && !seen[row][col + 1])
      f(f, row, col + 1, group);

    if (cgu && !seen[row - 1][col])
      f(f, row - 1, col, group);

    if (cgd && !seen[row + 1][col])
      f(f, row + 1, col, group);
  };

  int maxFreeDeg = INT_MIN;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (cellType[i][j] == FREE_MARK && !seen[i][j])
      {
        // cout << "Starting group at: " << i << "," << j << endl;
        uset<string> currGroup;

        dfs(dfs, i, j, currGroup);
        int finalSizeOfCurrGroup = currGroup.size();

        maxFreeDeg = max(maxFreeDeg, finalSizeOfCurrGroup);
      }
    }
  }

  cout << max(maxFreeDeg, 1) << endl;
}

int main()
{
  // Optimize IO
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // Handle multiple test cases
  int t = 1;
  if (multi)
    cin >> t;

  while (t--)
    solve();

  return 0;
}