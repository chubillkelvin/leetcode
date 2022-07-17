#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, priority_queue<int>> q;
        for (int i = 0; i < n; i++) {
            string num = to_string(nums[i]);
            int total = 0;
            for (char c: num) {
                total += (c - '0');
            }
            q[total].push(nums[i]);
        }
        int maxSum = -1;
        for (auto p: q) {
            if (p.second.size() > 1) {
                int top = p.second.top();
                p.second.pop();
                int top2 = p.second.top();
                maxSum = max(maxSum, top + top2);
            }
        }
        return maxSum;
    }
};