#include <bits/stdc++.h>
using namespace std;

int MAX_SINGLE_DIGIT_NUMBER = 9;

class Solution
{
private:
  string INITIAL_COMB = "0000";
  unordered_set<string> seen;

public:
  int openLock(vector<string> &deadends, string target)
  {
    for (string deadEnd : deadends)
    {
      seen.insert(deadEnd);
    }

    if (seen.find(INITIAL_COMB) != seen.end())
      return -1;

    unordered_map<char, char> wrappedDown, wrappedUp;

    for (int i = 0; i <= MAX_SINGLE_DIGIT_NUMBER; i++)
    {
      int nextIdx = (i + 1) % (MAX_SINGLE_DIGIT_NUMBER + 1),
          prevIdx = i == 0 ? MAX_SINGLE_DIGIT_NUMBER : i - 1;

      wrappedUp['0' + i] = '0' + nextIdx;
      wrappedDown['0' + i] = '0' + prevIdx;
    }

    int currLvl = 0;

    queue<string> pendingCombs;
    pendingCombs.push(INITIAL_COMB);
    seen.insert(INITIAL_COMB);

    while (!pendingCombs.empty())
    {
      int combsInCurrLvl = pendingCombs.size();

      while (combsInCurrLvl--)
      {
        string currComb = pendingCombs.front();
        pendingCombs.pop();

        if (currComb == target)
          return currLvl;

        for (int wheelToUpdate = 0; wheelToUpdate < currComb.size(); wheelToUpdate++)
        {
          string d = currComb, u = currComb;

          d[wheelToUpdate] = wrappedDown[currComb[wheelToUpdate]];
          if (seen.find(d) == seen.end())
          {
            pendingCombs.push(d);
            seen.insert(d);
          }

          u[wheelToUpdate] = wrappedUp[currComb[wheelToUpdate]];
          if (seen.find(u) == seen.end())
          {
            pendingCombs.push(u);
            seen.insert(u);
          }
        }
      }

      currLvl++;
    }

    return -1;
  }
};
