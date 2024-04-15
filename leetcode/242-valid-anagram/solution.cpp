#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.length() != t.length())
      return false;

    // NOTE: We can earn some space by using a single map and decrementing the count
    // of the characters in the second string. If the final count of all characters is
    // zero, then the strings are anagrams.
    unordered_map<char, int> s_chars_count, t_chars_count;

    for (int i = 0; i < s.length(); i++)
    {
      s_chars_count[s[i]]++;
      t_chars_count[t[i]]++;
    }

    unordered_map<char, int>::iterator scs_it;
    for (scs_it = s_chars_count.begin(); scs_it != s_chars_count.end(); scs_it++)
    {
      char current_char = scs_it->first;
      int current_char_count = scs_it->second;

      if (t_chars_count[current_char] != current_char_count)
        return false;
    }

    return true;
  }
};