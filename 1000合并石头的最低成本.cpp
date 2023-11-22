//
// Created by 龚余 on 2023/4/4.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
    static constexpr int inf = 0x3f3f3f3f;

public:
    int mergeStones(vector<int> &stones, int k) {
        /*
         * Solution:
         *      首先考虑简化的问题，将[0,n]的石头两两合并，用dp[i][j]表示将[i,j]的石子合并在一起的最小代价，dp[i][j]=min(dp[i][p]+dp[p+1][j])+sum[i][j], i<p<j
         *      考虑k合并，无非是再加上一个维度，用dp[i][j][k]表示将i->j的石子合并成k堆所需要的代价
         *          dp[i][j][k]=min(dp[i][p][1]+dp[p+1][j][k-1])+sum i<p<j
         *          目标是dp[0][n][1]
         * */
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
            return -1;
        vector dp(n, vector(n, vector(k + 1, inf)));
        vector<int> sum(n, 0);
        for (int i = 0, s = 0; i < n; ++i) {
            dp[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }
        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l < n && l + len - 1 < n; l++) {
                int r = l + len - 1;
                for (int t = 2; t <= k; t++) {
                    for (int p = l; p < r; p += k - 1) {
                        dp[l][r][t] = min(dp[l][r][t], dp[l][p][1] + dp[p + 1][r][t - 1]);
                    }
                }
                dp[l][r][1] = min(dp[l][r][1], dp[l][r][k] + sum[r] - (l == 0 ? 0 : sum[l - 1]));
            }
        }
        return dp[0][n - 1][1];
    }
};

int main() {
    cout << "hello";
}