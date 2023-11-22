//
// Created by 龚余 on 2023/6/25.
//
#include "bits/stdc++.h"
using namespace std;
class Solution
{
  long long distance(int ux, int uy, int vx, int vy)
  {
    return (long long) pow(ux - vx, 2) + (long long) pow(uy - vy, 2);
  }

 public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
  {
    /*圆心在矩形内部*/
    if (xCenter >= x1 && yCenter >= y1 && xCenter <= x2 && yCenter <= y2)
      return true;
    /*圆心在左矩形*/
    if (xCenter >= (x1 - radius) && xCenter <= x1 && yCenter >= y1 && yCenter <= y2)
      return true;
    /*圆心在右矩形*/
    if (xCenter >= x2 && xCenter <= (x2 + radius) && yCenter >= y1 && yCenter <= y2)
      return true;
    /*圆心在上矩形*/
    if (yCenter >= y2 && yCenter <= (y2 + radius) && xCenter >= x1 && xCenter <= x2)
      return true;
    /*圆心在下矩形*/
    if (yCenter >= (y1 - radius) && yCenter <= y1 && xCenter >= x1 && xCenter <= x2)
      return true;
    /*圆心在左上角圆，即计算圆心到左上角的距离小于等于r*/
    if (distance(xCenter, yCenter, x1, y2) <= radius * radius)
      return true;
    /* 矩形左下角 */
    if (distance(xCenter, yCenter, x1, y1) <= radius * radius)
    {
      return true;
    }
    /* 矩形右上角 */
    if (distance(xCenter, yCenter, x2, y2) <= radius * radius)
    {
      return true;
    }
    /* 矩形右下角 */
    if (distance(xCenter, yCenter, x1, y2) <= radius * radius)
    {
      return true;
    }
    return false;
  }
};
int main()
{

}