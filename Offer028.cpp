//
// Created by 龚余 on 2023/3/14.
//
#include "bits/stdc++.h"
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Node
{
  public:
   int val;
   Node *prev;
   Node *next;
   Node *child;
};
class Solution
{
  public:
   Node *flatten(Node *head)
   {
      function<Node *(Node *)> dfs = [&](Node *node) {
         Node *cur = node;
         Node *last = nullptr;
         while (cur)
         {
            Node *next = cur->next;
            if (cur->child)
            {
               Node *child_last = dfs(cur->child);
               next = cur->next;
               cur->next = cur->child;
               cur->child->prev = cur;
               if (next)
               {
                  child_last->next = next;
                  next->prev = child_last;
               }
               cur->child = nullptr;
               last = child_last;
            } else
            {
               last = cur;
            }
            cur = cur->next;
         }
         return last;
      };
      dfs(head);
      return head;
   }
};

int main()
{

}