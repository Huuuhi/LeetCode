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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *successor = nullptr;
        if (p->right) {
            successor = p->right;
            while (successor->left) {
                successor = successor->left;
            }
            return successor;
        }
        TreeNode *node = root;
        while (node) {
            if (node->val > p->val) {
                successor = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return successor;
    }
};

int main() {

}