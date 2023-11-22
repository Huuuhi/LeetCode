//
// Created by 龚余 on 2023/4/21.
//
#include"bits/stdc++.h"

using namespace std;


//  Definition for a binary tree node.
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
    TreeNode *pruneTree(TreeNode *root) {
        if(!root)
            return nullptr;
        root->left= pruneTree(root->left);
        root->right= pruneTree(root->right);
        if(!root->left&&!root->right&&!root->val)
            return nullptr;
        return root;
    }
};

int main() {

}