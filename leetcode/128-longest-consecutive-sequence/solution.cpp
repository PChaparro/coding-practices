#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    unordered_map<int, int> largest_seq_including_num;
    int max_seq_len = 0;

    for (auto num : nums)
    {
      int largest_seq_including_prev_num = largest_seq_including_num[num - 1];
      int curr_seq_len = largest_seq_including_prev_num + 1;

      /* As we sorted the array at the beginning, we can be sure that the current number
      is the last number in the sequence and the only one that needs to be updated.*/
      largest_seq_including_num[num] = curr_seq_len;
      max_seq_len = max(max_seq_len, curr_seq_len);
    }

    return max_seq_len;
  }
};