//
// Created by 龚余 on 2023/6/29.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
 public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
  {
    int n = colsum.size();
    bool flag = false;
    vector<int> cnt(2, 0);
    cnt[0] = upper, cnt[1] = lower;
    vector<vector<int>> res(2, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
      if (colsum[i] == 0)
        continue;
      if (colsum[i] == 1)
      {
        int j = cnt[0] >= cnt[1] ? 0 : 1;
        cout << j << endl;
        if (cnt[j] > 0)
        {
          res[j][i] = 1;
          cnt[j]--;
        } else if (cnt[(j + 1) % 2] > 0)
        {
          res[(j + 1) % 2][i] = 1;
          cnt[(j + 1) % 2]++;
        } else
          return {};
      } else
      {
        if ((cnt[0] > 0) && (cnt[1] > 0))
        {
          res[0][i] = 1;
          cnt[0]--;
          res[1][i] = 1;
          cnt[1]--;
        } else
        {
          return {};
        }
      }
    }
    if(cnt[0]==0&&cnt[1]==0)
      return res;
    return {};
  }
};
int main()
{
  int upper = 4, lower = 7;
  vector<int> colsum{2,1,2,2,1,1,1};
  Solution so;
  auto rst = so.reconstructMatrix(upper, lower, colsum);
  for (auto &row : rst)
  {
    for (auto &i : row)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}