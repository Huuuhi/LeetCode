//
// Created by 龚余 on 2023/6/1.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
 public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int n = piles.size();
    int left = 1, right = 1;
    for (auto &i : piles)
      right = max(i, right);
    int ans = right;
    while (left < right)
    {
      int mid = (left + right) / 2;
      bool flag = check(piles, h, mid);
      if (flag)
      {
        ans = mid;
        right = mid;
      } else
        left = mid + 1;
    }
    return ans;
  }
  bool check(vector<int> &piles, int h, int speed)
  {
    int total = 0;
    for (auto &pile : piles)
    {
      total += (pile-1)/speed+1;
    }
    return total <= h;
  }
};
int main()
{

}