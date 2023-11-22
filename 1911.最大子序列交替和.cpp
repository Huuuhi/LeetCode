//
// Created by 龚余 on 2023/7/11.
//
#include "bits/stdc++.h"
using namespace std;
/*Solution
 *  动态规划，num[i]每一位仅包含两种状态，选中与选不中，同时到下标[i]的子序列仅包含偶数与奇数两种情况
 *  dp[i][0]表示到下标i的为偶数的子序列交替和最大值，dp[i][1]表示到下标i为奇数的子序列交替和最大值
 *  dp[i][0] = max{dp[i-1][1]+nums[i], dp[i-1][0]}
 *  dp[i][1] = max{dp[i-1][0]-nums[i], dp[i-1][1]}
 *  最后比较dp[n-1][0], dp[n-1][1]最大值即可，其中dp[0][0]=nums[0], dp[0][1]=0
 *  可用滚动数组进行优化
 * */
class Solution
{
  public:
   long long maxAlternatingSum(vector<int> &nums)
   {
      long long even = nums[0], odd = 0;
      for (int i = 1; i < nums.size(); ++i)
      {
         int t = even;
         even = max(odd + nums[i], even);
         odd = max(even - nums[i], odd);
      }
      return even;
   }
};

int main()
{

}