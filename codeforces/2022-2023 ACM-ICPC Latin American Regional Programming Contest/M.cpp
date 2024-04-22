#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
// #define umap unordered_map
// #define uset unordered_set
// typedef pair<int,int> pii;

bool multi = false;

// We need to use a different mark for the original nut and the flipped one
short int SEEN_MARK = 1;

bool isValidNutPosition(
    int currIdxOfNutStart,
    int currHeight,
    vector<bool> &nut,
    vector<vector<bool>> &maze)
{
  bool isValid = true;
  int currOffset = currIdxOfNutStart - 0;

  for (int c = 0; c < nut.size(); c++)
  {
    int currC = (c + currOffset) % nut.size();
    if (nut[currC] && maze[currHeight][c])
    {
      isValid = false;
      break;
    }
  }

  return isValid;
}

void solve()
{
  int ROWS, COLS;
  cin >> ROWS >> COLS;

  vector<bool> nut(COLS);

  for (int c = 0; c < COLS; c++)
  {
    char ni;
    cin >> ni;
    nut[c] = ni == '1';
  }

  vector<vector<bool>> maze(ROWS, vector<bool>(COLS));

  // For each height we save if the current config of the nut was used
  vector<vector<short int>> seen(ROWS, vector<short int>(COLS, 0));

  for (int r = 0; r < ROWS; r++)
  {
    for (int c = 0; c < COLS; c++)
    {
      char mrc;
      cin >> mrc;
      maze[r][c] = mrc == '1';
    }
  }

  auto dfs = [&](auto dfs, int idxOfNutStart, int currHeight) -> bool
  {
    // Avoid unnecessary computation
    seen[currHeight][idxOfNutStart] = SEEN_MARK;

    // Goal was reached
    if (currHeight == ROWS - 1)
      return true;

    // 1. Down
    if (seen[currHeight + 1][idxOfNutStart] != SEEN_MARK &&
        isValidNutPosition(idxOfNutStart, currHeight + 1, nut, maze))
    {
      if (dfs(dfs, idxOfNutStart, currHeight + 1))
        return true;
    }

    // 2. Left
    int idxOfRotatedNutStart = idxOfNutStart == 0 ? nut.size() - 1 : idxOfNutStart - 1;

    if (seen[currHeight][idxOfRotatedNutStart] != SEEN_MARK &&
        isValidNutPosition(idxOfRotatedNutStart, currHeight, nut, maze))
    {
      if (dfs(dfs, idxOfRotatedNutStart, currHeight))
        return true;
    }

    // 3. Right
    idxOfRotatedNutStart = (idxOfNutStart + 1) % nut.size();

    if (seen[currHeight][idxOfRotatedNutStart] != SEEN_MARK &&
        isValidNutPosition(idxOfRotatedNutStart, currHeight, nut, maze))
    {
      if (dfs(dfs, idxOfRotatedNutStart, currHeight))
        return true;
    }

    // 4. Up
    if (currHeight > 0 &&
        seen[currHeight - 1][idxOfNutStart] != SEEN_MARK &&
        isValidNutPosition(idxOfNutStart, currHeight - 1, nut, maze))
    {
      if (dfs(dfs, idxOfNutStart, currHeight - 1))
        return true;
    }

    return false;
  };

  // Check every starting position
  int idxOfNutStart = -1;

  for (int i = 0; i < nut.size(); i++)
  {
    idxOfNutStart = (idxOfNutStart + 1) % nut.size();

    if (!isValidNutPosition(idxOfNutStart, 0, nut, maze))
      continue;

    if (dfs(dfs, idxOfNutStart, 0))
    {
      cout << "Y" << endl;
      return;
    }
  }

  // Flip the nut and try every starting position
  reverse(nut.begin(), nut.end());
  idxOfNutStart = nut.size() - 2;

  // Update the mark for seen configs of the nut
  SEEN_MARK = 2;

  for (int i = 0; i < nut.size(); i++)
  {
    idxOfNutStart = (idxOfNutStart + 1) % nut.size();

    if (!isValidNutPosition(idxOfNutStart, 0, nut, maze))
      continue;

    if (dfs(dfs, idxOfNutStart, 0))
    {
      cout << "Y" << endl;
      return;
    }
  }

  cout << "N" << endl;
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