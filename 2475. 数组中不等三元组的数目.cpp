//
// Created by 龚余 on 2023/6/13.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int unequalTriplets(vector<int> &nums)
   {
      int n = nums.size();
      int cnt = 0;
      sort(nums.begin(), nums.end());
      for (int i = 0, j = 0; i < n; i = j)
      {
         while (j < n && nums[j] == nums[i])
         {
            j++;
         }
         cnt += i * (j - i) * (n - j);
      }

      return cnt;
   }
};

int main()
{

}