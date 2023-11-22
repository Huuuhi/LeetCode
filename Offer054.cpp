//
// Created by 龚余 on 2023/5/23.
//
#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        int sum=0;
        inorder(root,sum);
        return root;
    }

    void inorder(TreeNode *root,int &sum){
        if(!root)
            return;
        inorder(root->right,sum);
        sum+=root->val;
        root->val=sum;
        inorder(root->left,sum);
    }
};