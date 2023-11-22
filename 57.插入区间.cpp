//
// Created by 龚余 on 2023/8/28.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
   {
      int left = newInterval[0], right = newInterval[1];
      int revised = false;
      vector<vector<int>> ans;
      for (auto &interval : intervals)
      {
         if (interval[1] < left)
         {
            ans.push_back(interval);
         } else if (interval[0] > right)
         {
            if (!revised)
            {
               ans.push_back({left, right});
               revised = true;
            }
            ans.push_back(interval);
         } else
         {
            // 有交集
            left = min(interval[0], left);
            right = max(interval[1], right);
         }
      }
      if (!revised)
      {
         ans.push_back({left, right});
      }
      return ans;
   }
};