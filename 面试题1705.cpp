//
// Created by 龚余 on 2023/3/11.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int calValue(string a) {
        if (a[0] >= '0' && a[0] <= '9')
            return -1;
        else
            return 1;
    }

    vector<string> findLongestSubarray(vector<string> &array) {
        unordered_map<int, int> indices;
        indices[0] = -1;
        int sum = 0;
        int maxLength = 0;
        int startIndex = -1;
        int n = array.size();
        for (int i = 0; i < n; ++i) {
            sum += calValue(array[i]);
            if (indices.count(sum)) {
                int firstIndex = indices[sum];
                if (i - firstIndex > maxLength) {
                    maxLength = i - firstIndex;
                    startIndex = firstIndex + 1;
                }
            } else {
                indices[sum] = i;
            }
        }
        if (maxLength == 0)
            return {};
        return vector<string>(array.begin() + startIndex, array.begin() + startIndex + maxLength);
    }
};

int main() {

}