//
// Created by 龚余 on 2023/4/25.
//
#include "bits/stdc++.h"
using namespace std;
#include <cstdlib>
class Solution
{
  public:
   vector<string> sortPeople(vector<string> &names, vector<int> &heights)
   {
      int n = names.size();
      vector<int> indices(n);
      sort(indices.begin(), indices.end(), [&](int x, int y) {
         return heights[x] > heights[y];
      });
      vector<string> ans(n);
      for (int i = 0; i < n; ++i)
      {
         ans[i] = names[indices[i]];
      }
      return ans;
   }
};

int main()
{
   int n = 3;
   vector<int> indices(n);
   iota(indices.begin(), indices.end(), 0);
   for (auto i : indices)
      cout << i << " ";
}