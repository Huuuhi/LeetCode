//
// Created by 龚余 on 2023/5/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  public:
   string oddString(vector<string> &words)
   {
      vector<int> diff0 = get(words[0]);
      vector<int> diff1 = get(words[1]);
      if (diff0 == diff1)
      {
         for (int i = 2; i < words.size(); ++i)
         {
            vector<int> diff = get(words[i]);
            if (diff != diff0)
               return words[i];
         }
      }
      return get(words[2]) == diff0 ? words[1] : words[0];
   }
   vector<int> get(string &str)
   {
      vector<int> diff;
      for (int i = 1; i < str.size(); ++i)
      {
         diff.push_back(str[i] - '0' - (str[i - 1]) - '0');
      }
      return diff;
   }
};

int main()
{

}