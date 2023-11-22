//
// Created by 龚余 on 2023/6/6.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   int equalPairs(vector<vector<int>> &grid)
   {
      int n = grid.size();
      int ans = 0;
      map<vector<int>, int> mp;
      // 按行存入set
      for (auto &row : grid)
         mp[row]++;
      // 按列访问
      for (int i = 0; i < n; ++i)
      {
         vector<int> column;
         for (int j = 0; j < n; ++j)
            column.push_back(grid[j][i]);
         if (mp.count(column))
            ans += mp[column];
      }
      return ans;
   }
};

int main()
{

}