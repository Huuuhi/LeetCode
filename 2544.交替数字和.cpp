//
// Created by 龚余 on 2023/7/12.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int alternateDigitSum(int n)
   {
      stack<int> stk;
      while (n > 0)
      {
         int t = n % 10;
         stk.push(t);
         n /= 10;
      }
      int flag = 1, ans = 0;
      while (!stk.empty())
      {
         ans += flag * stk.top();
         stk.pop();
         flag = -flag;
      }
      return ans;
   }
};

class Solution_best
{
  public:
   int alternateDigitSum(int n)
   {
      int ans = 0, flag = 1;
      while (n > 0)
      {
         int t = n % 10;
         n /= 10;
         ans += t * flag;
         flag = -flag;
      }
      return ans * -flag;
   }
};