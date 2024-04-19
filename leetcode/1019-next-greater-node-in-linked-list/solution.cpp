#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
  int DEFAULT_SMALLER = 0;

public:
  vector<int> nextLargerNodes(ListNode *head)
  {
    vector<int> res;
    stack<pii> pendingSmallerNodes;

    int i = 0;
    ListNode *currNode = head;

    while (currNode)
    {
      res.push_back(this->DEFAULT_SMALLER);

      while (!pendingSmallerNodes.empty() &&
             pendingSmallerNodes.top().first < currNode->val)
      {
        res[pendingSmallerNodes.top().second] = currNode->val;
        pendingSmallerNodes.pop();
      }

      pendingSmallerNodes.push({currNode->val, i});

      currNode = currNode->next;
      i++;
    }

    return res;
  }
};