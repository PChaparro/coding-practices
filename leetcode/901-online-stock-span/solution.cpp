#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class StockSpanner
{
private:
  stack<pii> decrementingStocksStreaks;

public:
  StockSpanner()
  {
  }

  int next(int price)
  {
    int lessOrEqualStreak = 1;

    while (!this->decrementingStocksStreaks.empty() &&
           this->decrementingStocksStreaks.top().first <= price)
    {
      pii prevStreak = decrementingStocksStreaks.top();
      lessOrEqualStreak += prevStreak.second;
      decrementingStocksStreaks.pop();
    }

    decrementingStocksStreaks.push({price, lessOrEqualStreak});
    return lessOrEqualStreak;
  }
};
