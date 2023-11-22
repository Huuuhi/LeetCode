//
// Created by 龚余 on 2023/8/25.
//
#include "bits/stdc++.h"
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr)
  {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
  {}
};

class Solution
{
 public:
  int goodNodes(TreeNode *root)
  {
    int ans = 0;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *root, int max_x) {
      if (!root)
        return;
      if (root->val >= max_x)
      {
        ans++;
        max_x = root->val;
      }
      dfs(root->left, max_x);
      dfs(root->right, max_x);
    };
    dfs(root, root->val);
    return ans;
  }
};