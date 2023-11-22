//
// Created by 龚余 on 2023/7/20.
//
#include "bits/stdc++.h"
using namespace std;


class Solution
{
 public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int n = nums.size();
    int pre1 = nums[0], pre2 = nums[0], maxA = nums[0], minA = nums[0], sum = nums[0];
    for (int i=1;i<n;++i)
    {
      pre1 = max(pre1 + nums[i], nums[i]);
      maxA = max(maxA, pre1);
      pre2 = min(pre2 + nums[i], nums[i]);
      minA = min(minA, pre2);
      sum += nums[i];
    }
    if(maxA<0)
      return maxA;
    return max(maxA, sum - minA);
  }
};
int main()
{

}