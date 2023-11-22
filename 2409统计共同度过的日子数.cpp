//
// Created by 龚余 on 2023/4/17.
//
#include "bits/stdc++.h"
using namespace std;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution
{
  public:
   int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
   {

      vector<int> prefixSum(1, 0);
      for (int date : days)
      {
         prefixSum.emplace_back(prefixSum.back() + date);
      }
      int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
      int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
      int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
      int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
      return max(0, min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1);
   }
   int calculateDayOfYear(string day, const vector<int> &prefixSum)
   {
      int month = stoi(day.substr(0, 2));
      int date = stoi(day.substr(3));
      return prefixSum[month - 1] + date;
   }

};
int main()
{

}