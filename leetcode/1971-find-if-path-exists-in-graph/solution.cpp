#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
  {
    unordered_map<int, vector<int>> conns;
    for (int i = 0; i < edges.size(); i++)
    {
      conns[edges[i][0]].push_back(edges[i][1]);
      conns[edges[i][1]].push_back(edges[i][0]);
    }

    auto dfs = [&](auto &dfs, int curr) -> bool
    {
      if (curr == destination)
        return true;

      if (conns.find(curr) == conns.end())
        return false;

      vector<int> neighbors = conns[curr];
      conns.erase(curr);

      for (int neighbor : neighbors)
        if (dfs(dfs, neighbor))
          return true;

      return false;
    };

    return dfs(dfs, source);
  }
};