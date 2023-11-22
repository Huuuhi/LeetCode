//
// Created by 龚余 on 2023/7/13.
//
#include"bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    vector<int> dp(n + 2, INT_MAX);
    for (int j = 0; j < n; ++j)
      dp[j + 1] = matrix[0][j];
    for (int i = 1; i < n; ++i)
    {
//      vector<int> tp(n + 2, INT_MAX);
      int pre=dp[0];
      for (int j = 0; j < n; ++j)
      {
        int tp=pre;
        pre=dp[j+1];
        dp[j + 1] = min({tp, dp[j + 1], dp[j + 2]}) + matrix[i][j];
      }
//      dp = tp;
    }
    return *min_element(dp.begin(), dp.end());
  }
};

int main()
{

}