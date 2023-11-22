#include "bits/stdc++.h"
class Solution
{
 public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
  {
    vector<vector<int>> g(numCourses);
    vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
    vector<int> degree(numCourses, 0);
    for (auto &edge : prerequisites)
    {
      degree[edge[1]]++;
      g[edge[0]].push_back(edge[1]);
      isPre[edge[0]][edge[1]] = true;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (degree[i] == 0)
        q.push(i);
    while (!q.empty())
    {
      int t = q.front();
      q.pop();
      for (auto &e : g[t])
      {
        isPre[t][e] = true;
        for (int i = 0; i < numCourses; ++i)
        {
          isPre[i][e] = isPre[i][e] | isPre[i][t];
        }
        degree[e]--;
        if (degree[e] == 0)
          q.push(e);
      }
    }
    vector<bool> ans;
    for (auto &query : queries)
    {
      ans.push_back(isPre[query[0]][query[1]]);
    }
    return ans;
  }
};