//
// Created by 龚余 on 2023/11/28.
//
#include <bits/stdc++.h>

/*
 * Solution:
 *    1. 依靠两个双端队列加以规则, 两个队列分别命名为left&right
 *    2. pushFront: 若size right>left, right先pop_back到left_front一个，再push_front; else directly push_front
 *    3. pushBack: if size left=right, left pop_front >> right_back, -> push_back; else directly push_back (控制left不可能大于right，方便对中间元素处理）
 *    3. popFront: 先right pop_front, if right<left, left pop_front>> right push_back
 *    4. popBack: if left<right, left pop_back, right pop_back, left push_front;else left pop_back
 *    5. pushMiddle: 若size left=right, right push_back, else left push_front
 *    5. popMiddle: if size left=right, left pop_front , else right pop_back
 * */
class FrontMiddleBackQueue
{
  public:
   deque<int> left, right;
   FrontMiddleBackQueue()
   {};

   void pushFront(int val)
   {
      auto size_l = left.size(), size_r = right.size();
      if (size_l < size_r)
      {
         left.push_front(right.back());
         right.pop_back();
      }
      right.push_front(val);
   }

   void pushMiddle(int val)
   {
      auto size_l = left.size(), size_r = right.size();
      if (size_l == size_r)
      {
         right.push_back(val);
      } else
      {
         left.push_front(val);
      }
   }

   void pushBack(int val)
   {
      auto size_l = left.size(), size_r = right.size();
      if (size_l == size_r)
      {
         right.push_back(left.front());
         left.pop_front();
      }
      left.push_back(val);
   }

   int popFront()
   {
      auto size_l = left.size(), size_r = right.size();
      if (size_r == 0)
         return -1;
      if (size_l == size_r)
      {
         right.push_back(left.front());
         left.pop_front();
      }
      int val = right.front();
      right.pop_front();
      return val;
   }

   int popMiddle()
   {
      auto size_l = left.size(), size_r = right.size();
      if (size_r == 0)
         return -1;
      int val;
      if (size_l == size_r)
      {
         val = left.front();
         left.pop_front();
      } else
      {
         val = right.back();
         right.pop_back();
      }
      return val;
   }

   int popBack()
   {
      auto size_l = left.size(), size_r = right.size();
      if (size_r == 0)
         return -1;
      if (size_l < size_r)
      {
         left.push_front(right.back());
         right.pop_back();
      }
      int val = left.back();
      left.pop_back();
      return val;
   }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main()
{
   FrontMiddleBackQueue q;
   q.pushFront(1);   // [1]
   q.pushBack(2);    // [1, 2]
   q.pushMiddle(3);  // [1, 3, 2]
   q.pushMiddle(4);  // [1, 4, 3, 2]
   for (int i = 0; i < q.left.size(); i++)
   {
      auto t = q.left.back();
      q.left.pop_back();
      cout << t << " ";
   }
   cout << endl;
   for (int i = 0; i < q.right.size(); i++)
   {
      auto t = q.right.back();
      q.right.pop_back();
      cout << t << " ";
   }
   /*auto a = q.popFront();     // 返回 1 -> [4, 3, 2]
   auto b = q.popMiddle();    // 返回 3 -> [4, 2]
   auto c = q.popMiddle();    // 返回 4 -> [2]
   auto d = q.popBack();      // 返回 2 -> []
   auto f = q.popFront();     // 返回 -1 -> [] （队列为空）*/

}