#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    unordered_map<char, char> closingChars = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}};

    stack<char> pendingToClose;

    for (auto currChar : s)
    {
      bool isOpeningChar = currChar == '(' ||
                           currChar == '[' ||
                           currChar == '{';

      if (isOpeningChar)
      {
        pendingToClose.push(currChar);
        continue;
      }

      if (pendingToClose.empty())
        return false;

      char lastOpeningChar = pendingToClose.top();
      pendingToClose.pop();

      if (closingChars[lastOpeningChar] != currChar)
        return false;
    }

    return pendingToClose.empty();
  }
};
