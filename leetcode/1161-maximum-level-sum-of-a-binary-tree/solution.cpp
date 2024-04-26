#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pil pair<int, ll>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    queue<TreeNode *> nodesPerLvl;
    nodesPerLvl.push(root);

    pil lvlWithMaxSum = {1, LONG_LONG_MIN};
    int currLvl = 1;

    while (!nodesPerLvl.empty())
    {
      int nodesInCurrLvl = nodesPerLvl.size();
      ll currLvlSum = 0;

      while (nodesInCurrLvl--)
      {
        TreeNode *curr = nodesPerLvl.front();
        currLvlSum += curr->val;

        if (curr->left)
          nodesPerLvl.push(curr->left);

        if (curr->right)
          nodesPerLvl.push(curr->right);

        nodesPerLvl.pop();
      }

      if (currLvlSum > lvlWithMaxSum.second)
        lvlWithMaxSum = {currLvl, currLvlSum};

      currLvl++;
    }

    return lvlWithMaxSum.first;
  }
};