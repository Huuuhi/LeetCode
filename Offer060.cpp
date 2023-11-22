//
// Created by 龚余 on 2023/6/26.
//
#include"bits/stdc++.h"
using namespace std;
class Solution
{
 public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int,int> frequency;
    auto cmp=[](const pair<int, int>& a, const pair<int, int>& b){
      return a.second>b.second;
    };
    for(auto &num:nums)
      frequency[num]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> q(cmp);
    for(auto[key,value]:frequency){
      if(q.size()<k){
        q.emplace(key,value);
      }
      else{
        if(q.top().second<value){
          q.pop();
          q.emplace(key,value);
        }
      }
    }
    vector<int> ret;
    while(!q.empty()){
      ret.push_back(q.top().first);
      q.pop();
    }
    return ret;
  }
};
int main()
{

}