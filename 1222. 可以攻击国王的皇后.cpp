//
// Created by 龚余 on 2023/9/14.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  const int directions[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
 public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
  {
    bool isQueen[8][8]{};
    for (auto &queen : queens)
    {
      isQueen[queen[0]][queen[1]] = true;
    }
    vector<vector<int>> ret;
    for (auto &dir : directions)
    {
      int x = king[0] + dir[0], y = king[1] + dir[1];
      while (x >= 0 && x < 8 && y >= 0 && y < 8)
      {
        if (isQueen[x][y])
        {
          ret.push_back({x, y});
          break;
        }
        x += dir[0];
        y += dir[1];
      }
    }
    return ret;
  }
};