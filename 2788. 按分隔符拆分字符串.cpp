//
// Created by 龚余 on 2023/7/25.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   vector<string> splitWordsBySeparator(vector<string> &words, char separator)
   {
      vector<string> ans;
      for (auto &word : words)
      {
         string s = "";
         int n = word.size();
         for (int i = 0; i <= n; ++i)
         {
            if (i != n && word[i] != separator)
            {
               s += word[i];
            } else
            {
               if (!s.empty())
                  ans.push_back(s);
               s = "";
            }
         }
      }
      return ans;
   }
};

int main()
{

}