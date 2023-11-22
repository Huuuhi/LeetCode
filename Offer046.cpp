//
// Created by 龚余 on 2023/4/19.
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        unordered_map<int, int> Depth;
        int max_depth = -1;
        queue<TreeNode *> nodeQueue;
        queue<int> depthQueue;
        nodeQueue.push(root);
        depthQueue.push(0);
        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            int depth = depthQueue.front();
            depthQueue.pop();
            if (node) {
                max_depth = max(depth, max_depth);
                Depth[depth] = node->val;
                nodeQueue.push(node->left);
                nodeQueue.push(node->right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
        }
        for(int i=0;i<=max_depth;++i){
            ans.emplace_back(Depth[i]);
        }
        return ans;
    }
};


};
int main() {

}