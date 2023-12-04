//
// Created by 龚余 on 2023/11/29.
//
#include <bits/stdc++.h>
/*
 * 现有一个包含所有正整数的集合 [1, 2, 3, 4, 5, ...] 。实现 SmallestInfiniteSet 类：
 *    SmallestInfiniteSet() 初始化 SmallestInfiniteSet 对象以包含 所有 正整数。
 *    int popSmallest() 移除 并返回该无限集中的最小整数。
 *    void addBack(int num) 如果正整数 num 不 存在于无限集中，则将一个 num 添加 到该无限集中。
 * Solution：所有正整数不太好保存，那么就保存被删掉的正整数，如果add时在被删掉的集合里则将集合里的该数删除，没有就无事发生，pop考虑记录被删除的边界值结合set判断
 * */
class SmallestInfiniteSet
{
  private:
   set<int> st;
   int threshold;
  public:
   SmallestInfiniteSet() : threshold(1)
   {

   }

   int popSmallest()
   {
      int popVal = threshold++;
      st.insert(popVal);
      while (st.find(threshold) != st.end())
         threshold++;
      return popVal;
   }

   void addBack(int num)
   {
      if (!st.count(num))
      {
         return;
      }
      st.erase(num);
      threshold = min(threshold, num);
   }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */