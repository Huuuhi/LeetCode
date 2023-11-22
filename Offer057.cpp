//
// Created by 龚余 on 2023/5/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int n = nums.size();
        set<int> rec;
        for (int i = 0; i < n; ++i) {
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t); //INT_MIN+t是为了防止越界
            if(iter!=rec.end()&&*iter<=t+min(nums[i],INT_MAX-t)){
                return true;
            }
            rec.insert(nums[i]);
            if(i>=k){
                rec.erase(nums[i-k]);
            }
        }
        return false;
    }
};