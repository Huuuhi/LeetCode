//
// Created by 龚余 on 2023/9/7.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   long long repairCars(vector<int> &ranks, int cars)
   {
      using ll = long long int;
      ll ans = -1;
      int min_r = *min_element(ranks.begin(), ranks.end());
      ll upper = 1LL * min_r * cars * cars, lower = 0;
      auto check = [&](ll t) {
         ll sum = 0;
         for (auto &rank : ranks)
         {
            sum += (sqrt(t / rank));
         }
         return sum >= cars;
      };
      while (lower <= upper)
      {
         ll mid = lower + (upper - lower) / 2;
         if (check(mid))
         {
            upper = mid - 1;
            ans = mid;
         } else
         {
            lower = mid + 1;
         }
      }
      return ans;
   }
};