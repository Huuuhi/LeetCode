//
// Created by 龚余 on 2023/6/7.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int maximumCandies(vector<int> &candies, long long k)
   {
      int n = candies.size();
      auto check = [&](int i) {
         long long res = 0;
         for (auto c : candies)
            res += c / i;
         return res >= k;
      };
      int l = 1, r = 1 + *max_element(candies.begin(), candies.end());
      int ans = 0;
      while (l < r)
      {
         int mid = (l + r - 1) / 2;
         if (check(mid))
         {
            l = mid + 1;
         } else
            r = mid;
      }
      return l - 1;
   }
};
int main()
{

}