//
// Created by 龚余 on 2023/5/9.
//
#include "bits/stdc++.h"

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
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummynode = new TreeNode();
        TreeNode *res = dummynode;
        function<void(TreeNode *)> inorder = [&](TreeNode *node) {
            if (!node) {
                return;
            }
            inorder(node->left);
            res->right = node;
            node->left = nullptr;
            res = node;
            inorder(node->right);
        };
        inorder(root);
        return dummynode->right;
    }
};

int main() {

}