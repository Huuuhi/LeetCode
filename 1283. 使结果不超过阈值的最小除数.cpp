//
// Created by 龚余 on 2023/6/2.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    int left = 1, right = 0;
    for (auto &num : nums)
      right = max(num, right);
    int ans = -1;
    while (left < right)
    {
      int mid = (left + right) / 2;
      int s = calTotal(nums, mid);
      if (s > threshold)
      {
        left = mid + 1;
      } else if (s == threshold)
        return mid;
      else
      {
        right = mid;
        ans = mid;
      }
    }
    return ans;
  }
  int calTotal(vector<int> &nums, int div)
  {
    int sum = 0;
    for (auto &num : nums)
    {
      sum += (num + div - 1) / div;
    }
    return sum;
  }
};

int main()
{

}
