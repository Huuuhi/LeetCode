//
// Created by 龚余 on 2023/3/9.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int countSubstrings(string s)
   {
      int n = s.size();
      string t = "$#";
      for (auto c : s)
      {
         t += c;
         t += '#';
      }
      n = t.size();
      t += '!';
      int ans = 0, iMax = 0, rMax = 0;
      vector<int> f(n);
      for (int i = 1; i < n; i++)
      {
         // init f[i]
         f[i] = (i <= rMax) ? min(f[2 * iMax - i], rMax - i + 1) : 1;
         // 中心扩散
         while (t[i + f[i]] == t[i - f[i]]) ++f[i];
         if (i + f[i] - 1 > rMax)
         {
            iMax = i;
            rMax = i + f[i] - 1;
         }
         ans += (f[i] / 2);
      }
      return ans;
   }
};

int main()
{

}