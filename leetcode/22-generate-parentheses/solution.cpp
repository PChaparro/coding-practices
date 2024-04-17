#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void walk(string state, int pendingToClose, int pendingToOpen, vector<string> *res)
  {
    if (pendingToOpen == 0)
    {
      while (pendingToClose--)
      {
        state.push_back(')');
      }

      res->push_back(state);
      return;
    }

    string leftPathState = state;
    leftPathState += '(';
    walk(leftPathState, pendingToClose + 1, pendingToOpen - 1, res);

    if (pendingToClose > 0)
    {
      string rightPathState = state;
      rightPathState += ')';
      walk(rightPathState, pendingToClose - 1, pendingToOpen, res);
    }
  }

  vector<string> generateParenthesis(int n)
  {
    vector<string> res;
    walk("(", 1, n - 1, &res);
    return res;
  }
};