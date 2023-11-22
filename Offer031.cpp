//
// Created by 龚余 on 2023/3/16.
//
#include "bits/stdc++.h"
using namespace std;

struct DLinkedNode
{
   int key, value;
   DLinkedNode *next;
   DLinkedNode *prev;

   DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr)
   {}

   DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr)
   {}
};

class LRUCache
{
  private:
   DLinkedNode *head;
   DLinkedNode *tail;
   unordered_map<int, DLinkedNode *> cache;
   int size;
   int capacity;

   void moveToHead(DLinkedNode *node)
   {
      removeNode(node);
      addToHead(node);
   };

   void addToHead(DLinkedNode *node)
   {
      node->next = head->next;
      head->next->prev = node;
      head->next = node;
      node->prev = head;
   };

   void removeNode(DLinkedNode *node)
   {
      node->prev->next = node->next;
      node->next->prev = node->prev;
   };

   void removeTail()
   {
      DLinkedNode *t_tail = tail->prev;
      removeNode(t_tail);
      // 释放掉tail；
      cache.erase(t_tail->key);
      delete t_tail;
   }

  public:
   LRUCache(int capacity)
   {
      this->capacity = capacity;
      this->size = 0;
      head = new DLinkedNode();
      tail = new DLinkedNode();
      head->next = tail;
      tail->prev = head;
   }

   int get(int key)
   {
      if (!cache.count(key))
         return -1;
      DLinkedNode *node = cache[key];
      moveToHead(node);
      return node->value;
   }

   void put(int key, int value)
   {
      if (cache.count(key))
      {
         DLinkedNode *node = cache[key];
         node->value = value;
         moveToHead(node);
         return;
      }
      auto *node = new DLinkedNode(key, value);
      addToHead(node);
      cache[key] = node;
      if (++size > capacity)
      {
         removeTail();
         --size;
      }
   }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */