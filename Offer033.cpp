//
// Created by 龚余 on 2023/3/16.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   vector<vector<string>> groupAnagrams(vector<string> &strs)
   {
      unordered_map<string, vector<string>> mp;
      for (auto &str : strs)
      {
         string str_t = str;
         sort(str_t.begin(), str_t.end());
         mp[str_t].emplace_back(str);
      }
      vector<vector<string>> ans;
      for (auto &[key, value] : mp)
      {
         ans.emplace_back(value);
      }
      return ans;
   }
};

int main()
{

}