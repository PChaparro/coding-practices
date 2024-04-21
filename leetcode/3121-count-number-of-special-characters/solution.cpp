#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSpecialChars(string word)
  {
    int NUM_OF_LOWERCASE_LETTERS = 'z' - 'a' + 1;

    int lastTimeSeenLower[NUM_OF_LOWERCASE_LETTERS];
    fill(lastTimeSeenLower, lastTimeSeenLower + NUM_OF_LOWERCASE_LETTERS, INT_MIN);

    int firstTimeSeenUpper[NUM_OF_LOWERCASE_LETTERS];
    fill(firstTimeSeenUpper, firstTimeSeenUpper + NUM_OF_LOWERCASE_LETTERS, INT_MAX);

    for (int i = 0; i < word.size(); i++)
    {
      char c = word[i];

      bool isUpper = c >= 'A' && c <= 'Z';
      if (isUpper)
        firstTimeSeenUpper[c - 'A'] = min(firstTimeSeenUpper[c - 'A'], i);
      else
        lastTimeSeenLower[c - 'a'] = max(lastTimeSeenLower[c - 'a'], i);
    }

    int ans = 0;

    for (int i = 0; i < NUM_OF_LOWERCASE_LETTERS; i++)
    {
      if (lastTimeSeenLower[i] != INT_MIN &&
          firstTimeSeenUpper[i] != INT_MAX &&
          firstTimeSeenUpper[i] > lastTimeSeenLower[i])
        ans++;
    }

    return ans;
  }
};