//
// Created by 龚余 on 2023/8/23.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
  {
    vector<int> deg(n + 1, 0);
    int nEdges = edges.size();
    unordered_map<int, int> overlap;
    auto encoder = [n](int a, int b) -> int {return max(a, b) * (n + 1) + min(a, b);};
    vector<vector<int>> distinctEdges;
    for (int i = 0; i < nEdges; i++) {
      int p = edges[i][0], q = edges[i][1];
      deg[p]++;
      deg[q]++;
      int idx = encoder(p, q);
      if (overlap.find(idx) == overlap.end()) {
        distinctEdges.push_back({p, q});
      }
      overlap[idx]++;
    }

    vector<int> sortedDeg(deg.begin() + 1, deg.end());
    sort(sortedDeg.begin(), sortedDeg.end());
    int nQueries = queries.size();
    vector<int> ret(nQueries);
    for (int i = 0; i < queries.size(); ++i)
    {
      int l = 0, r = n - 1;
      int cnt = 0;
      while (l < n)
      {
        while (r > l && sortedDeg[l] + sortedDeg[r] > queries[i])
        {
          r--;
        }
        cnt += (n - max(l, r) - 1);
        l++;
      }
      for (auto &edge : distinctEdges)
      {
        int a = edge[0], b = edge[1];
        int idx = encoder(a, b);
        if (deg[a] + deg[b] > queries[i] && deg[a] + deg[b] - overlap[idx] <= queries[i])
          cnt--;
      }
      ret[i] = cnt;
    }
    return ret;
  }
};

int main()
{
  int n = 4;
  vector<vector<int>> edges{{1, 2}, {2, 4}, {1, 3}, {2, 3}, {2, 1}};
  vector<int> queries{2, 3};
  Solution so;
  auto ans = so.countPairs(n, edges, queries);
  for(auto i:ans)
    cout<<i<<"; ";
}