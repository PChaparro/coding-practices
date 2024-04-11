#include <bits/stdc++.h>
using namespace std;

// Utils
#define ll long long
// #define lld long double
// #define umap unordered_map
// #define uset unordered_set
// typedef pair<int,int> pii;

// Whether the input has multiple test cases
bool multi = true;

void solve()
{
  // Receive and sum the squares
  int n, ni;
  cin >> n;

  ll squares_sum = 0;

  while (n--)
  {
    cin >> ni;
    squares_sum += ni;
  }

  // Check if the number has a perfect square
  int sum_sqrt = sqrt(squares_sum);
  pow(sum_sqrt, 2) == squares_sum ? cout << "YES" << endl : cout << "NO" << endl;
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