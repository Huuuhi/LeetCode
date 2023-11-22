//
// Created by 龚余 on 2023/3/15.
//
#include"bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<vector<bool>> connect(n, vector(n, false));
        vector<int> degree(n);
        for (auto road: roads) {
            connect[road[0]][road[1]] = true;
            connect[road[1]][road[0]] = true;
            degree[road[0]]++;
            degree[road[1]]++;
        }
        int first = -1, second = -2;
        vector<int> firstArr, secondArr;
        for (int i = 0; i < n; i++) {
            if (degree[i] > first) {
                second = first;
                first = degree[i];
                secondArr = firstArr;
                firstArr.clear();
                firstArr.emplace_back(i);
            } else if (degree[i] == first) {
                firstArr.emplace_back(i);
            } else if (degree[i] > second) {
                second = degree[i];
                secondArr.clear();
                secondArr.emplace_back(i);
            } else if (degree[i] == second) {
                secondArr.emplace_back(i);
            }
        }
        /*if()*/
        if (firstArr.size() == 1) {
            int u = firstArr[0];
            for (auto v: secondArr) {
                if (connect[u][v] == 0)
                    return first + second;
            }
            return first + second - 1;
        } else {
            int ans = first * 2, m = firstArr.size();
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    if (connect[firstArr[i]][firstArr[j]] == 0)
                        return ans;
                }
            }
            return ans - 1;
        }
    }
};

int main() {

}