//
// Created by 龚余 on 2023/3/27.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> vtl(m + 1, vector<int>(n + 1));
        vector<vector<int>> vtr(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                vtl[i + 1][j + 1] = (s[i] == t[j] ? vtl[i][j] + 1 : 0);
            }
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                vtr[i][j] = (s[i] == t[j] ? vtr[i + 1][j + 1] + 1 : 0);
            }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] != t[j]) {
                    int l = vtl[i][j];
                    int r = vtr[i + 1][j + 1];
                    ans += (l + 1) * (r + 1);
                }
            }
        }
        return ans;
    }
};

int main() {

}