//
// Created by 龚余 on 2023/7/25.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   long long maxArrayValue(vector<int> &nums)
   {
      long long ans = nums[0];
      int n = nums.size();
      long long res = 0;
      for (int i = n - 1; i >= 0; --i)
      {
         if (res >= nums[i])
         {
            res = res + nums[i];
         } else
            res = nums[i];
         ans = max(ans, res);
      }
      return ans;
   }
};

int main()
{

}