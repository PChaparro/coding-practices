#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    deque<char> validChars;

    for (int i = 0; i < s.size(); i++)
    {
      char c = s[i];
      if (isalnum(c))
        validChars.push_back(tolower(c));
    }

    while (!validChars.empty())
    {
      char front = validChars.front(), back = validChars.back();

      if (front != back)
        return false;

      validChars.pop_front();

      if (!validChars.empty())
        validChars.pop_back();
    }

    return true;
  }
};