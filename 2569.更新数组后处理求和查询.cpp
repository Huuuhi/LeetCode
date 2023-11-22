//
// Created by 龚余 on 2023/7/26.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
  private:
   static constexpr int MX = 4e5 + 1;
   int cnt[MX];
   bool flip[MX];
   // 维护当前节点1的个数
   void maintain(int o)
   {
      cnt[o] = cnt[o * 2] + cnt[o * 2 + 1];
   }
   // 初始化线段树
   void build(vector<int> &a, int o, int l, int r)
   {
      if (l == r)
      {
         cnt[o] = a[l - 1];
         return;
      }
      int m = (l + r) / 2;
      build(a, o * 2, l, m);
      build(a, o * 2 + 1, m + 1, r);
      maintain(o);
   }
   // 区间反转
   void do_(int o, int l, int r)
   {
      cnt[o] = r - l + 1 - cnt[o];
      flip[o] = !flip[o];
   }
   // 反转区间[L,R] o,l,r=1,1,n
   void update(int o, int l, int r, int L, int R)
   {
      if (L <= l && r <= R)
      {
         do_(o, l, r);
         return;
      }
      int m = (l + r) / 2;
      if (flip[o])
      {
         do_(o * 2, l, m);
         do_(o * 2 + 1, m + 1, r);
         flip[o] = false;
      }
      if (m >= L)
      {
         update(o * 2, l, m, L, R);
      }
      if (m < R)
      {
         update(o * 2 + 1, m + 1, r, L, R);
      }
      maintain(o);
   }
  public:
   vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
   {
      int n = nums1.size();
      build(nums1, 1, 1, n);
      vector<long long> ans;
      long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
      for (auto &q : queries)
      {
         if (q[0] == 1)
            update(1, 1, n, q[1] + 1, q[2] + 1);
         else if (q[0] == 2)
            sum += 1LL * q[1] * cnt[1];
         else
            ans.push_back(sum);
      }
      return ans;
   }
};

int main()
{

}