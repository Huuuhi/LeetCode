//
// Created by 龚余 on 2023/7/3.
//
#include"bits/stdc++.h"

using namespace std;

//  Definition for singly-linked list.
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    stack<int> s1, s2;
    ListNode *pos1 = l1, *pos2 = l2;
    while (pos1 != nullptr)
    {
      s1.push(pos1->val);
      pos1 = pos1->next;
    }
    while (pos2 != nullptr)
    {
      s2.push(pos2->val);
      pos2 = pos2->next;
    }
    int carry = 0;
    ListNode *dummy = new ListNode();
    while (!s1.empty() || !s2.empty() || carry)
    {
      int a = s1.empty() ? 0 : s1.top();
      int b = s2.empty() ? 0 : s2.top();
      if (!s1.empty())s1.pop();
      if (!s2.empty())s2.pop();
      auto *node = new ListNode((a + b + carry) % 10);
      node->next = dummy->next;
      dummy->next = node;
      carry = (a + b + carry) / 10;
    }
    return dummy->next;
  }
};
int main()
{

}