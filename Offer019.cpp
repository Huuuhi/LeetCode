//
// Created by 龚余 on 2023/3/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   bool check(const string &s, int left, int right)
   {
      string t = s.substr(left, right - left + 1);
      cout << t;
      string t_rev = t;
      reverse(t_rev.begin(), t_rev.end());
      if (t == t_rev)
         return true;
      return false;
   };
   bool validPalindrome(string s)
   {
      int left = 0, right = s.size() - 1;
      while (left < right)
      {
         if (s[left] == s[right])
         {
            left++;
            right--;
         } else
         {
            return check(s, left, right - 1) || check(s, left + 1, right);
         }
      }
      return true;
   }
};

int main()
{
   Solution so;
}