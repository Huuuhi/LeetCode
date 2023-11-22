//
// Created by 龚余 on 2023/3/30.
//
#include "bits/stdc++.h"

using namespace std;

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        v.push_back(t);
        auto idx=upper_bound(v.begin(),v.end(),t-3001);
        int counter=0;
        while(idx!=v.end()){
            ++counter;
            ++idx;
        }
        return counter;
    }
private:
    vector<int> v;
};

int main() {

}