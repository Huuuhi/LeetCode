//
// Created by 龚余 on 2023/11/27.
//
#include<bits/stdc++.h>

/*
 * Question: 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。由于答案可能很大，因此 返回答案模 10^9 + 7 。
 * Solution:
 *    1. 暴力法，枚举所有子数组，找到最小值，累加
 *    2. 单调栈，找到每个元素左右两边第一个比它小的元素，然后计算以该元素为最小值的子数组个数
 *       a. 暴力法太慢了，换个视角，对每个数，算出它是哪些子数组的最小值。这样ans=ans+arr[i]*numofsubarray[满足arr[i]是最小值的子数组个数]
 *       b. 假设找到的区间是(L,R)开区间，以该元素为最小值的子数组个数 = (i-L-1+1)*(R-i-1+1), 满足排列组合的定律，该元素左边有i-L-1个元素，右边有R-i-1个元素
 *          但是两边各还有一种都不选的可能，所以要+1
 *       c. 所以就可以用两个单调栈实现，一个维护左边界，一个维护右边界，left保存比当前元素小的左边最大元素的下标，right保存比当前元素小于等于右边最小元素的下标
 * */
class Solution
{
  public:
   int sumSubarrayMins(vector<int> &arr)
   {
      const int MOD = 1e9 + 7;
      int n = arr.size();
      vector<int> left(n, -1), right(n, n);
      stack<int> s;
      for (int i = 0; i < n; ++i)
      {
         while (!s.empty() && arr[s.top()] >= arr[i])
         {
            s.pop();
         }
         if (!s.empty()) left[i] = s.top();
         s.push(i);
      }
      while (!s.empty())s.pop();
      for (int i = n - 1; i >= 0; --i)
      {
         while (!s.empty() && arr[s.top()] > arr[i])
         {
            s.pop();
         }
         if (!s.empty())right[i] = s.top();
         s.push(i);
      }
      long ans = 0L;
      for (int i = 0; i < n; ++i)
      {
         ans += (long) arr[i] * (i - left[i]) * (right[i] - i);
      }
      return ans % MOD;
   }
};