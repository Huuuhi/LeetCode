//
// Created by 龚余 on 2023/3/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   int largestRectangleArea(vector<int> &heights)
   {
      stack<int> stk;
      int area = 0;
      stk.push(-1);
      for (int i = 0; i < heights.size(); ++i)
      {
         while (stk.top() != -1 && heights[stk.top()] >= heights[i])
         {
            int t = stk.top();
            stk.pop();
            area = max(area, heights[t] * (i - 1 - stk.top()));
         }
         stk.push(i);
      }
      /*处理栈中剩下的数据*/
      while (stk.top() != -1)
      {
         int t = stk.top();
         stk.pop();
         area = max(area, heights[t] * ((int) heights.size() - stk.top() - 1));
      }
      return area;
   }
};

int main()
{

}