#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
// #define umap unordered_map
// #define uset unordered_set
// typedef pair<int,int> pii;

// Whether the input has multiple test cases
bool multi = true;

void solve()
{
  int ns[3], ans;
  cin >> ns[0] >> ns[1] >> ns[2];

  if (ns[0] == ns[1])
    ans = ns[2];
  else if (ns[0] == ns[2])
    ans = ns[1];
  else
    ans = ns[0];

  cout << ans << endl;
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