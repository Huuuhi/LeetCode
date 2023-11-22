#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   bool isPalindrome(const string &s)
   {
      int n = s.size();
      int left = 0, right = n - 1;
      while (left < right)
      {
         while (left < right && !isalnum(s[left]))
            left++;
         while (left < right && !isalnum(s[right]))
            right--;
         if (left < right)
         {
            if (toupper(s[left]) != toupper(s[right]))
               return false;
         }
         ++left;
         --right;
      }
      return true;
   }
};

int main()
{

}