//
// Created by 龚余 on 2023/6/27.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    auto greaterthan =
        [&nums1, &nums2](pair<int, int> a, pair<int, int> b) -> bool {
          return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greaterthan)> que(greaterthan);
    int m = nums1.size(), n = nums2.size();
    que.emplace(0, 0);
    vector<vector<int>> res;
    while (k-- && !que.empty())
    {
      auto [i, j] = que.top();
      que.pop();
      res.emplace_back(initializer_list<int>{nums1[i], nums2[j]});
      if (j == 0 && i + 1 < m)
        que.emplace(i + 1, 0);
      if (j + 1 < n)
        que.emplace(i, j + 1);
    }
    return res;
  }
};

int main()
{

}