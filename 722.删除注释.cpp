//
// Created by 龚余 on 2023/8/3.
//
#include "bits/stdc++.h"
using namespace std;

class Solution
{
 public:
  vector<string> removeComments(vector<string> &source)
  {
    bool inBlock = false;
    vector<string> ans;
    string newLine;
    for (auto &line : source)
    {
      int n = line.size();
      for (int i = 0; i < n; ++i)
      {
        if (inBlock)
        {
          if (i + 1 < n && line[i] == '*' && line[i + 1] == '/')
          {
            inBlock = false;
            i++;
          }
        } else
        {
          if (i + 1 < n && line[i] == '/' && line[i + 1] == '*')
          {
            inBlock = true;
            i++;
          } else if (i + 1 < n && line[i] == '/' && line[i + 1] == '/')
            break;
          else
            newLine += line[i];
        }
      }
      if (!newLine.empty()&&!inBlock){
        ans.emplace_back(newLine);
        newLine="";
      }
    }
    return ans;
  }
};

int main()
{

}