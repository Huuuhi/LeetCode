//
// Created by 龚余 on 2023/5/16.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        int dp[n];
        /*初始化第一行*/
        dp[0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i)
            dp[i] = max(dp[i - 1], jobDifficulty[i]);
        for (int i = 1; i < d; ++i) {
            for (int j = n - 1; j >= i; --j) {
                dp[j] = INT_MAX;
                int mx = 0;
                for (int k = j; k >= i; --k) {
                    mx = max(mx, jobDifficulty[k]);
                    dp[j] = min(dp[j], dp[k - 1] + mx);
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {

}