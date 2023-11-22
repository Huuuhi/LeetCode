//
// Created by 龚余 on 2023/6/30.
//
#include "bits/stdc++.h"
class Solution
{
  public:
   bool isCircularSentence(string sentence)
   {
      if (sentence[0] != sentence.back())
         return false;
      for (int i = 0; i < sentence.size(); ++i)
      {
         if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
            return false;
      }
      return true;
   }
};
