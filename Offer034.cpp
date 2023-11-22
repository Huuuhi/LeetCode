//
// Created by 龚余 on 2023/3/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   bool isAlienSorted(vector<string> &words, string order)
   {
      vector<int> idx(26);
      for (int i = 0; i < order.length(); i++)
      {
         idx[order[i] - 'a'] = i;
      }
      int n = words.size();
      for (int i = 1; i < n; i++)
      {
         bool flag = false;
         for (int j = 0; j < words[i].size() && j < words[i - 1].size(); j++)
         {
            int prev = idx[words[i - 1][j] - 'a'];
            int cur = idx[words[i][j] - 'a'];
            if (prev > cur)
            {
               return false;
            } else if (prev < cur)
            {
               flag = true;
               break;
            }
         }
         if (!flag)
         {
            if (words[i - 1].size() > words[i].size())
               return false;
         }
      }
      return true;
   }
};