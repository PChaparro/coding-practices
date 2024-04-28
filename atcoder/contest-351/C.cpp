#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
// #define umap unordered_map
// #define uset unordered_set
// typedef pair<int, int> pii;

// Whether the input has multiple test cases
bool multi = false;

void solve()
{
  int n;
  cin >> n;

  int aa[n];

  for (int i = 0; i < n; i++)
    cin >> aa[i];

  stack<int> seq;
  int ai = 0;

  seq.push(aa[ai]);
  ai++;

  // Operations
  for (int i = 1; i < n; i++)
  {
    int valToPush = aa[ai];

    while (!seq.empty())
    {
      if (seq.top() != valToPush)
        break;

      valToPush++; // 2^n + 2^n = 2^1 * 2^n = 2^(n + 1)
      seq.pop();
    }

    seq.push(valToPush);
    ai++;
  }

  cout << seq.size() << endl;
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