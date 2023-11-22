//
// Created by 龚余 on 2023/11/9.
//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
   constexpr static int INF = 1e9;
   constexpr static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  public:
   int maximumMinutes(vector<vector<int>> &grid)
   {
      int m = grid.size(), n = grid[0].size();
      vector<vector<int>> fireTime(m, vector<int>(n, INF));
      genFireTime(grid, fireTime);
      int ans = -1;
      int low = 0, high = m * n;
      while (low <= high)
      {
         int mid = (low + high) / 2;
         if (check(mid, grid, fireTime))
         {
            ans = mid;
            low = mid + 1;
         } else
            high = mid - 1;
      }
      return ans >= m * n ? 1e9 : ans;
   }
   bool check(int mid, vector<vector<int>> &grid, vector<vector<int>> &fireTime)
   {
      int m = grid.size(), n = grid[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      queue<tuple<int, int, int>> q;
      q.emplace(0, 0, mid);
      visited[0][0] = true;
      while (!q.empty())
      {
         auto [x, y, t] = q.front();
         q.pop();
         for (auto &dir : dirs)
         {
            auto nx = x + dir[0];
            auto ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
               if (visited[nx][ny] || grid[nx][ny])
                  continue;
               if (nx == m - 1 && ny == n - 1)
                  return fireTime[m - 1][n - 1] >= t + 1;
               if (fireTime[nx][ny] > t + 1)
               {
                  q.emplace(nx, ny, t + 1);
                  visited[nx][ny] = true;
               }
            }
         }
      }
      return false;
   }
   void genFireTime(vector<vector<int>> &grid, vector<vector<int>> &fireTime)
   {
      int m = grid.size(), n = grid[0].size();
      queue<pair<int, int>> q;
      for (int i = 0; i < m; ++i)
      {
         for (int j = 0; j < n; ++j)
         {
            if (grid[i][j] == 1)
            {
               q.emplace(i, j);
               fireTime[i][j] = 0;
            }
         }
      }
      int time = 1;
      while (!q.empty())
      {
         auto sz = q.size();
         for (int i = 0; i < sz; ++i)
         {
            auto [x, y] = q.front();
            q.pop();
            for (auto dir : dirs)
            {
               auto nx = x + dir[0];
               auto ny = y + dir[1];
               if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
//                  if (grid[nx][ny] == 2 || fireTime[nx][ny] != INF) {
//                     continue;
//                  }
                  if (grid[nx][ny] == 0 && fireTime[nx][ny] == INF) {
                     q.emplace(nx, ny);
                     fireTime[nx][ny] = time;
                  }
               }
            }
         }
         time++;
      }
   }
};

int main()
{

}