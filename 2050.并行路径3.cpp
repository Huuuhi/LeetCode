//
// Created by 龚余 on 2023/7/28.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
   {
      vector<vector<int>> g(n);
      vector<int> deg(n);
      for (auto &re : relations)
      {
         int x = re[0] - 1, y = re[1] - 1;
         g[x].push_back(y);
         deg[y]++;
      }
      vector<int> f(n);
      queue<int> q;
      for (int i = 0; i < n; ++i)
         if (deg[i] == 0)
            q.push(i);
      while (!q.empty())
      {
         int x = q.front();
         q.pop();
         f[x] += time[x];
         for (auto i : g[x])
         {
            f[i] = max(f[i], f[x]);
            if (--deg[i] == 0)
               q.push(i);
         }
      }
      return *max_element(f.begin(), f.end());
   }
};

int main()
{

}