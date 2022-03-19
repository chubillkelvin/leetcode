#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int halveArray(vector<int> &nums) {
        double total = 0;
        priority_queue<double> q;
        for (int num: nums) {
            total += num;
            q.push(num);
        }
        int count = 0;
        double curr = total;
        while (curr > total / 2) {
            double num = q.top();
            q.pop();
            num /= 2;
            curr -= num;
            q.push(num);
            count++;
        }
        return count;
    }
};