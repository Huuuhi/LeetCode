//
// Created by 龚余 on 2023/4/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &stones) {
        int n = stones.size();
        sort(stones.begin(),stones.end());
        int max_l= stones.back()-stones[0]+1-n;
        if(max_l==0)
            return {0,0};
        int ma = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        int mi=n;
        for(int i=0,j=0;i<n&&j+1<n;++i){
            while(j+1<n&&stones[j+1]-stones[i]+1<=n)
                ++j;
            if(j-i+1==n-1&&stones[j]-stones[i]+1==n-1){
                mi=min(mi,2);
            }
            else{
                mi=min(mi,n-(j-i+1));
            }
        }
        return {mi,ma};
    }
};

int main() {

}