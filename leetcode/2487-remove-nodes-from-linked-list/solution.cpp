#include <bits/stdc++.h>
using namespace std;

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
public:
  ListNode *removeNodes(ListNode *head)
  {
    ListNode *newHead = head,
             *currNode = head;

    stack<ListNode *> pendingDecNodes;

    while (currNode)
    {
      while (!pendingDecNodes.empty() && pendingDecNodes.top()->val < currNode->val)
      {
        if (pendingDecNodes.top() == newHead)
          newHead = currNode;

        pendingDecNodes.pop();
      }

      if (!pendingDecNodes.empty())
        pendingDecNodes.top()->next = currNode;

      pendingDecNodes.push(currNode);
      currNode = currNode->next;
    }

    return newHead;
  }
};