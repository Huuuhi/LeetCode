//
// Created by 龚余 on 2023/5/30.
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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        unordered_set to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode *> forests;
        function<TreeNode *(TreeNode *, bool)> dfs = [&](TreeNode *root, bool is_root) -> TreeNode * {
            if (!root)
                return nullptr;
            bool delete_flag = !(to_delete_set.find(root->val) == to_delete_set.end());
            root->left = dfs(root->left, delete_flag);
            root->right = dfs(root->right, delete_flag);
            if (delete_flag) {
                return nullptr;
            } else {
                if (is_root)
                    forests.push_back(root);
                return root;
            }
        };
        dfs(root, true);
        return forests;
    }
};