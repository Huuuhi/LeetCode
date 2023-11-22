//
// Created by 龚余 on 2023/4/10.
//
#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for a binary tree node.
*/
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
    vector<int> largestValues(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode *> q1, q2;
        if(!root)
            return ans;
        q1.push(root);
        int max_t = root->val;
        while (!q1.empty()) {
            TreeNode *cur = q1.front();
            if (cur->left)
                q2.push(cur->left);
            if (cur->right)
                q2.push(cur->right);
            max_t = max(max_t, cur->val);
            q1.pop();
            if (q1.empty()) {
                ans.push_back(max_t);
                max_t = INT_MIN;
                while (!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }
        return ans;
    }
};

int main() {

}