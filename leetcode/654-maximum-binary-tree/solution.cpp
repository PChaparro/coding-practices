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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums)
  {
    stack<TreeNode *> pendingNodes;

    for (int num : nums)
    {
      TreeNode *curr = new TreeNode(num);

      while (!pendingNodes.empty() && pendingNodes.top()->val < curr->val)
      {
        pendingNodes.top()->right = curr->right;
        curr->right = pendingNodes.top();
        pendingNodes.pop();
      }

      curr->left = curr->right;
      curr->right = nullptr;

      pendingNodes.push(curr);
    }

    TreeNode *root = nullptr;

    while (!pendingNodes.empty())
    {
      if (!root)
      {
        root = pendingNodes.top();
      }
      else
      {
        pendingNodes.top()->right = root;
        root = pendingNodes.top();
      }

      pendingNodes.pop();
    }

    return root;
  }
};
