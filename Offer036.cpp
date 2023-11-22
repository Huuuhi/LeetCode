//
// Created by 龚余 on 2023/3/21.
//
#include "bits/stdc++.h"
using namespace std;

/*
 * 逆波兰表示法：即后缀表示法
 * */
class Solution
{
  private:

  public:
   static bool isNum(string &str)
   {
      bool flag = false;
      auto i = str.begin();
//        if( str[0]=='-')
//            i++;
      for_each(i, str.end(), [&flag](char c) { flag = flag || isdigit(c); });
      return flag;
   };
   int evalRPN(vector<string> &tokens)
   {
      stack<int> dgS;
      for (auto &token : tokens)
      {
         if (isNum(token))
         {
            dgS.push(stoi(token));
         } else
         {
            int num2 = dgS.top();
            dgS.pop();
            int num1 = dgS.top();
            dgS.pop();
            switch (token[0])
            {
               case '+':dgS.push(num1 + num2);
                  break;
               case '-':dgS.push(num1 - num2);
                  break;
               case '*':dgS.push(num1 * num2);
                  break;
               case '/':dgS.push(num1 / num2);
                  break;
            }
         }
      }
      return dgS.top();
   }
};

int main()
{
   Solution so;
   string s = "-";
   cout << so.isNum(s);
}