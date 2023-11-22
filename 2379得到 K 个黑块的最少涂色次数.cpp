//
// Created by 龚余 on 2023/3/9.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int minimumRecolors(string blocks, int k)
   {
      int white = 0, n = blocks.size();
      if (k > n)
         return -1;
      for (int i = 0; i < k; i++)
      {
         if (blocks[i] == 'W')
            white++;
      }
      int ans = white;
      for (int i = k; i < n; i++)
      {
         if (blocks[i - k] == 'W') white--;
         if (blocks[i] == 'W') white++;
         ans = min(ans, white);
      }
      return ans;
   }
};

int main()
{
   Solution solution;
   cout << solution.minimumRecolors("WBBWWBBWBW", 7);
}
