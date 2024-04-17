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
  // Recursive function to generate all possible strings from leafs to root
  void getStrs(TreeNode *node, string currStr, vector<string> *strs)
  {
    bool isLeaf = !node->left && !node->right;
    if (isLeaf)
    {
      strs->push_back(currStr);
      return;
    }

    if (node->left)
    {
      string leftLeafStr = char('a' + node->left->val) + currStr;
      getStrs(node->left, leftLeafStr, strs);
    }

    if (node->right)
    {
      string rightLeafStr = char('a' + node->right->val) + currStr;
      getStrs(node->right, rightLeafStr, strs);
    }
  }

  string smallestFromLeaf(TreeNode *root)
  {
    string initialState = "",
           smallest = "";

    // Generate all possible strings from leafs to root
    initialState.push_back(char('a' + root->val));

    vector<string> strs;
    getStrs(root, initialState, &strs);

    // Get the smallest string
    for (int i = 0; i < strs.size(); i++)
    {
      if (smallest.empty() ||
          strs[i] < smallest)
        smallest = strs[i];
    }

    return smallest;
  }
};
