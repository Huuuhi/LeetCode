//
// Created by 龚余 on 2023/11/13.
//
#include <bits/stdc++.h>

class NumArray
{
  private:
   vector<int> segmentTree;
   int n;
   void build(int node, int s, int e, vector<int> &nums)
   {
      if (s == e)
      {
         segmentTree[node] = nums[s];
         return;
      }
      auto m = s + ((e - s) >> 1);
      build(node * 2 + 1, s, m, nums);
      build(node * 2 + 2, m + 1, e, nums);
      segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
   }
   void change(int index, int val, int node, int s, int e)
   {
      if (s == e)
      {
         segmentTree[node] = val;
         return;
      }
      auto m = s + ((e - s) >> 1);
      if (index <= m)
      {
         change(index, val, node * 2 + 1, s, m);
      } else
      {
         change(index, val, node * 2 + 2, m + 1, e);
      }
      segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
   }
   int query(int left, int right, int node, int s, int e)
   {
      if (left == s && right == e)
      {
         return segmentTree[node];
      }
      auto m = s + ((e - s) >> 1);
      if (right <= m)
         return query(left, right, node * 2 + 1, s, m);
      else if (left >= m)
         return query(left, right, node * 2 + 2, m + 1, e);
      else
         return query(left, m, node * 2 + 1, s, m) + query(m + 1, right, node * 2 + 2, m + 1, e);
   }
  public:
   NumArray(vector<int> &nums) : n(nums.size()), segmentTree(nums.size() * 4)
   {
      build(0, 0, n - 1, nums);
   }

   void update(int index, int val)
   {
      change(index, val, 0, 0, n - 1);
   }

   int sumRange(int left, int right)
   {
      return query(left, right, 0, 0, n - 1);
   }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */