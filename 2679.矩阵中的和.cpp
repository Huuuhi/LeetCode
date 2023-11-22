//
// Created by 龚余 on 2023/7/4.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int matrixSum(vector<vector<int>> &nums)
   {
      for (auto &row : nums)
      {
         sort(row.begin(), row.end());
      }
      int ans = 0, n = nums.size();
      for (int j = 0; j < n; ++j)
      {
         int mx = 0;
         for (int i = 0; i < n; ++i)
            mx = max(mx, nums[i][j]);
         ans += mx;
      }
      return ans;
   }
};

int main()
{

}