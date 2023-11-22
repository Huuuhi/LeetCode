//
// Created by 龚余 on 2023/4/21.
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
    int dfs(TreeNode *root,int prevSum){
        if(!root)
            return 0;
        int sum=prevSum*10+root->val;
        if(!root->left&&!root->right){
            return sum;
        }
        else
            return dfs(root->left,sum)+dfs(root->right,sum);
    };
    int sumNumbers(TreeNode *root) {
        return dfs(root,0);
    }
};

int main() {

}