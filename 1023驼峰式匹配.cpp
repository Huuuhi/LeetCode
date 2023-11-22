//
// Created by 龚余 on 2023/4/14.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        int l_p = pattern.size(), p = 0, n = queries.size();
        vector<bool> ans(n, true);
        for (int j = 0; j < n; ++j) {
            string s = queries[j];
            p = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == pattern[p]&&p<l_p) {
                    ++p;
                } else if (s[i] >= 'A' && s[i] <= 'Z') {
                    ans[j] = false;
                }
            }
            if (p < l_p)
                ans[j] = false;
        }
        return ans;
    }
};
int main() {

}