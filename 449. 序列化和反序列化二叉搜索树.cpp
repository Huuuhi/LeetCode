//
// Created by 龚余 on 2023/9/4.
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

class Codec {
 private:
  vector<int> split(const string& str, char delimiter) {
    vector<int> tokens;
    string token;
    for (char c : str) {
      if (c == delimiter) {
        tokens.push_back(stoi(token));
        token.clear();
      } else {
        token += c;
      }
    }
    return tokens;
  }
  TreeNode* insert(TreeNode *root,int val){
    if(!root) return new TreeNode(val);
    else if(root->val<val) root->right = insert(root->right,val);
    else root->left = insert(root->left,val);
    return root;
  }
 public:

  // Encodes a tree to a single string.
  // 先序遍历顺序：根->左->右
  string serialize(TreeNode* root) {
    function<void(TreeNode*,string&)> preOrder=[&](TreeNode *root,string &str){
      if(!root){
        str+="";
        return;
      }
      str+= to_string(root->val)+' ';
      preOrder(root->left,str);
      preOrder(root->right,str);
    };
    string res;
    preOrder(root,res);
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if(data.empty())
      return nullptr;
    auto nums= split(data,' ');
    int n=nums.size();
    TreeNode *root=new TreeNode(nums[0]);
    for(int i=1;i<n;++i){
      root=insert(root,nums[i]);
    }
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
int main(){
  TreeNode *root=new TreeNode(2);
  root->left=new TreeNode(1);
  root->right=new TreeNode(3);
//  root->left->left=new TreeNode(1);
  Codec c;
  cout<<c.serialize(root);
}