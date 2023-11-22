//
// Created by 龚余 on 2023/8/24.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int countServers(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    unordered_map<int, int> row, col;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (grid[i][j] == 1)
        {
          row[i]++;
          col[j]++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1))
          ans++;
      }
    }
    return ans;
  }
};
1 1 0 0
0 0 1 0
0 0 1 0
0 0 0 1