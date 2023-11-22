//
// Created by 龚余 on 2023/3/28.
//
#include"bits/stdc++.h"

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        /**/
        for (int i = 0; i < n + 1; ++i) {
            dp[i][m] = n - i;
        }
        for (int i = 0; i < m + 1; ++i) {
            dp[n][i] = m - i;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
                }
            }
        }
        string ans;
        int t1 = 0, t2 = 0;
        while (t1 < n && t2 < m) {
            if (str1[t1] == str2[t2]) {
                ans.push_back(str1[t1]);
                ++t1;
                ++t2;
            } else if (dp[t1][t2] == dp[t1 + 1][t2] + 1) {
                ans.push_back(str1[t1]);
                ++t1;
            } else if (dp[t1][t2] == dp[t1][t2 + 1] + 1) {
                ans.push_back(str2[t2]);
                ++t2;
            }
        }
        if(t1<n){
            ans+=str1.substr(t1);
        }
        if(t2<m){
            ans+=str2.substr(t2);
        }
        return ans;
    }
};

int main() {

}