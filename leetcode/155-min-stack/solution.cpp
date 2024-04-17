#include <bits/stdc++.h>
using namespace std;

class MinStackNode
{
private:
  int minBefSelf;
  int val;
  MinStackNode *prev;

public:
  MinStackNode(int minBefSelf, int val, MinStackNode *prev)
  {
    this->minBefSelf = minBefSelf;
    this->val = val;
    this->prev = prev;
  }

  MinStackNode *getPrev()
  {
    return this->prev;
  }

  int getVal()
  {
    return this->val;
  }

  int getMinBeforeSelf()
  {
    return this->minBefSelf;
  }
};

class MinStack
{
private:
  int currMin;
  MinStackNode *currTop;

public:
  MinStack()
  {
    this->currMin = INT_MAX;
    this->currTop = nullptr;
  }

  void push(int val)
  {
    MinStackNode *newNode = new MinStackNode(this->currMin, val, this->currTop);
    this->currTop = newNode;

    if (val < currMin)
    {
      this->currMin = val;
    }
  }

  void pop()
  {
    this->currMin = this->currTop->getMinBeforeSelf();
    this->currTop = this->currTop->getPrev();
  }

  int top()
  {
    return this->currTop->getVal();
  }

  int getMin()
  {
    return this->currMin;
  }
};