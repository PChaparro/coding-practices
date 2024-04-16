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
  void addNodesToTree(TreeNode *currentNode, int currentDepth, int &val, int &targetDepth)
  {
    bool haveReachedTargetDepth = currentDepth == targetDepth - 1;
    if (haveReachedTargetDepth)
    {
      TreeNode *newLeftNode = new TreeNode(val, currentNode->left, nullptr);
      TreeNode *newRightNode = new TreeNode(val, nullptr, currentNode->right);

      currentNode->left = newLeftNode;
      currentNode->right = newRightNode;

      return;
    }

    if (currentNode->left)
      addNodesToTree(currentNode->left, currentDepth + 1, val, targetDepth);

    if (currentNode->right)
      addNodesToTree(currentNode->right, currentDepth + 1, val, targetDepth);
  }

  TreeNode *addOneRow(TreeNode *root, int val, int depth)
  {
    // Corner case: if depth is 1, we need to create a new root
    if (depth == 1)
    {
      TreeNode *newRoot = new TreeNode(val, root, nullptr);
      return newRoot;
    }

    addNodesToTree(root, 1, val, depth);
    return root;
  }
};
