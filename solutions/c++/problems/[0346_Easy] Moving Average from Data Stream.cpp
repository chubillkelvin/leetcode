#include <bits/stdc++.h>

using namespace std;

class MovingAverage {
private:
    int windowSize;
    int count = 0;
    queue<int> numbers = {};
public:
    MovingAverage(int size) {
        windowSize = size;
    }

    double next(int val) {
        numbers.push(val);
        if (numbers.size() > windowSize) numbers.pop();
        queue<int> copy = numbers;
        int total = 0;
        while (!copy.empty()) {
            total += copy.front();
            copy.pop();
        }
        return (double) total / (double) numbers.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */