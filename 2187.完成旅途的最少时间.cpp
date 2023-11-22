//
// Created by 龚余 on 2023/6/6.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   long long minimumTime(vector<int> &time, int totalTrips)
   {
      long long m = LONG_MAX;
      long long left = 1, right = (long long) totalTrips * *max_element(time.begin(), time.end());;
      while (left < right)
      {
         long long mid = (left + right) / 2;
         if (calTrip(time, mid) >= totalTrips)
         {
            right = mid;
         } else
            left = mid + 1;
      }
      return left;
   }
   long long calTrip(vector<int> &time, long long ti)
   {
      long long trip = 0;
      for (auto &t : time)
      {
         trip += (ti / t);
      }
      return trip;
   }
};
int main()
{

}