//
// Created by 龚余 on 2023/4/11.
//
#include "bits/stdc++.h"

using namespace std;

class Solution
{
  private:
   static constexpr int SEG_COUNT = 4;
   vector<string> ans;
   vector<int> segments;
  public:
   void dfs(string &s, int segId, int segStart)
   {
      if (segId == SEG_COUNT)
      {
         if (segStart == s.size())
         {
            string ipAddr;
            for (int i = 0; i < SEG_COUNT; ++i)
            {
               ipAddr += to_string(segments[i]);
               if (i != SEG_COUNT - 1)
                  ipAddr += '.';
            }
            ans.push_back(ipAddr);
         }
         return;
      }
      if (segStart == s.size())
         return;
      // 前导0
      if (s[segStart] == '0')
      {
         segments[segId] = 0;
         dfs(s, segId + 1, segStart + 1);
      }
      int addr = 0;
      for (int segEnd = segStart; segEnd < s.size(); ++segEnd)
      {
         addr = addr * 10 + (s[segEnd] - '0');
         if (addr > 0 && addr <= 255)
         {
            segments[segId] = addr;
            dfs(s, segId + 1, segEnd + 1);
         } else
            break;
      }
   }

   vector<string> restoreIpAddresses(string s)
   {
      segments.resize(SEG_COUNT);
      dfs(s, 0, 0);
      return ans;
   }
};

int main()
{

}