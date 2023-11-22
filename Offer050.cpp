//
// Created by 龚余 on 2023/5/5.
//
#include "bits/stdc++.h"

using namespace std;


//* Definition for a binary tree node.
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
    int pathSum(TreeNode *root, int targetSum) {
        /*一个前缀差问题，数据结构由数组变成了二叉树需要进行一定变化*/
        if (!root)
            return 0;
        unordered_map<long long, int> hash;
        int cnt = 0;
        hash[0] = 1;
        function<void(TreeNode *, long long)> dfs = [&](TreeNode *cur, long long preSum) {
            if (!cur)
                return;
            preSum += cur->val;
            if (hash.find(preSum - targetSum) != hash.end()) {
                cnt += hash[preSum - targetSum];
            }
            hash[preSum]++;
            dfs(cur->left, preSum);
            dfs(cur->right, preSum);
            hash[preSum]--;
        };
        dfs(root, 0);
        return cnt;
    }
};