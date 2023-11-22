//
// Created by 龚余 on 2023/3/13.
//
#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode
{
   int val;
   ListNode *next;

   ListNode() : val(0), next(nullptr)
   {}

   ListNode(int x) : val(x), next(nullptr)
   {}

   ListNode(int x, ListNode *next) : val(x), next(next)
   {}
};

class Solution
{
  public:
   void reorderList(ListNode *head)
   {
      if (head == nullptr)
      {
         return;
      }
      vector<ListNode *> v;
      ListNode *pos = head;
      while (pos)
      {
         v.emplace_back(pos);
         pos = pos->next;
      }
      int i = 0, j = v.size() - 1;
      while (i < j)
      {
         v[i]->next = v[j];
         i++;
         if (i == j)
            break;
         v[j]->next = v[i];
         j--;
      }
      v[i]->next = nullptr;
   }
};