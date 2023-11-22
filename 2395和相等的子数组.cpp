//
// Created by 龚余 on 2023/3/26.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   bool findSubarrays(vector<int> &nums)
   {
      unordered_set<int> s;
      for (int i = 0; i < nums.size() - 1; i++)
      {
         int t = nums[i] + nums[i + 1];
         if (s.count(t))
         {
            return true;
         }
         s.insert(t);
      }
      return false;
   }
};

int main()
{

}