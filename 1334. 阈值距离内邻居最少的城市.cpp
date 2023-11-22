//
// Created by 龚余 on 2023/11/14.
//
#include <bits/stdc++.h>

class Solution
{
  public:
   int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
   {
      vector<vector<int>> w(n, vector<int>(n, INT_MAX / 2));
      for (auto &edge : edges)
      {
         int f = edge[0], t = edge[1], wt = edge[2];
         w[f][t] = w[t][f] = wt;
      }
      /*
       * dfs[k][i][j]=min(dfs[k-1][i][j],dfs[k-1][i][k]+dfs[k-1][k][j])
       * */
      auto f = std::move(w);
      for (int k = 0; k < n; k++)
      {
         for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < n; j++)
            {
               f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
         }
      }
      int ans = 0, minCnt = n;
      for (int i = 0; i < n; ++i)
      {
         int cnt=0;
         for (int j = 0; j < n; ++j)
         {
            if (i != j && f[i][j] <= distanceThreshold)
            {
               ++cnt;
            }
         }
         if (minCnt >= cnt)
         {
            minCnt = cnt;
            ans = i;
         }
      }
      return ans;
   }
};