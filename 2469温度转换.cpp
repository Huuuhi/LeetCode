//
// Created by 龚余 on 2023/3/21.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   vector<double> convertTemperature(double celsius)
   {
      return {celsius + 273.15, celsius * 1.80 + 32.00};
   }
};

int main()
{

}