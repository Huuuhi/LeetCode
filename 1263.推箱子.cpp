//
// Created by 龚余 on 2023/5/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minPushBox(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int sx = 0, sy = 0, bx = 0, by = 0;
        /*找人和箱子的初始位置*/
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] == 'B') {
                    bx = i;
                    by = j;
                }
            }

        vector<vector<int>> dp(m * n, vector<int>(m * n, INT_MAX));
        queue<pair<int, int>> q;
        vector<int> dir = {0, -1, 0, 1, 0};
        auto ok = [&](int x, int y) -> bool {
            return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
        };
        dp[sx * n + sy][bx * n + by] = 0;//初始状态推动箱子次数为0；
        q.emplace(sx * n + sy, bx * n + by);
        while (!q.empty()) {
            queue<pair<int, int>> q1;
            while (!q.empty()) {
                auto [s1, b1] = q.front();
                int s1x = s1 / n, s1y = s1 % n, b1x = b1 / n, b1y = b1 % n;
                q.pop();
                if (grid[b1x][b1y] == 'T') {
                    return dp[s1][b1];
                }
                for (int i = 0; i < 4; ++i) {
                    /*判断人往这边走是否合格*/
                    int s2x = s1x + dir[i], s2y = s1y + dir[i + 1], s2 = s2x * n + s2y;
                    if (ok(s2x, s2y)) {
                        /*判断箱子是否被推动*/
                        if (s2x == b1x && s2y == b1y) {
                            /*判断箱子推动是否合理,是否被访问过*/
                            int b2x = b1x + dir[i], b2y = b1y + dir[i + 1], b2 = b2x * n + b2y;
                            if (!ok(b2x, b2y) || dp[s2][b2] <= dp[s1][b1] + 1) {
                                continue;
                            }
                            dp[s2][b2] = dp[s1][b1] + 1;
                            q1.emplace(s2, b2);
                        } else {
                            if (dp[s2][b1] <= dp[s1][b1])
                                continue;
                            dp[s2][b1] = dp[s1][b1];
                            q.emplace(s2, b1);
                        }
                    } else {
                        continue;
                    }
                }
            }
            q.swap(q1);
        }
        return -1;
    }
};

int main() {

}