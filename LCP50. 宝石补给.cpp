//
// Created by 龚余 on 2023/9/15.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   int giveGem(vector<int> &gem, vector<vector<int>> &operations)
   {
      for (auto &ope : operations)
      {
         int x = ope[0], y = ope[1];
         int num = gem[x] / 2;
         gem[x] -= num;
         gem[y] += num;
      }
      int maxD = *max_element(gem.begin(), gem.end()), minD = *min_element(gem.begin(), gem.end());
      return maxD - minD;
   }
};