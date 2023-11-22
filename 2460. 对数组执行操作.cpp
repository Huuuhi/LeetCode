//
// Created by 龚余 on 2023/6/5.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   vector<int> applyOperations(vector<int> &nums)
   {
      int n = nums.size();
      for (int i = 0; i < n - 1; ++i)
      {
         if (nums[i] == nums[i + 1])
         {
            nums[i] *= 2;
            nums[i + 1] = 0;
         }
      }
      vector<int> ans(n);
      int pos = 0;
      for (auto &num : nums)
      {
         if (num != 0)
            ans[pos++] = num;
      }
      return ans;
   }
};
int main()
{

}