#include "bits/stdc++.h"

std::vector<int> &&return_vector(void)
{
   std::vector<int> tmp{1, 2, 3, 4, 5};
   return std::move(tmp);
}

int main()
{
   std::vector<int> &&rval_ref = return_vector();
   // 使用 rval_ref
   return 0;
}

t> &&
rval_ref = return_vecto2();