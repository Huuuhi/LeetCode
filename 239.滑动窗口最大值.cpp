//
// Created by 龚余 on 2023/11/7.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   vector<int> maxSlidingWindow(vector<int> &nums, int k)
   {
      int n = nums.size();
      deque<int> dq; //当作单调队列使用
      for (int i = 0; i < k; ++i)
      {
         while (!dq.empty() && nums[i] >= nums[dq.back()])
         {
            dq.pop_back();
         }
         dq.push_back(i);
      }
      vector<int> ans{nums[dq.front()]};
      for (int i = k; i < n; ++i)
      {
         // 挤出去一个，再加入一个
         while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
         while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
         dq.push_back(i);
         ans.push_back(nums[dq.front()]);
      }
      return ans;
   }
};