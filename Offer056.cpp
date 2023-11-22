//
// Created by 龚余 on 2023/5/25.
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
    unordered_set<int> st;
    bool findTarget(TreeNode *root, int k) {
        if(!root)
            return false;
        if(st.find(k-root->val)!=st.end())
            return true;
        st.insert(root->val);
        return findTarget(root->left,k)|| findTarget(root->right,k);
    }
};

int main() {

}