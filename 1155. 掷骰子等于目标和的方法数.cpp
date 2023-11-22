//
// Created by 龚余 on 2023/10/24.
//
#include "bits/stdc++.h"
using namespace std;

/*
class Solution
{
 public:
  int numRollsToTarget(int n, int k, int target)
  {
    if (target < n || target > n * k)
      return 0;
    const int MOD = 1'000'000'007;
    vector<vector<int>> dp(n + 1, vector<int>(target - n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 0; j <= target - n; j++)
      {
        for (int x = 0; x < k && x <= j; x++) { // 掷出了 x
          dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
        }
      }
    }
    return dp.back().back();
  }
};*/

class Solution
{
 public:
  int numRollsToTarget(int n, int k, int target)
  {
    /*
     * dp[i][j]=dp[i-1][j-1]+...+dp[i-1][j-k]...
     * 为了避免讨论 j<0 的情况，可以把问题改成：每个骰子上的数字是 0 到 k−1，数字之和是 target−n。相当于把每个骰子掷出的数字都提一个 1 出来，那么这些骰子的数字之和就等于 target−n。
     * 如此一来，如果 x>j，那么 j−x<0，方案数必然为 0，所以 x 至多枚举到 j。
     * 修改后的式子为 dp[i][j]=dp[i-1][j]+...+dp[i-1][j-min(j,k-1)]
     * 注意观察，在这种情况下，若j<=k-1时，dp[i][j]=dp[i-1][j]+...dp[i-1][0]不就是前缀和设为s[j]，j<k-1时就变成了s[j]-s[j-(k-1)-1]
     * */
    if (target < n || target > n * k)
      return 0;
    const int MOD = 1'000'000'007;
    vector<long long> dp(target - n + 1);
    dp[0] = 1;
    for(int i=1;i<=n;++i){
      int max_j = min(i * (k - 1), target - n); //这里是一个小trick，因为i个硬币最多到i*(k-1)如果target超过这个值则方案数量为0
      for(int j=1;j<=max_j;j++){
        dp[j]+=dp[j-1];
      }
      for(int j=max_j;j>=k;j--){
        dp[j]=(dp[j] - dp[j - k]) % MOD;
      }
    }
    unordered_set<int> s;
    s.
    return dp.back();
  }
};