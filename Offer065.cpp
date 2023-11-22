//
// Created by 龚余 on 2023/7/11.
//
#include "bits/stdc++.h"
using namespace std;

/*字典树*/
struct Trie
{
  int count;
  vector<Trie *> children;
  Trie() : count(0), children(26)
  {};
};
class Solution
{
 private:
  Trie *root=new Trie();
 public:
  int minimumLengthEncoding(vector<string> &words)
  {
    unordered_map<Trie *, int> nodes;
    for (int i = 0; i < words.size(); ++i)
    {
      string word = words[i];
      Trie *cur = root;
      for (int j = word.length() - 1; j >= 0; j--)
      {
        int idx = word[j] - 'a';
        if (cur->children[idx] == nullptr)
        {
          cur->children[idx] = new Trie();
          cur->count++;
        }
        cur = cur->children[idx];
      }
      nodes[cur] = i;
    }
    int ans = 0;
    for (auto &[node, idx] : nodes)
    {
      if (node->count == 0)
      {
        ans += words[idx].length() + 1;
      }
    }
    return ans;
  }
};
int main()
{

}