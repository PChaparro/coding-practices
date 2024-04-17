#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    int carsCount = position.size();

    pii positionsWithIdx[carsCount];
    for (int i = 0; i < carsCount; i++)
    {
      positionsWithIdx[i] = {position[i], i};
    }

    sort(
        positionsWithIdx,
        positionsWithIdx + carsCount,
        [](const pii &a, const pii &b)
        { return a.first < b.first; });

    stack<float> fleetCausers;

    for (int i = 0; i < carsCount; i++)
    {
      float currReqTime = (target - positionsWithIdx[i].first) /
                          (float)speed[positionsWithIdx[i].second];

      while (!fleetCausers.empty() && fleetCausers.top() <= currReqTime)
      {
        fleetCausers.pop();
      }

      fleetCausers.push(currReqTime);
    }

    return fleetCausers.size();
  };
};