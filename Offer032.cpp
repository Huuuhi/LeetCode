//
// Created by 龚余 on 2023/3/16.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   bool isAnagram(string s, string t)
   {
      if (s.length() != t.length() || s == t)
         return false;
      vector<int> a(26);
      int n = s.length();
      for (auto item : s)
      {
         a[item - 'a']++;
      }
      for (auto item : t)
      {
         if (--a[item - 'a'] < 0)
            return false;
      }
      return true;
   }
};

int main()
{

}