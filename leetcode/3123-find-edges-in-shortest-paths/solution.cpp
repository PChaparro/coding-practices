#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define umap unordered_map

typedef pair<int, lli> pil;

class Solution
{
private:
  umap<int, vector<pil>> adj;

public:
  void dijkstra(int from, lli *distances)
  {
    priority_queue<pil, vector<pil>, greater<>> pendingVertex;

    pendingVertex.push({from, 0});
    distances[from] = 0;

    while (!pendingVertex.empty())
    {
      pil currPair = pendingVertex.top();
      pendingVertex.pop();

      int currVertex = currPair.first;
      int currDist = currPair.second;

      if (currDist > distances[currVertex])
        continue;

      for (pil adjacent : this->adj[currVertex])
      {
        int neighborVertex = adjacent.first;
        lli goToNeighborCost = adjacent.second;

        if (currDist + goToNeighborCost < distances[neighborVertex])
        {
          distances[neighborVertex] = currDist + goToNeighborCost;
          pendingVertex.push({neighborVertex, distances[neighborVertex]});
        }
      }
    }
  };

  vector<bool> findAnswer(int n, vector<vector<int>> &edges)
  {
    // Save adjacent elements
    for (auto edge : edges)
    {
      int a = edge[0],
          b = edge[1],
          w = edge[2];

      this->adj[a].push_back({b, w});
      this->adj[b].push_back({a, w});
    }

    // Calculate all distances from 0
    lli distancesFromFirst[n];
    fill(distancesFromFirst, distancesFromFirst + n, INT_MAX);
    dijkstra(0, distancesFromFirst);

    // Calculate all distances from n - 1
    lli distancesFromLast[n];
    fill(distancesFromLast, distancesFromLast + n, INT_MAX);
    dijkstra(n - 1, distancesFromLast);

    // Check if every edge is in a shortest path
    vector<bool> isInShortestPath(edges.size());
    lli minDistanceToLastNode = distancesFromFirst[n - 1];

    for (int i = 0; i < edges.size(); i++)
    {
      auto edge = edges[i];
      int a = edge[0],
          b = edge[1],
          w = edge[2];

      // Calculate from left to right (start -> a -> b -> end)
      lli d1 = distancesFromFirst[a],
          d2 = distancesFromLast[b];

      if ((d1 + w + d2) == minDistanceToLastNode)
      {
        isInShortestPath[i] = true;
        continue;
      }

      // Calculate from right to left (end -> a -> b -> start)
      d1 = distancesFromFirst[b],
      d2 = distancesFromLast[a];

      if ((d1 + w + d2) == minDistanceToLastNode)
        isInShortestPath[i] = true;
    }

    return isInShortestPath;
  }
};
