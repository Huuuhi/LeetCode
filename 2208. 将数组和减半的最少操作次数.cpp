//
// Created by 龚余 on 2023/7/25.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   int halveArray(vector<int> &nums)
   {
      double s = 0;
      priority_queue<double, vector<double>, less<>> pq;
      for (auto &num : nums)
      {
         s += num;
         pq.push(num);
      }
      int ans = 0;
      double curSum = s;
      while (!pq.empty() && curSum > (s / 2))
      {
         auto t = pq.top();
         pq.pop();
         t /= 2.0;
         curSum -= (t);
         pq.push(t);
         ans++;
      }
      return ans;
   }
};

int main()
{

}