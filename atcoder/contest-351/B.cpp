#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
// #define umap unordered_map
// #define uset unordered_set
// typedef pair<int,int> pii;

// Whether the input has multiple test cases
bool multi = false;

void solve()
{
  int N;
  cin >> N;

  char expected[N][N];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> expected[i][j];

  char Bij;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> Bij;

      if (expected[i][j] != Bij)
      {
        cout << i + 1 << " " << j + 1 << endl;
        return;
      }
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