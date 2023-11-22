//
// Created by 龚余 on 2023/3/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        int x = 0;
        for (auto num: nums)
            x = (x + num) % p;
        if (x == 0)
            return 0;
        unordered_map<int, int> index;
        int y = 0, ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            index[y] = i;
            y = (y + nums[i]) % p;
            if (index.count((y - x + p) % p) > 0) {
                ans = min(ans, i - index[(y - x + p) % p]);
            }
        }
        return ans == nums.size() ? -1 : ans;
    }
};

int main() {

}