#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<>> q;
        int maxNum = 0;
        for (int num: nums) {
            if (num == 0) continue;
            q.push(num);
            maxNum = max(maxNum, num);
        }
        int total = 0;
        int count = 0;
        while (!q.empty() && maxNum > 0) {
            int curr = q.top() - total;
            q.pop();
            if (curr <= 0) continue;
            maxNum -= curr;
            total += curr;
            count++;
        }
        return count;
    }
};