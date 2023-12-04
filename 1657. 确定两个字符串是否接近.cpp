//
// Created by 龚余 on 2023/11/30.
//
#include<bits/stdc++.h>
/*
 * 仅仅可以依靠交换和改变次数实现word1->word2的转变，那么很容易想到如果：
 *    1. 两个word长度不一样，return false
 *    2. 如果两个字符串各个字符出现的次数一样，一定可以通过位置交换完成转变
 *    3. 如果两个字符串各个字符的词频经过排序以后一样，则可以通过操作2交换词频完成转变
 *    4. 如果两个字符串字符存在出入比如abc->cde，无法实现
 * */
class Solution
{
  public:
   bool closeStrings(string word1, string word2)
   {
      if (word1.size() != word2.size())
         return false;
      int mask1 = 0, mask2 = 0;
      vector<int> mk1(26), mk2(26);
      for (int i = 0; i < word1.size(); ++i)
      {
         mask1 |= 1 << (word1[i] - 'a');
         mk1[word1[i] - 'a']++;
         mask2 |= 1 << (word2[i] - 'a');
         mk2[word2[i] - 'a']++;
      }
      if (mask1 != mask2) return false;
      sort(mk1.begin(), mk1.end());
      sort(mk2.begin(), mk2.end());
      return mk1 == mk2;
   }
};