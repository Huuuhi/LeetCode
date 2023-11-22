//
// Created by 龚余 on 2023/3/13.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
   {
      int ans = 0, totalEnergy = 0, totalExperience = initialExperience;
      for (auto &i : energy)
      {
         totalEnergy += i;
      }
      ans = initialEnergy > totalEnergy ? 0 : totalEnergy - initialEnergy + 1;
      for (auto &i : experience)
      {
         int t = (totalExperience > i ? 0 : (i - totalExperience + 1));
         totalExperience += (i + t);
         ans += t;
      }
      return ans;
   }
};

int main()
{

}