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
  int n, a, b;
  cin >> n >> a >> b;

  bool promotion_is_worth = b <= a * 2;
  int optimal_cost_of_two_yogurts = promotion_is_worth ? b : a * 2;
  int final_cost_of_two_yogurts = n / 2 * optimal_cost_of_two_yogurts;

  int optimal_final_cost = n % 2 == 0 ? final_cost_of_two_yogurts : final_cost_of_two_yogurts + a;
  cout << optimal_final_cost << endl;
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