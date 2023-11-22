//
// Created by 龚余 on 2023/5/9.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  public:
   bool check(string &time)
   {
      int hour = (time[0] - '0') * 10 + (time[1] - '0');
      int minute = (time[3] - '0') * 10 + (time[4] - '0');
      if (hour >= 0 && hour <= 23)
         if (minute >= 0 && minute <= 60)
            return true;
      return false;
   };
   int countTime(string time)
   {
      int res = 0;
      int n = time.size();
      function<void(int)> dfs = [&](int pos) {
         if (pos == n)
         {
            if (check(time))
            {
               res++;
            }
            return;
         }
         if (time[pos] == '?')
         {
            for (int i = 0; i <= 9; ++i)
            {
               time[pos] = '0' + i;
               dfs(pos + 1);
               time[pos] = '?';
            }
         } else
            dfs(pos + 1);
      };
      dfs(0);
      return res;
   }
};
int main()
{

}