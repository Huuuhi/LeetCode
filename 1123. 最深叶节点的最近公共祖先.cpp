//
// Created by 龚余 on 2023/9/6.
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
  TreeNode *lcaDeepestLeaves(TreeNode *root)
  {
    TreeNode *ans;
    int max_depth = -1;
    function<int(TreeNode *, int)> dfs = [&](TreeNode *root, int depth) -> int {
      if (root == nullptr)
      {
        max_depth = max(max_depth, depth);
        return depth;
      }
      int left_depth = dfs(root->left, depth + 1);
      int right_depth = dfs(root->right, depth + 1);
      if (left_depth == right_depth && left_depth == max_depth)
      {
        ans = root;
      }
      return max(left_depth, right_depth);
    };
    dfs(root, 0);
    return ans;
  }
};

int main()
{

}