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
  int ttTotal = 0,
      taTotal = 0,
      tti,
      tai;

  for (int i = 0; i < 9; i++)
  {
    cin >> tti;
    ttTotal += tti;
  }

  for (int i = 0; i < 8; i++)
  {
    cin >> tai;
    taTotal += tai;
  }

  cout << ttTotal - taTotal + 1 << endl;
  ;
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