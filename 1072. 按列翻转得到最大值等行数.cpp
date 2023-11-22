//
// Created by 龚余 on 2023/5/15.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        unordered_map<string, int> mp;
        int ans = 0;
        for (auto &row: matrix) {
            string s;
            for (auto &i: row) {
                s.push_back('0' + (row[0] == 0 ? i : i ^ 1));
            }
            mp[s]++;
            ans = max(ans, mp[s]);
        }
        return ans;
    }
};

int main() {

}