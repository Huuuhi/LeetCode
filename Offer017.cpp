#include "bits/stdc++.h"
using namespace std;

class Solution
{
  public:
   string minWindow(string s, string t)
   {
      /*  */
      int lenS = s.length(), lenT = t.length();
      if (lenT > lenS)
         return "";
      vector<pair<char, int>> s_p;
      unordered_map<char, int> mp;
      for (int i = 0; i < lenT; i++)
         mp[t[i]]++;
      for (int i = 0; i < lenS; i++)
      {
         if (mp.count(s[i]))
            s_p.emplace_back(s[i], i);
      }
      unordered_map<char, int> wd;
      int ftIdx = 0, ltIdx = 0;
      for (int i = 0; i < lenT; i++)
      {
         wd[s_p[i].first]++;
      }
      if (wd == mp)
      {
         ftIdx = s_p[0].second;
         ltIdx = s_p[lenT - 1].second;
      }
      for (int i = lenT; i < lenS; i++)
      {
         wd[s_p[i - lenT].first]--;
         wd[s_p[i].first]++;
         if (wd == mp)
         {
            int t1 = s_p[i - lenT + 1].second;
            int t2 = s_p[i].second;
            if (t2 - t1 < ltIdx - ftIdx)
            {
               ftIdx = t1;
               ltIdx = t2;
            }
         }
      }
      string ans;
      for (int i = ftIdx; i <= ltIdx; i++)
         ans += s[i];
      return ans;
   }
};

int main()
{
   Solution so;
   string s = "A", t = "A";
   cout << so.minWindow(s, t);
}