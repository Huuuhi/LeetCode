//
// Created by 龚余 on 2023/6/26.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int pivotInteger(int n)
   {
      if (n == 1)
         return 1;

      int sum = 0;
      for (int i = 1; i <= n; ++i)
      {
         sum += i;
      }
      int cnt = 1;
      for (int i = 2; i <= n; ++i)
      {
         if ((i + cnt + cnt) == sum)
            return i;
         cnt += i;
      }
      return -1;
   }
};
int main()
{
   Solution so;
   cout << so.pivotInteger(8);
}