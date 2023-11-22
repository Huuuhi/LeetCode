//
// Created by 龚余 on 2023/9/18.
//
#include "bits/stdc++.h"
using namespace std;
// Definition for a binary tree node.
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
  private:
   unordered_map<TreeNode *, int> g; //选择抢当前结点
   unordered_map<TreeNode *, int> f; //选择不抢当前结点
  public:
   int rob(TreeNode *root)
   {
      function<void(TreeNode *)> dfs = [&](TreeNode *root) -> void {
         if (!root)
            return;
         dfs(root->left);
         dfs(root->right);
         g[root] = root->val + f[root->left] + f[root->right];
         f[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
      };
      dfs(root);
      return max(f[root], g[root]);
   }
};