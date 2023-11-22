//
// Created by 龚余 on 2023/4/3.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int> &arr) {
        /*
         * Solution:
         *      改变字典序，让目标字典序小于原序列同时在小于的序列中最大
         *      arr[1,2,3,4...i...j]让字典序变小，即arr[i],arr[j]交换位置后变小，即arr[i]>arr[j]，想让这种变化最小即尽量找到
         *      最右边的i，与小于arr[i]的最大值arr[j]进行交换
         * */
        int n=arr.size();
        for(int i=n-2;i>=0;--i){
            if(arr[i]>arr[i+1]){
                int j=n-1;
                while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
                    j--;
                }
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};

int main() {

}