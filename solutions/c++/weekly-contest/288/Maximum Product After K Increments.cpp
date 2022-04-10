#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums, int k) {
        int MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<>> q;
        for (int num: nums) q.push(num);
        while (k > 0) {
            int top = q.top();
            q.pop();
            q.push(top + 1);
            k--;
        }
        long long prod = 1;
        while (!q.empty()) {
            prod *= q.top();
            prod %= MOD;
            q.pop();
        }
        return prod;
    }
};