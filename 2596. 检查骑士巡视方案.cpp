//
// Created by 龚余 on 2023/9/13.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   bool checkValidGrid(vector<vector<int>> &grid)
   {
      if (grid[0][0] != 0)
         return false;
      int n = grid.size();
      vector<pair<int, int>> indices(n * n);
      for (int i = 0; i < n; ++i)
      {
         for (int j = 0; j < n; ++j)
         {
            indices[grid[i][j]] = {i, j};
         }
      }
      for (int i = 0; i < indices.size() - 1; ++i)
      {
         int diffX = abs(indices[i].first - indices[i + 1].first);
         int diffY = abs(indices[i].second - indices[i + 1].second);
         if (diffY * diffX != 2)
            return false;
      }
      return true;
   }
};