#include <bits/stdc++.h>
using namespace std;

#define umap unordered_map
#define uset unordered_set

class Solution
{
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
  {
    vector<int> minHeightRoots;

    // Special cases
    if (n <= 2)
    {
      for (int i = 0; i < n; i++)
        minHeightRoots.push_back(i);

      return minHeightRoots;
    }

    umap<int, int> neighborsCount;
    umap<int, vector<int>> neighbors;

    for (auto edge : edges)
    {
      int a = edge[0],
          b = edge[1];

      neighbors[a].push_back(b);
      neighbors[b].push_back(a);
    }

    // Get the leafs
    int nodesCount = n;
    queue<int> leafs;

    uset<int> seen;

    for (auto it = neighbors.begin(); it != neighbors.end(); it++)
    {
      neighborsCount[it->first] = it->second.size();

      if (neighborsCount[it->first] == 1)
      {
        leafs.push(it->first);
        seen.insert(it->first);
      }
    }

    // BFS
    while (nodesCount > 2)
    {
      int currLeafsCount = leafs.size();

      while (currLeafsCount--)
      {
        int currLeaf = leafs.front();
        leafs.pop();

        // Update neighbors of the leaf to identify new leafs
        for (auto neighbor : neighbors[currLeaf])
        {
          neighborsCount[neighbor]--;

          if (neighborsCount[neighbor] <= 1 &&
              seen.find(neighbor) == seen.end())
          {
            leafs.push(neighbor);
            seen.insert(neighbor);
          }
        }

        // Remove the curr leaf
        neighborsCount.erase(currLeaf);
        neighbors.erase(currLeaf);
        nodesCount--;
      }
    }

    // Set response
    for (auto it = neighbors.begin(); it != neighbors.end(); it++)
      minHeightRoots.push_back(it->first);

    return minHeightRoots;
  }
};