#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int tc = temperatures.size();
    stack<int> pendingIndices;
    vector<int> res(tc, 0);

    for (int i = 0; i < tc; i++)
    {
      int currTemp = temperatures[i];

      while (!pendingIndices.empty() &&
             currTemp > temperatures[pendingIndices.top()])
      {
        res[pendingIndices.top()] = i - pendingIndices.top();
        pendingIndices.pop();
      }

      pendingIndices.push(i);
    }

    return res;
  }
};