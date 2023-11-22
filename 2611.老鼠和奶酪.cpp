//
// Created by 龚余 on 2023/6/7.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
   {
      int n = reward1.size();
      vector<int> diff(n);
      int sum = 0;
      for (int i = 0; i < n; ++i)
      {
         diff[i] = reward1[i] - reward2[i];
         sum += reward2[i];
      }
      sort(diff.begin(), diff.end(), greater<>());
      for (int i = 0; i < k; ++i)
      {
         sum += diff[i];
      }
      return sum;
   }
};