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
  void calcAllPathsSum(TreeNode *root, int currPathNum, int currDepth, int &allPathsSum)

  {
    if (!root)
      return;

    currPathNum = currPathNum * 10 + root->val;

    if (!root->left && !root->right)
    {
      allPathsSum += currPathNum;
      return;
    }

    calcAllPathsSum(root->left, currPathNum, currDepth + 1, allPathsSum);
    calcAllPathsSum(root->right, currPathNum, currDepth + 1, allPathsSum);
  }

  int sumNumbers(TreeNode *root)
  {
    int ans = 0;
    calcAllPathsSum(root, 0, 0, ans);
    return ans;
  }
};