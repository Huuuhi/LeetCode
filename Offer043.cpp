//
// Created by 龚余 on 2023/4/6.
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
/*
 * Solution 1:
 *      设置一个候选队列，按顺序放置完全二叉树中子节点优缺的节点，植入节点时取出第一个候选节点，如果缺少左节点加入左节点，缺少有节点则加入右节点同时从队列中删除，同时将新加入的节点加入到候选队列中
 * */
class CBTInserter {
private:
    TreeNode *root;
    queue<TreeNode*> candidate;
public:
    CBTInserter(TreeNode *root) {
        this->root=root;
        /*层次遍历*/
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *p=q.front();
            q.pop();
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            if(!(p->left&&p->right))
                candidate.push(p);
        }
        /*while(!q.empty()){
            TreeNode *p=q.front();
            q.pop();
            candidate.push(p);
        }*/
    }

    int insert(int v) {
        auto *node=new TreeNode(v);
        TreeNode *p=candidate.front();
        int ret = node->val;
        if(!p->left){
            p->left=node;
        }
        else{
            p->right=node;
            candidate.pop();
        }
        candidate.push(node);
        return ret;
    }

    TreeNode *get_root() {
        return root;
    }
};

int main(){

}
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */