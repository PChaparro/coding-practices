#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minReorder(int n, vector<vector<int>> &connections)
  {
    unordered_map<int, vector<int>> outgoing, incoming;

    for (auto connection : connections)
    {
      int a = connection[0],
          b = connection[1];

      outgoing[a].push_back(b);
      incoming[b].push_back(a);
    }

    int rtr = 0;

    vector<bool> seen(n, false);
    seen[0] = true;

    auto ensureIncoming = [&](auto f, int currCity) -> void
    {
      // Change the outgoing roads to incoming
      for (int outgoingNeighbor : outgoing[currCity])
      {
        if (!seen[outgoingNeighbor])
        {
          seen[outgoingNeighbor] = true;
          f(f, outgoingNeighbor);
          rtr++;
        }
      }

      // Ensure all roads connected to an incoming city are also incoming
      for (int incomingNeighbor : incoming[currCity])
      {
        if (!seen[incomingNeighbor])
        {
          seen[incomingNeighbor] = true;
          f(f, incomingNeighbor);
        }
      }
    };

    ensureIncoming(ensureIncoming, 0);
    return rtr;
  }
};