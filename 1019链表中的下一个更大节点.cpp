//
// Created by 龚余 on 2023/4/10.
//
#include "bits/stdc++.h"

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        stack<pair<int, int>> s;
        ListNode *cur = head;
        int idx = -1;
        vector<int> ans;
        while (cur) {
            idx++;
            ans.push_back(0);
            while (!s.empty() && s.top().first < cur->val) {
                ans[s.top().second] = cur->val;
                s.pop();
            }
            s.emplace(cur->val, idx);
            cur = cur->next;
        }
        return ans;
    }
};

int main() {

}