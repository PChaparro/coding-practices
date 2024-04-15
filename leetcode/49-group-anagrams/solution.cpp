#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> grouped_anagrams;

    for (auto curr_str : strs)
    {
      string sorted_str = curr_str;
      sort(sorted_str.begin(), sorted_str.end());
      grouped_anagrams[sorted_str].push_back(curr_str);
    }

    vector<vector<string>> res;
    for (auto grouped_anagrams_it : grouped_anagrams)
    {
      res.push_back(grouped_anagrams_it.second);
    }

    return res;
  }
};