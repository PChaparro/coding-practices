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
  int n;
  cin >> n;

  string s, current_syllable, separated;
  cin >> s;

  while (!s.empty())
  {
    // Detect the type of the current syllable
    int expected_syllable_length;

    if (s.back() == 'a' || s.back() == 'e')
    {
      expected_syllable_length = 2;
    }
    else
    {
      expected_syllable_length = 3;
    }

    // Get the current syllable
    while (expected_syllable_length--)
    {
      current_syllable = s.back() + current_syllable;
      s.pop_back();
    }

    // Add the current syllable to the separated message
    separated = current_syllable + "." + separated;
    current_syllable.clear();
  }

  // Remove the last dot
  separated.pop_back();
  cout << separated << endl;
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