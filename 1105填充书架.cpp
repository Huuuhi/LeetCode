//
// Created by 龚余 on 2023/4/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int maxHeight = 0, curWidth = 0;
            for (int j = i; j > 0; --j) {
                curWidth += books[j - 1][0];
                if (curWidth > shelfWidth)
                    break;
                maxHeight = max(maxHeight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
            }
        }
        return dp[n];
    }
};

int main() {

}