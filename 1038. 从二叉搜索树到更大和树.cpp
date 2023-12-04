//
// Created by 龚余 on 2023/12/4.
//

#include <bits/stdc++.h>

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
/*
 * 二叉搜索树满足左<当前<右，所以让当前节点代表所有大于当前节点的值就是求他的右子树+当前值+父节点值，所以树的搜索过程即逆中序：右->根->左
 * */
class Solution
{
  private:
   int s = 0;
  public:
   TreeNode *bstToGst(TreeNode *root)
   {
      function<void(TreeNode *)> dfs = [&](TreeNode *node) {
         if (!node)
            return;
         dfs(node->right);
         s += node->val;
         node->val = s;
         dfs(node->left);
      };
      dfs(root);
      return root;
   }
};