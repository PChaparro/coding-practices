#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
// #define umap unordered_map
#define uset unordered_set
// typedef pair<int,int> pii;

// Whether the input has multiple test cases
bool multi = true;

void solve()
{
  // Receive values
  vector<uset<char>> square(3);
  int missing_value_row;
  char ci;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> ci;
      square[i].insert(ci);

      if (ci == '?')
      {
        missing_value_row = i;
      }
    }
  }

  // Get the missing value
  char expected_values[3] = {'A', 'B', 'C'};

  for (int i = 0; i < 3; i++)
  {
    if (square[missing_value_row].find(expected_values[i]) == square[missing_value_row].end())
    {
      cout << expected_values[i] << endl;
      return;
    }
  }
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