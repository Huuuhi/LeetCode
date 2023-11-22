//
// Created by 龚余 on 2023/3/10.
//
#include "bits/stdc++.h"

using namespace std;

//Definition for singly-linked list.
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
   ListNode *removeNthFromEnd(ListNode *head, int n)
   {
      ListNode *dummy = new ListNode(0, head);
      ListNode *first = head;
      ListNode *second = dummy;
      for (int i = 0; i < n; i++)
         first = first->next;
      while (first)
      {
         first = first->next;
         second = second->next;
      }
      second->next = second->next->next;
      delete dummy;
      return head;
   }
};

int main()
{

}