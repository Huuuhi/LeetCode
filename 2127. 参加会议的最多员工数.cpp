//
// Created by 龚余 on 2023/11/1.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int maximumInvitations(vector<int> &favorite)
   {
      int n = favorite.size();
      vector<int> deg(n);
      for (int i = 0; i < n; ++i)
      {
         deg[favorite[i]]++;
      }
      queue<int> q;
      vector<vector<int>> rg(n);
      for (int i = 0; i < n; ++i)
      {
         if (deg[i] == 0)
            q.push(i);
      }
      /*一次拓扑排序*/
      while (!q.empty())
      {
         int x = q.front();
         int y = favorite[x];
         q.pop();
         rg[y].push_back(x);
         if (--deg[y] == 0)
            q.push(y);
      }
      function<int(int)> rdfs = [&](int x) -> int {
         int max_depth = 1;
         for (int son : rg[x])
         {
            max_depth = max(max_depth, rdfs(son) + 1);
         }
         return max_depth;
      };
      /*遍历基环*/
      int max_ring_size = 0, sum_chain_size = 0;
      for (int i = 0; i < n; ++i)
      {
         if (deg[i] == 0)
            continue;
         // 遍历基环上的点
         deg[i] = 0; // 将基环上的点的入度标记为 0，避免重复访问
         int ring_size = 1; // 基环长度
         for (int x = favorite[i]; x != i; x = favorite[x])
         {
            deg[x] = 0; // 将基环上的点的入度标记为 0，避免重复访问
            ring_size++;
         }
         if (ring_size == 2)
         {
            sum_chain_size += rdfs(i) + rdfs(favorite[i]);
         } else
            max_ring_size = max(max_ring_size, ring_size);
      }
      return max(max_ring_size, sum_chain_size);
   }
};