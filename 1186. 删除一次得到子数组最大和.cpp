//
// Created by 龚余 on 2023/6/27.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  int maximumSum(vector<int> &arr)
  {
    /*
     * 问题：求的是子数组中最大的存在（最多可以进行一次删除操作）
     * 思考：
     * 1. 朴素的思维：列举数组的子数组，即列举左右边界i,j，然后考虑列举k(i<=k<=j),最后计算出最大值
     * 2. 思考用递归的思想，假设元素和最大连续子数组有断电为r，原问题即子数组右端点为r，且至多删除一个数，子数组元素和最长为，转换为两个问题
     *    其一：子数组右端点为r，且不能删除一个数字，它的最大元素和是？
     *        如果不选r左边的数，它的最长元素即{r}
     *        如果选r左边的数l，它的问题变为：子数组右端点数为l，且不能删除数字，子数组最大元素和是
     *    其二：子数组右端点为r，且必须删除一个数字，它的最大元素和是？
     *        如果不选r左边的数，且必须删除，则不成立，不考虑这种情况
     *        若果选左边的数l，它的问题变为：
     *            子数组右端点为l，且必须删除一个数，其最长元素和是
     *            子数组右端点为l，且不能删除数字，。。。
     *
     * 状态转移方程：
     *      dfs[i][0]=max{dfs[i-1][0],0}+arr[i]
     *      dfs[i][1]=max{dfs[i-1][0],dfs[i-1][1]+arr[i]}
     *
     *      f[i+1,0]=max{f[i][0],0)+arr[i]
     *      f[i+1,1]=max{f[i][0],f[i][1]+arr[i]}
     * */
    int n = arr.size(), ans = INT_MIN;
    vector<vector<int>> f(n + 1, vector<int>(2, INT_MIN / 2));
    for (int i = 0; i < n; ++i)
    {
      f[i + 1][0] = max(f[i][0], 0) + arr[i];
      f[i + 1][1] = max(f[i][1] + arr[i], f[i][0]);
      ans = max(ans, max(f[i + 1][0], f[i + 1][1]));
    }
    return ans;
  }
};

int main(){

}