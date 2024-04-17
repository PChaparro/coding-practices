#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> pendingNums;

    for (string token : tokens)
    {
      if (
          token == "+" ||
          token == "-" ||
          token == "*" ||
          token == "/")
      {
        int b = pendingNums.top();
        pendingNums.pop();

        int a = pendingNums.top();
        pendingNums.pop();

        if (token == "+")
          pendingNums.push(a + b);
        else if (token == "-")
          pendingNums.push(a - b);
        else if (token == "*")
          pendingNums.push(a * b);
        else
          pendingNums.push(a / b);

        continue;
      }

      pendingNums.push(stoi(token));
    }

    return pendingNums.top();
  }
};