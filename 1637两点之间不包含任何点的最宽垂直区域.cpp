//
// Created by 龚余 on 2023/3/30.
//
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int mx = 0;
        for (int i = 1; i < points.size(); i++) {
            mx = max(points[i][0] - points[i - 1][0], mx);
        }
        return mx;
    }
};


int main(){

}