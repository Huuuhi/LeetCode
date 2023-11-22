#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int maxDistToClosest(vector<int> &seats)
  {
    int i = 0, dMiMx = 0, n = seats.size();
    while (i < n && seats[i] == 0)
      ++i;
    dMiMx = max(i, dMiMx);
    while (i < n)
    {
      int j = i + 1;
      while (j < n && seats[j] == 0)
      {
        ++j;
      }
      if (j == n)
      {
        dMiMx = max(dMiMx, j - i - 1);
      } else
      {
        dMiMx = max(dMiMx, (j - i) / 2);
      }
      i = j;
    }
    return dMiMx;
  }
};