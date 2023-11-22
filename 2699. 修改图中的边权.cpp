//
// Created by 龚余 on 2023/6/9.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
   {
      vector<pair<int, int>> g[n];
      for (int i = 0; i < edges.size(); ++i)
      {
         int n = edges[i][0], m = edges[i][1];
         g[n].emplace_back(m, i);
         g[m].emplace_back(n, i);
      }
      int dis[n][2], vis[n], delta;
      memset(dis, 0x3f, sizeof(dis));
      dis[source][0] = dis[source][1] = 0;
      auto dijkstra = [&](int k) {
         memset(vis, 0, sizeof(vis));
         for (;;)
         {
            int x = -1;
            for (int i = 0; i < n; ++i)
               if (!vis[i] && (x < 0 || dis[i][k] < dis[x][k]))
                  x = i;
            if (x == destination)
               return;
            vis[x] = true;
            for (auto [y, eid] : g[x])
            {
               int wt = edges[eid][2];
               if (wt == -1)
                  wt = 1;
               if (k == 1 && edges[eid][2] == -1)
               {
                  int w = delta + dis[y][0] - dis[x][1]; // delta=target-d_(destination,0)
                  if (w > wt)
                     edges[eid][2] = wt = w;
               }
               dis[y][k] = min(dis[y][k], dis[x][k] + wt);
            }
         }
      };
      dijkstra(0);
      delta = target - dis[destination][0];
      if (delta < 0)
         return {};
      dijkstra(1);
      if (dis[destination][1] < target) // 最短路无法再变大，无法达到 target
         return {};
      for (auto &e : edges)
         if (e[2] == -1) // 剩余没修改的边全部改成 1
            e[2] = 1;
      return edges;
   }
};
int main()
{

}