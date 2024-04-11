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
  int n, ni;
  cin >> n;

  // Receive the numbers and memoize the sums
  ll ns_sum[n];

  for (int i = 0; i < n; i++)
  {
    cin >> ni;

    if (i % 2 == 0)
      ni *= -1;

    if (i == 0)
      ns_sum[i] = ni;
    else
      ns_sum[i] = ns_sum[i - 1] + ni;
  }

  set<ll> unique_sums;

  // By default, the prefix sum of the array is zero
  unique_sums.insert(0);

  // Check if there are two index where the prefix sum is equal
  for (int i = 0; i < n; i++)
  {
    ll current_sum = ns_sum[i];

    if (unique_sums.find(current_sum) != unique_sums.end())
    {
      cout << "YES" << endl;
      return;
    }

    unique_sums.insert(current_sum);
  }

  cout << "NO" << endl;
}

/**
 * This is an alternative but sub-optimal solution with O(n^2) complexity.
 * Even though the memoization avoids recalculating the sum of each sub-array,
 * this solution doesn't pass the time limit.
 */

/*
void solve()
{

  int n, ni;
  cin >> n;

  // Receive the numbers and memoize the sums
  ll ns_sum[n];
  bool exists = false;

  for (int i = 0; i < n; i++)
  {
    cin >> ni;

    if (i % 2 == 0)
      ni *= -1;

    if (i == 0)
      ns_sum[i] = ni;
    else
      ns_sum[i] = ns_sum[i - 1] + ni;
  }

  // Check if there is a sub-array where the sum is 0
  for (int i = 0; i < n - 1; i++)
  {
    int left_offset = i == 0 ? 0 : ns_sum[i - 1];

    for (int j = i + 1; j < n; j++)
    {
      ll sas = ns_sum[j] - left_offset;
      if (sas == 0)
      {
        exists = true;
        goto response;
      }
    }
  }

response:
  exists ? cout << "YES" << endl : cout << "NO" << endl;
}
*/

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