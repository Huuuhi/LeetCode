//
// Created by 龚余 on 2023/5/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int hardestWorker(int n, vector<vector<int>> &logs)
   {
      int maxHour = logs[0][1];
      int maxId = logs[0][0];
      for (int i = 1; i < logs.size(); ++i)
      {
         int wh = logs[i][1] - logs[i - 1][1];
         if (wh > maxHour)
         {
            maxHour = wh;
            maxId = logs[i][0];
         } else if (wh == maxHour)
            maxId = min(logs[i][0], maxId);
      }
      return maxId;
   }
};

int main()
{

}