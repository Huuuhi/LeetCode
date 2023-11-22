//
// Created by 龚余 on 2023/3/30.
//
#include "bits/stdc++.h"

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
    }

    double next(int val) {
        if (q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        q.emplace(val);
        sum += val;
        return sum / q.size();
    }

private:
    queue<int> q;
    int size;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
int main() {

}