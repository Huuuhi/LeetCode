//
// Created by 龚余 on 2023/5/11.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        int m = s.size();
        /*维持一个滑动窗口，枚举s的字串，如果字串在n以内则加入hash表，若最后hash表的长度刚好等于n则说明可以表示1-n的任意值*/
        unordered_set<int> seen;
        for (int i = 0; i < s.size(); ++i) {
            int x = s[i] - '0';
            if (x == 0)
                continue;
            for (int j = i + 1; j <= m && x <= n; ++j) {
                seen.insert(x);
                if (j < m)
                    x = (x << 1) | (s[j] - '0');
            }
        }
        if(seen.size()==n)
            return true;
        return false;
    }
};

int main() {

}