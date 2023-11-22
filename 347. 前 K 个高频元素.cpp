//
// Created by 龚余 on 2023/11/8.
//
#include"bits/stdc++.h"

using namespace std;

class Solution
{
   static bool cmp(pair<int, int> &m, pair<int, int> &n)
   {
      return m.second > n.second;
   }
  public:
   vector<int> topKFrequent(vector<int> &nums, int k)
   {
      unordered_map<int, int> mp; // 元素，词频
      int n = nums.size();
      for (auto &num : nums)
      {
         mp[num]++;
      }
      auto cmp = [&](int a, int b) { return mp[a] > mp[b]; };
      priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
      for (auto &[num, count] : mp)
      {
         if (q.size() == k)
         {
            if (count > mp[q.top()])
            {
               q.pop();
               q.push(num);
            }
         } else
            q.push(num);
      }
      vector<int> ans;
      while (!q.empty())
      {
         ans.push_back(q.top());
         q.pop();
      }
      return ans;
   }
};