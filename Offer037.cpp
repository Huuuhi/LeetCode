//
// Created by 龚余 on 2023/3/21.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   vector<int> asteroidCollision(vector<int> &asteroids)
   {
      for (int i = 0; i < asteroids.size(); i++)
      {
         if (asteroids[i] < 0)
         {

            int k = i - 1;
            int energy = -asteroids[i];
            while (k >= 0)
            {
               if (asteroids[k] < 0)
                  break;
               if (asteroids[k] > energy)
               {
                  asteroids[k + 1] = 0;
                  break;
               } else if (asteroids[k] == energy)
               {
                  asteroids[k + 1] = asteroids[k] = 0;
                  break;
               } else
               {
                  asteroids[k] = -energy;
                  asteroids[k + 1] = 0;
                  k--;
               }
            }
         }
      }
      vector<int> rst;
      for (auto i : asteroids)
      {
         if (i != 0)
            rst.push_back(i);
      }
      return rst;
   }
};

int main()
{
   Solution so;
   vector<int> k = {-2, -2, 1, -2};
   auto rst = so.asteroidCollision(k);
   for (auto i : rst)
      cout << i << " ";
}