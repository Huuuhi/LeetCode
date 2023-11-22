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
   ListNode *detectCycle(ListNode *head)
   {
      unordered_set<ListNode *> visited;
      ListNode *pos = head;
      while (pos)
      {
         if (visited.count(pos))
            return pos;
         visited.insert(pos);
         pos = pos->next;
      }
      return nullptr;
   }
};