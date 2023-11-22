//
// Created by 龚余 on 2023/5/23.
//
#include "bits/stdc++.h"
#include "stdlib.h"
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        vector<int> s(n);
        for(int i=0;i<n;++i)
            s[i]=i;
        sort(s.begin(),s.end(),[&](int i,int j){
            return values[i]>values[j];
        });
        int choose=0;
        unordered_map<int,int> cnt;
        int ans=0;
        for(int i=0;i<n&&choose<numWanted;++i){
            int label=labels[s[i]];
            if(cnt[label]==useLimit){
                continue;
            }
            ans+=values[s[i]];
            ++choose;
            ++cnt[label];
        }
        return ans;
    }
};

int main(){

}