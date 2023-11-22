//
// Created by 龚余 on 2023/11/8.
//
#include"bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int findTheLongestBalancedSubstring(string s)
   {
      int ans = 0, pre = 0, cur = 0, n = s.size();
      for (int i = 0; i < n; ++i)
      {
         cur++;
         if (i == n - 1 || s[i] != s[i + 1])
         {
            if (s[i] == '1')
            {
               ans = max(ans, min(pre, cur) * 2);
            }
            pre = cur;
            cur = 0;
         }
      }
      return ans;
   }
};