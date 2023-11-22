//
// Created by 龚余 on 2023/3/11.
//
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
   ListNode *reverseList(ListNode *head)
   {
      ListNode *dummy = new ListNode();
      while (head)
      {
         ListNode *t = head->next;
         head->next = dummy->next;
         dummy->next = head;
         head = t;
      }
      return dummy->next;
   }
};

int main()
{

}