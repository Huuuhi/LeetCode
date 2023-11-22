//
// Created by 龚余 on 2023/4/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0 || n == 1)
            return to_string(n);
        string ans;
        while (n) {
            int remainer = n & 1;
            cout << remainer << " ";
            ans += ('0' + remainer);
            n-=remainer;
            n/=(-2);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

}