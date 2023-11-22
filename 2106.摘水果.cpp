//
// Created by 龚余 on 2023/5/4.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
   {
      /*
       * step= right-left+ [1.startPos-right, 2.left-startPos, 3.startPos-left, 4.right-startPos]
       * so, step=right-left+min{|startPos-left|,|startPos-right|}
       * */
      int sum = 0, ans = 0;
      auto step = [&](int left, int right) {
         return fruits[right][0] - fruits[left][0]
             + min(abs(startPos - fruits[left][0]), abs(startPos - fruits[right][0]));
      };
      int left = 0, right = 0, n = fruits.size();
      while (right < n)
      {
         sum += fruits[right][1];
         while (left <= right && step(left, right) > k)
         {
            sum -= fruits[left][1];
            left++;
         }
         ans = max(ans, sum);
         right++;
      }
      return ans;
   }
};