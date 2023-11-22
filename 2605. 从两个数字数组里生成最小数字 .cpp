//
// Created by 龚余 on 2023/9/5.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int minNumber(vector<int> &nums1, vector<int> &nums2)
   {
      unordered_set<int> st;
      int a = 10, b = 10, ans = 100;
      for (auto &num : nums1)
      {
         a = min(a, num);
         st.insert(num);
      }
      for (auto &num : nums2)
      {
         if (st.count(num))
            ans = min(ans, num);
         b = min(b, num);
      }
      if (ans != 100)
         return ans;
      if (a == b)
         return a;
      else if (a < b)
         return a * 10 + b;
      else return b * 10 + a;
   }
};