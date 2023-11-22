//
// Created by 龚余 on 2023/7/14.
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

/*
 * coins代表硬币数，nodes代表节点总数，那么经过边的硬币数=coins-nodes
 * coins=cl+cr+node.val; nodes=nl+nr+1
 * 所以可以合并计算coins-nodes=d -> d=dl+dr-1+node.val
 * */
class Solution
{
  int ans=0;
  int dfs(TreeNode *root){
    if(root== nullptr)
      return 0;
    int d= dfs(root->left)+dfs(root->right)-1+root->val;
    ans+=abs(d);
    return d;
  }
 public:
  int distributeCoins(TreeNode *root)
  {
    dfs(root);
    return ans;
  }
};
int main()
{

}