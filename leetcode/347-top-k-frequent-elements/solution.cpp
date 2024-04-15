#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    // Count the reps of each number
    unordered_map<int, int> nums_count;
    for (auto num : nums)
      nums_count[num]++;

    // Create a vector of pairs from the values of the umap
    vector<pair<int, int>> nums_count_pairs(nums_count.begin(), nums_count.end());

    // Sort the vector
    sort(nums_count_pairs.begin(), nums_count_pairs.end(),
         [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    // Get an return the top K frequent
    vector<int> res;
    while (k--)
    {
      res.push_back(nums_count_pairs.back().first);
      nums_count_pairs.pop_back();
    }

    return res;
  }
};