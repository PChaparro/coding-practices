#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;

class TimeMap
{
private:
  unordered_map<string, vector<pis>> storage;
  string NOT_FOUND_VAL = "";

public:
  TimeMap()
  {
  }

  void set(string key, string value, int timestamp)
  {
    this->storage[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp)
  {
    string val = this->NOT_FOUND_VAL;

    int l = 0,
        r = this->storage[key].size() - 1,
        mid;

    pis pairAtMid;

    while (l <= r)
    {
      mid = (l + r) / 2;
      pairAtMid = this->storage[key][mid];

      if (pairAtMid.first > timestamp)
      {
        r = mid - 1;
      }
      else
      {
        val = this->storage[key][mid].second;
        l = mid + 1;
      }
    }

    return val;
  }
};