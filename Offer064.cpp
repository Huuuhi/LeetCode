//
// Created by 龚余 on 2023/7/5.
//

#include "bits/stdc++.h"
using namespace std;
struct Trie
{
  bool isEnd;
  vector<Trie *> children;
  Trie() : isEnd{false}, children(26)
  {}
};
class MagicDictionary
{
 private:
  Trie *root;
 public:
  /** Initialize your data structure here. */
  MagicDictionary()
  {
    root = new Trie();
  }

  void buildDict(vector<string> dictionary)
  {
    for (auto &&word : dictionary)
    {
      Trie *cur = root;
      for (char ch : word)
      {
        int idx = ch - 'a';
        if (cur->children[idx] == nullptr)
        {
          cur->children[idx] = new Trie();
        }
        cur = cur->children[idx];
      }
      cur->isEnd = true;
    }
  }

  bool search(string searchWord)
  {
    function<bool(Trie *, int, bool)> dfs = [&](Trie *node, int pos, bool modified) {
      if (pos == searchWord.size())
      {
        return modified && node->isEnd;
      }
      int idx = searchWord[pos] - 'a';
      if (node->children[idx])
      {
        if (dfs(node->children[idx], pos + 1, modified))
        {
          return true;
        }
      }
      if (!modified)
      {
        for (int i = 0; i < 26; ++i)
        {
          if (i != idx && node->children[i])
          {
            if (dfs(node->children[i], pos + 1, true))
            {
              return true;
            }
          }
        }
      }
      return false;
    };
    return dfs(root, 0, false);
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main()
{

}