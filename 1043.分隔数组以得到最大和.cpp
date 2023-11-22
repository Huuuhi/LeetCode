//
// Created by 龚余 on 2023/4/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int mx=0;
            for(int j=i;j>max(0,i-k);--j){
                mx=max(mx,arr[j-1]);
                dp[i]=max(dp[i],dp[j-1]+mx*(i-j+1));
            }
            cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};

int main() {

}