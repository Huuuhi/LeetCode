//
// Created by 龚余 on 2023/9/21.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges)
   {
      int n = coins.size();
      vector<vector<int>> g(n);
      vector<int> deg(n, 0);
      for (auto &edge : edges)
      {
         int x = edge[0], y = edge[1];
         g[x].push_back(y);
         g[y].push_back(x);
         deg[x]++;
         deg[y]++;
      }
      int left_edges = n - 1;
      // 第一次拓扑，清除度为1且没有金币度点
      vector<int> q;
      for (int i = 0; i < n; ++i)
      {
         if (deg[i] == 1 && coins[i] == 0)
            q.push_back(i);
      }
      while (!q.empty())
      {
         int x = q.back();
         --left_edges;
         q.pop_back();
         for (auto y : g[x])
         {
            if (--deg[y] == 1 && coins[y] == 0)
               q.push_back(y);
         }
      }
      // 第二次拓扑，清除带coin的结点以及父亲结点
      for (int i = 0; i < n; ++i)
      {
         if (deg[i] == 1 && coins[i] == 1)
            q.push_back(i);
      }
      left_edges -= q.size();
      while (!q.empty())
      {
         int x = q.back();
         q.pop_back();
         for (auto y : g[x])
         {
            if (--deg[y] == 1)
               --left_edges;
         }
      }
      return max(left_edges * 2, 0);
   }
};