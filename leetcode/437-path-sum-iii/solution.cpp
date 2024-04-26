#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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
  int pathSum(TreeNode *root, int targetSum)
  {
    if (!root)
      return 0;

    int validPaths = 0;

    auto dfs = [&](auto dfs, TreeNode *node, vector<int> path, ll accSum) -> void
    {
      ll currSum = accSum + node->val;

      // Try with all the acc path
      if (currSum == targetSum)
        validPaths++;

      // Try removing ancestors
      for (int i = 0; i < path.size(); i++)
      {
        currSum -= path[i];

        if (currSum == targetSum)
          validPaths++;
      }

      vector<int> updatedPath(path);
      updatedPath.push_back(node->val);

      if (node->left)
        dfs(dfs, node->left, updatedPath, accSum + node->val);

      if (node->right)
        dfs(dfs, node->right, updatedPath, accSum + node->val);
    };

    dfs(dfs, root, {}, 0);
    return validPaths;
  }
};