//
// Created by 龚余 on 2023/7/12.
//
#include "bits/stdc++.h"
using namespace std;
struct Trie
{
  int val;
  vector<Trie *> children;
  Trie() : val(0), children(26, nullptr)
  {};
};

class MapSum
{
 private:
  Trie *root;
  unordered_map<string, int> cnt;
 public:
  /** Initialize your data structure here. */
  MapSum()
  {
    root = new Trie();
  }

  void insert(string key, int val)
  {
    int delta = val;
    if (cnt.count(key))
    {
      delta -= cnt[key];
    }
    cnt[key] = val;
    Trie *cur = root;
    for (char &c : key)
    {
      int idx = c - 'a';
      if (cur->children[idx] == nullptr)
      {
        cur->children[idx] = new Trie();
      }
      cur = cur->children[idx];
      cur->val += delta;
    }
  }

  int sum(string prefix)
  {
    Trie *cur = root;
    for (char &c : prefix)
    {
      int idx = c - 'a';
      if (cur->children[idx] == nullptr)
        return 0;
      else
        cur = cur->children[idx];
    }
    return cur->val;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */