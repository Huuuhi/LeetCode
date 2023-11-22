//
// Created by 龚余 on 2023/7/18.
//
#include "bits/stdc++.h"
using namespace std;

struct Query
{
   int val;
   int idx;
   int len;
   bool operator<(const Query &other) const
   {
      return val < other.val;
   }

};
struct Interval
{
   int tail;
   int len;
   bool operator<(const Interval &other) const
   {
      return len > other.len;
   }
};
class Solution
{
  public:
   vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
   {
      vector<Query> qVec;
      for (int i = 0; i < queries.size(); ++i)
      {
         qVec.push_back({queries[i], i, 0});
      }
      sort(qVec.begin(), qVec.end());
      sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
         if (a[0] == b[0])
            return a[1] < b[1];
         else
            return a[0] < b[0];
      });
      int tail = 0;
      priority_queue<Interval> PQ;
      for (auto &it : qVec)
      {
         while (tail < intervals.size() && intervals[tail][0] <= it.val)
         {
            PQ.push({intervals[tail][1], intervals[tail][1] - intervals[tail][0] + 1});
            tail++;
         }
         while (!PQ.empty() && PQ.top().tail < it.val)
         {
            PQ.pop();
         }
         if (PQ.empty())
         {
            it.len = -1;
         } else
         {
            it.len = PQ.top().len;
         }
      }
      vector<int> ret(qVec.size());
      for (auto &it : qVec)
      {
         ret[it.idx] = it.len;
      }
      return ret;
   }
};

int main()
{

}