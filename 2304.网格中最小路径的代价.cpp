//
// Created by 龚余 on 2023/11/22.
//
#include<bits/stdc++.h>

/*
 * dfs(i,j)=min(dfs(i+1,k)+moveCost[grid[i][j]][k])+grid[i][j]
 * */
class Solution
{
  public:
   int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
   {
      int m = grid.size(), n = grid[0].size();
      vector<vector<int>> dp(m, vector<int>(n, INT_MAX / 2));
      for (int j = 0; j < n; ++j)
      {
         dp[m - 1][j] = grid[m - 1][j];
      }
      for (int i = m - 2; i >= 0; --i)
      {
         for (int j = 0; j < n; ++j)
         {
            for (int k = 0; k < n; ++k)
            {
               dp[i][j] = min(dp[i][j], dp[i + 1][k] + moveCost[grid[i][j]][k]);
            }
            dp[i][j] += grid[i][j];
         }
      }
      return *min_element(dp[0].begin(), dp[0].end());
   }
};