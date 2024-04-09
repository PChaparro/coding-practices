#include <bits/stdc++.h>
using namespace std;

// Utils
// #define ll long long
// #define lld long double
#define umap unordered_map
// #define uset unordered_set
// typedef pair<int,int> pii;

// Whether the input has multiple test cases
bool multi = true;

void solve()
{
  int n, c, d, ni;
  cin >> n >> c >> d;

  // Receive the numbers
  int min = INT_MAX;
  umap<int, int> received_numbers_count;

  int matrix_size = pow(n, 2);
  for (int i = 0; i < matrix_size; i++)
  {
    cin >> ni;

    if (ni < min)
      min = ni;

    received_numbers_count[ni]++;
  }

  // Check every required number is in the matrix
  bool is_progressive_square = true;

  for (int i = 0; i < n; i++)
  {
    int first_row_item = min + (c * i);

    for (int j = 0; j < n; j++)
    {
      int current_column_item = first_row_item + (d * j);

      bool not_enough_reps_of_current_number = received_numbers_count[current_column_item] <= 0;
      if (not_enough_reps_of_current_number)
      {
        is_progressive_square = false;
        goto response;
      }

      received_numbers_count[current_column_item]--;
    }
  }

response:
  if (is_progressive_square)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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