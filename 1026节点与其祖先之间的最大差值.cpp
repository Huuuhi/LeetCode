//
// Created by 龚余 on 2023/4/18.
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
    int maxAncestorDiff(TreeNode *root) {
        function<int(TreeNode *root, int mi, int ma)> func = [&](TreeNode *root, int mi, int ma) {
            if (root== nullptr)
                return 0;
            int diff = max(abs(root->val - mi), abs(root->val - ma));
            mi=min(root->val,mi);
            ma=max(root->val,ma);
            diff=max(func(root->left,mi,ma),diff);
            diff=max(func(root->right,mi,ma),diff);
            return diff;
        };
        int ans=func(root,root->val,root->val);
        return ans;
    }
};

int main() {

}