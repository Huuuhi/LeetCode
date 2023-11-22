//
// Created by 龚余 on 2023/7/27.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int maxIncreasingGroups(vector<int> &usageLimits)
   {
      int n = usageLimits.size();
      vector<long long> copy(usageLimits.begin(), usageLimits.end());
      sort(copy.begin(), copy.end());

      int x = 1;
      for (int i = 0; i < n; ++i)
      {
         if (copy[i] >= x) copy[i] -= x++;
         if (i + 1 < n) copy[i + 1] += copy[i];
      }
      return x - 1;
   }
};

int main()
{

}