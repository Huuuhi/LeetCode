//
// Created by 龚余 on 2023/6/2.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
   {
      int n = words.size();
      vector<int> prefixSum(n + 1);
      prefixSum[0] = 0;
      for (int i = 0; i < n; ++i)
      {
         prefixSum[i + 1] = prefixSum[i] + (check(words[i]) ? 1 : 0);
      }
      vector<int> ans;
      for (auto &query : queries)
      {
         ans.push_back(prefixSum[query[1] + 1] - prefixSum[query[0]]);
      }
      return ans;
   }
   bool check(string &word)
   {
      int len = word.length();
      return checkVowel(word[0]) && checkVowel(word[len - 1]);
   }
   bool checkVowel(char &character)
   {
      return character == 'a' || character == 'i' || character == 'u' || character == 'o' || character == 'e';
   }
};

int main()
{

}