//
// Created by 龚余 on 2023/3/16.
//
#include"bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int countSubarrays(vector<int> &nums, int k)
   {
      int n = nums.size(), k_ = nums.size();
      unordered_map<int, int> mp;
      mp[0] = 1;
      int ans = 0, pre_sum = 0;
      for (int i = 0; i < n; ++i)
      {
         // pre_sum-x=k_(或k_+1)
         if (nums[i] < k)
            --pre_sum;
         else if (nums[i] == k)
            pre_sum += k_;
         else
            ++pre_sum;
         if (mp.count(pre_sum - k_))
            ans += mp[pre_sum - k_];
         if (mp.count(pre_sum - k_ - 1))
            ans += mp[pre_sum - k_ - 1];
         mp[pre_sum]++;
      }
      return ans;
   }
};

int main()
{

}