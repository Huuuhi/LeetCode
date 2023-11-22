//
// Created by 龚余 on 2023/3/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        int n = l.size();
        vector<bool> ans;
        for (int i = 0; i < n; ++i) {
            /*判断l[i]到r[i]是否为等差数列：
             * 找出l[i]->r[i]最小值和最大值a,b，随后d=b-a/len(l[i],r[i]),然后就可以知道l[i]->r[i]的理论值进行比较*/
            int left = l[i], right = r[i];
            int min_e = *min_element(nums.begin() + left, nums.begin() + right + 1);
            int max_e = *max_element(nums.begin() + left, nums.begin() + right + 1);
            if (max_e == min_e) {
                // 即 1，1，1，1这种情况
                ans.push_back(true);
                continue;
            }
            cout << "max_e: " << max_e << " min_e: " << min_e << endl;
            if ((max_e - min_e) % (right - left) != 0) {
                ans.push_back(false);
                continue;
            }
            int d = (max_e - min_e) / (right - left);
            bool flag = true;
            vector<int> seen(right - left + 1);
            for (int j = left; j <= right; ++j) {
                if ((nums[j] - min_e) % d != 0) {
                    flag = false;
                    break;
                }
                int t = (nums[j] - min_e) / d;
                if (seen[t]) {
                    flag = false;
                    break;
                }
                seen[t] = true;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 6, 5, 9, 3, 7}, l = {0, 0, 2}, r = {2, 3, 5};
    Solution so;
    vector<bool> rst = so.checkArithmeticSubarrays(nums, l, r);
    for (auto item: rst) {
        cout << item << " ";
    }
}