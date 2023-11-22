//
// Created by 龚余 on 2023/6/30.
//
#include "bits/stdc++.h"
using namespace std;
class Trie
{
 private:
  struct TrieNode
  {
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode() : isEnd(false), children(26, nullptr)
    {}
  };
  TrieNode *root;
 public:
  Trie()
  {
    root = new TrieNode();
  }
  void insert(string word)
  {
    TrieNode *curr = root;
    for (char ch : word)
    {
      if (curr->children[ch - 'a'] == nullptr)
      {
        curr->children[ch - 'a'] = new TrieNode();
      }
      curr = curr->children[ch - 'a'];
    }
    curr->isEnd = true;
  }
  string searchPrefix(string word)
  {
    string ans;
    TrieNode *curr = root;
    for (auto ch : word)
    {
      if (curr->isEnd || curr->children[ch - 'a'] == nullptr) break;

      ans += ch;
      curr = curr->children[ch - 'a'];
    }

    return curr->isEnd ? ans : "";         //有前缀返回前缀，没有则返回空字符串

  }
};
class Solution
{
 public:
  string replaceWords(vector<string> &dictionary, string sentence)
  {
    Trie *trie = new Trie();
    for (string &sti : dictionary)
    {
      trie->insert(sti);
    }
    string ans;
    string tmp;
    for (int i = 0; i < sentence.size(); ++i)
    {
      if(sentence[i]==' '){
        string pre=trie->searchPrefix(tmp);
//        cout<<pre<<" ";
        if(!pre.empty()){
          ans+=pre+" ";
        }
        else{
          ans+=tmp+" ";
        }
        tmp="";
      }
      else{
        tmp+=sentence[i];
      }
    }
    // 遍历最后一个单词
    string pre=trie->searchPrefix(tmp);
    if(!pre.empty()){
      ans+=pre;
    }
    else{
      ans+=tmp;
    }
    return ans;
  }
};

int main(){
  vector<string>dictionary {"cat","bat","rat"};
  string sentence = "the cattle was rattled by the battery";
  Solution so;
  cout<<so.replaceWords(dictionary,sentence);
}
