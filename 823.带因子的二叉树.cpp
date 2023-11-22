//
// Created by 龚余 on 2023/8/29.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int numFactoredBinaryTrees(vector<int> &arr)
  {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    unordered_map<int, int> idx;
    for (int i = 0; i < n; ++i)
    {
      idx[arr[i]] = i;
    }
    vector<long long> dp(n, 1);
    for (int i = 0; i < n; ++i)
    {
      int val = arr[i];
      for (int j = 0; j < i; ++j)
      {
        int x = arr[j];
        if (1LL * x * x > val)
          break;
        if (x * x == val)
        {
          dp[i] += dp[j] * dp[j];
          break;
        }
        if (val % x == 0 && idx.count(val / x))
        {
          dp[i] += dp[j] * dp[idx[val / x]] * 2;
        }
      }
    }
    return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
  }
};