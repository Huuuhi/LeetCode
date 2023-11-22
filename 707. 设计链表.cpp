//
// Created by 龚余 on 2023/9/14.
//
#include "bits/stdc++.h"
using namespace std;
class MyLinkedList
{
 public:
  struct LinkNode
  {
    int val;
    LinkNode *next;
    LinkNode(int v) : val(v), next(nullptr)
    {}
    LinkNode() : val(0), next(nullptr)
    {}
  };
  MyLinkedList()
  {
    this->dummy = new LinkNode();
    this->_size = 0;
  }

  int get(int index)
  {
    if (index > (_size - 1) || index < 0) {
      return -1;
    }
    LinkNode *cur = dummy;
    int cnt = -1;
    while (cur && cnt < index)
    {
      cur = cur->next;
      cnt++;
    }
    return cur->val;
  }

  void addAtHead(int val)
  {
    LinkNode *node = new LinkNode(val);
    node->next = dummy->next;
    dummy->next = node;
    _size++;
  }

  void addAtTail(int val)
  {
    LinkNode *cur = dummy;
    while (cur->next)
    {
      cur = cur->next;
    }
    LinkNode *node = new LinkNode(val);
    cur->next = node;
    _size++;
  }

  void addAtIndex(int index, int val)
  {
    if (index > _size || index < 0)
      return;
    if (index == _size)
    {
      addAtTail(val);
      return;
    }
    LinkNode *cur = dummy;
    int cnt = -1;
    while (cnt < index - 1)
    {
      cur = cur->next;
      cnt++;
    }
    LinkNode *node = new LinkNode(val);
    node->next = cur->next;
    cur->next = node;
    _size++;
  }

  void deleteAtIndex(int index)
  {
    if (index >= _size || index < 0)
      return;
    int cnt = -1;
    LinkNode *cur = dummy;
    while (cnt < index - 1)
    {
      cur = cur->next;
      cnt++;
    }
    LinkNode *tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    tmp = nullptr;
    _size--;
  }
  // 打印链表
  void printLinkedList() {
    LinkNode* cur = dummy;
    while (cur->next != nullptr) {
      cout << cur->next->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }
 private:
  int _size;
  LinkNode *dummy;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
  MyLinkedList *myLinkedList = new MyLinkedList();
  myLinkedList->addAtHead(1);
  myLinkedList->printLinkedList();
  myLinkedList->addAtTail(3);
  myLinkedList->printLinkedList();
  myLinkedList->addAtIndex(1, 2);    // 链表变为 1->2->3
  myLinkedList->printLinkedList();

  cout<<endl<<myLinkedList->get(1)<<endl;              // 返回 2

  myLinkedList->deleteAtIndex(1);    // 现在，链表变为 1->3
  myLinkedList->printLinkedList();

  cout<<endl<<myLinkedList->get(1);              // 返回 3
}