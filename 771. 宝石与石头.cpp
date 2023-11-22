#include "bits/stdc++.h"
using namespace std;
/*class Solution
{
 public:
  int numJewelsInStones(string jewels, string stones)
  {
    unordered_map<char, int> num;
    for (char &c : stones)
    {
      num[c]++;
    }
    int ans = 0;
    for (char &c : jewels)
    {
      if (num.count(c))
        ans += num[c];
    }
    return ans;
  }
};*/
class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    // 把 jewels 转换成字符集合 mask
    long long mask = 0;
    for (char c: jewels)
      mask |= 1LL << (c & 63);
    // 统计有多少 stones[i] 在集合 mask 中
    int ans = 0;
    for (char c: stones)
      ans += mask >> (c & 63) & 1;
    return ans;
  }
};
