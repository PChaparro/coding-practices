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
  ll k, total_durability = 0;
  cin >> n >> k;

  deque<int> ships_durability;

  for (int i = 0; i < n; i++)
  {
    cin >> ni;
    total_durability += ni;
    ships_durability.push_back(ni);
  }

  // Special case
  bool kraken_can_sink_all_ships = k >= total_durability;
  if (kraken_can_sink_all_ships)
  {
    cout << n << endl;
    return;
  }

  while (ships_durability.size() && k)
  {
    ll current_attack_damage = min(
        ships_durability.front(),
        ships_durability.back());

    if ((current_attack_damage * 2) > k)
    {
      ships_durability.front() -= k / 2 + k % 2;
      ships_durability.back() -= k / 2;
      k = 0;
    }
    else
    {
      ships_durability.front() -= current_attack_damage;
      ships_durability.back() -= current_attack_damage;
      k -= current_attack_damage * 2;
    }

    if (ships_durability.front() == 0)
      ships_durability.pop_front();

    if (ships_durability.back() == 0)
      ships_durability.pop_back();
  }

  cout << n - ships_durability.size() << endl;
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