#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
#define umap unordered_map
// #define uset unordered_set
#define pii pair<int, int>
#define minHeapInt priority_queue<int, vector<int>, greater<>>
#define si short int
#define pq priority_queue

// Globals
si SEEN_MARK = 1;

// Whether the input has multiple test cases
bool multi = false;

void solve()
{
  int R, C;
  cin >> R >> C;

  umap<int, pii> indices;
  vector<vector<int>> menu(R, vector<int>(C));

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
    {
      cin >> menu[i][j];
      indices[menu[i][j]] = {i, j};
    }

  int maxDishes = 0;

  vector<si> seen(R * C, -1);

  auto dfs = [&](auto f, int currDish, int currMax, int dishesCount, minHeapInt &neighbors) -> void
  {
    auto [currRow, currCol] = indices[currDish];

    // Vertical neighbors
    for (int offset = -1; offset <= 1; offset += 2)
    {
      int neighborRow = currRow + offset;
      bool isInBounds = neighborRow >= 0 && neighborRow <= R - 1;

      if (!isInBounds)
        continue;

      int neighborDish = menu[neighborRow][currCol],
          neighborDishIdx = neighborDish - 1;

      if (neighborDish <= currMax || seen[neighborDishIdx] == SEEN_MARK)
        continue;

      neighbors.push(neighborDish);
      seen[neighborDishIdx] = SEEN_MARK;
    }

    // Horizontal neighbors
    for (int offset = -1; offset <= 1; offset += 2)
    {
      int neighborCol = currCol + offset;
      bool isInBounds = neighborCol >= 0 && neighborCol <= C - 1;

      if (!isInBounds)
        continue;

      int neighborDish = menu[currRow][neighborCol],
          neighborDishIdx = neighborDish - 1;

      if (neighborDish <= currMax || seen[neighborDishIdx] == SEEN_MARK)
        continue;

      neighbors.push(neighborDish);
      seen[neighborDishIdx] = SEEN_MARK;
    }

    // End
    if (neighbors.empty())
    {
      maxDishes = max(maxDishes, dishesCount);
      return;
    }

    int nextDish = neighbors.top();
    neighbors.pop();

    f(f, nextDish, nextDish, dishesCount + 1, neighbors);
  };

  for (int row = 0; row < R; row++)
  {
    for (int col = 0; col < C; col++)
    {
      minHeapInt neighbors;

      int currDish = menu[row][col],
          currDishIdx = currDish - 1;

      seen[currDishIdx] = SEEN_MARK;

      dfs(dfs, currDish, currDish, 1, neighbors);

      SEEN_MARK++;
    }
  }

  cout << maxDishes << endl;
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