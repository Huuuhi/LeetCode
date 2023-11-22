//
// Created by 龚余 on 2023/5/22.
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
    bool checkSufficientLeaf(TreeNode *root, int sum, int limit) {
        if (!root) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr)
            return root->val + sum >= limit;
        bool checkLeft = checkSufficientLeaf(root->left, sum + root->val, limit);
        bool checkRight = checkSufficientLeaf(root->right, sum + root->val, limit);
        if (!checkLeft) {
            root->left = nullptr;
        }
        if (!checkRight)
            root->right = nullptr;
        return checkRight || checkLeft;

    }

    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        int check= checkSufficientLeaf(root,0,limit);
        if(!check)
            return nullptr;
        return root;
    }
};

int main() {

}