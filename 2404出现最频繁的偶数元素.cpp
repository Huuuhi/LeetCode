//
// Created by 龚余 on 2023/4/13.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int mostFrequentEven(vector<int> &nums)
   {
      unordered_map<int, int> mp;
      int ans = -1, ans_n = -1;
      for (auto &i : nums)
      {
         if (i % 2 == 0)
         {
            mp[i]++;
            if (ans_n < mp[i])
            {
               ans_n = mp[i];
               ans = i;
            } else if (ans_n == mp[i])
            {
               ans = min(ans, i);
            }
         }
      }
      return ans;
   }
};

int main()
{

}