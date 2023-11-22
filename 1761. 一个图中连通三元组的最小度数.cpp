//
// Created by 龚余 on 2023/8/31.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int minTrioDegree(int n, vector<vector<int>> &edges)
  {
    // 题目中序号从1开始
    vector<unordered_set<int>> g(n + 1);
    vector<vector<int>> h(n + 1);
    vector<int> degree(n + 1);
    for (auto &edge : edges)
    {
      int a = edge[0], b = edge[1];
      degree[a]++;
      degree[b]++;
      g[a].insert(b);
      g[b].insert(a);
    }
    for (auto &edge : edges)
    {
      int a = edge[0], b = edge[1];
      if (degree[a] < degree[b] || (degree[a] == degree[b] && a < b))
        h[a].push_back(b);
      else
        h[b].push_back(a);
    }
    int res = INT_MAX;
    for (int i = 1; i < n + 1; ++i)
    {
      for (auto j : h[i])
      {
        for (auto k : h[j])
        {
          if (g[i].count(k))
            res = min(res, degree[i] + degree[j] + degree[k] - 6);
        }
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};