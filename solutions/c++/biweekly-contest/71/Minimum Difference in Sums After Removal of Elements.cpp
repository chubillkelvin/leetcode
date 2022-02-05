#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int> &nums) {
        int n = nums.size();
        int m = n / 3;
        long long sumL = 0;
        vector<long long> minL(n, 0);
        priority_queue<int> p1;
        long long sumR = 0;
        vector<long long> maxR(n, 0);
        priority_queue<int, vector<int>, greater<int>> p2;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            sumL += curr;
            p1.push(curr);
            if (p1.size() > m) {
                sumL -= p1.top();
                p1.pop();
            }
            minL[i] = sumL;
        }
        for (int i = 0; i < n; i++) {
            int curr = nums[n - 1 - i];
            sumR += curr;
            p2.push(curr);
            if (p2.size() > m) {
                sumR -= p2.top();
                p2.pop();
            }
            maxR[n - 1 - i] = sumR;
        }
        long long minDiff = LLONG_MAX;
        for (int i = m - 1; i < 2 * m; i++) {
            minDiff = min(minDiff, minL[i] - maxR[i + 1]);
        }
        return minDiff;
    }
};