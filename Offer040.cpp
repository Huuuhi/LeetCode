//
// Created by 龚余 on 2023/3/27.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int maximalRectangle(vector<string> &matrix)
   {
      int m = matrix.size();
      if (m == 0)
         return 0;
      int n = matrix[0].size();
      vector<vector<int>> left(m, vector<int>(n));
      for (int i = 0; i < m; ++i)
      {
         for (int j = 0; j < n; ++j)
         {
            left[i][j] = (matrix[i][j] == '0' ? 0 : (j == 0 ? 1 : 1 + left[i][j - 1]));
            cout << left[i][j] << " ";
         }
         cout << endl;
      }

      int ret = 0;
      for (int j = 0; j < n; ++j)
      {
         stack<int> stk;
         stk.push(-1);
         for (int i = 0; i < m; i++)
         {
            while (stk.top() != -1 && left[stk.top()][j] >= left[i][j])
            {
               int t = stk.top();
               stk.pop();
               ret = max(ret, left[t][j] * (i - 1 - stk.top()));
            }
            stk.push(i);
         }
         while (stk.top() != -1)
         {
            int t = stk.top();
            stk.pop();
            ret = max(ret, left[t][j] * (m - stk.top() - 1));
         }
      }
      return ret;
   }
};

int main()
{

}
