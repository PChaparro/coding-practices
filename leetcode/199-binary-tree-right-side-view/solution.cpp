#include <bits/stdc++.h>
using namespace std;

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
  vector<int> rightSideView(TreeNode *root)
  {
    if (!root)
      return {};

    vector<int> rightMostNodesPerLvl;

    deque<TreeNode *> nodesPerLvl;
    nodesPerLvl.push_back(root);

    while (!nodesPerLvl.empty())
    {
      rightMostNodesPerLvl.push_back(nodesPerLvl.back()->val);

      int currLvlSize = nodesPerLvl.size();

      while (currLvlSize--)
      {
        TreeNode *curr = nodesPerLvl.front();

        if (curr->left)
          nodesPerLvl.push_back(curr->left);

        if (curr->right)
          nodesPerLvl.push_back(curr->right);

        nodesPerLvl.pop_front();
      }
    }

    return rightMostNodesPerLvl;
  }
};