//
// Created by 龚余 on 2023/3/10.
//
#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
   int val;
   ListNode *next;

   ListNode(int x) : val(x), next(NULL)
   {}
};

class Solution
{
  public:
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
   {
      int m = 0, n = 0;
      ListNode *p1 = headA, *p2 = headB;
      while (p1)
      {
         p1 = p1->next;
         m++;
      }
      while (p2)
      {
         p2 = p2->next;
         n++;
      }
      p1 = headA, p2 = headB;
      if (m > n)
      {
         int t = m - n;
         while (t--)
            p1 = p1->next;
      } else if (m < n)
      {
         int t = n - m;
         while (t--)
            p2 = p2->next;
      }
      while (p1 && p2)
      {
         if (p1 == p2)
            return p1;
         p1 = p1->next;
         p2 = p2->next;
      }
      return nullptr;
   }
};