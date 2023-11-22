//
// Created by 龚余 on 2023/3/21.
//
#include "bits/stdc++.h"

using namespace std;

/*
 * 思路：单调栈；维护一个栈，如果栈为空直接将数字压入栈中，如果不为空，考虑比较栈顶元素大小，若比栈顶元素大则必定是第一个比它大的数，将它计算后加入答案队列
 * */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            int t = temperatures[i];
            while (!s.empty() && temperatures[s.top()] < t) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

int main() {

}