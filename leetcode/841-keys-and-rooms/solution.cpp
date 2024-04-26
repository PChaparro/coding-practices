#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    int lockedRooms = rooms.size() - 1;

    vector<bool> seen(rooms.size(), false);
    seen[0] = true;

    queue<int> pendingRooms;

    for (int key : rooms[0])
    {
      pendingRooms.push(key);
      seen[key] = true;
    }

    while (!pendingRooms.empty())
    {
      int key = pendingRooms.front();
      lockedRooms--;

      for (int unlockedKey : rooms[key])
      {
        if (!seen[unlockedKey])
        {
          seen[unlockedKey] = true;
          pendingRooms.push(unlockedKey);
        }
      }

      pendingRooms.pop();
    }

    return lockedRooms == 0;
  }
};