//
// Created by 龚余 on 2023/3/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
   int getMinutes(string &t)
   {
      return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0');
   }

  public:
   int findMinDifference(vector<string> &timePoints)
   {
      sort(timePoints.begin(), timePoints.end());
      int ans = INT_MAX;
      for (int i = 0; i < timePoints.size() - 1; i++)
      {
         int t1 = getMinutes(timePoints[i]);
         int t2 = getMinutes(timePoints[i + 1]);
         ans = min(ans, abs(t2 - t1));
      }
      int t1 = getMinutes(timePoints[0]);
      int t2 = getMinutes(timePoints[timePoints.size() - 1]);
      ans = min(ans, abs(t2 - 24 * 60 - t1));
      return ans;
   }
};

int main()
{

}