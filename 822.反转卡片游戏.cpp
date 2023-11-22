//
// Created by 龚余 on 2023/8/2.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int flipgame(vector<int> &fronts, vector<int> &backs)
  {
    int n = fronts.size();
    unordered_set<int> same;
    for (int i = 0; i < n; ++i)
    {
      if (fronts[i] == backs[i])
        same.insert(backs[i]);
    }
    int ans = 3000;
    for (int i = 0; i < n; ++i)
    {
      if (fronts[i] < ans && !same.count(fronts[i]))
        ans = fronts[i];
    }
    for (int i = 0; i < n; ++i)
    {
      if (backs[i] < ans && !same.count(backs[i]))
        ans = backs[i];
    }
    return ans % 3000;
  }
};