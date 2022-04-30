#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int> &nums) {
        long long n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (long long i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        long long minDiff = LONG_LONG_MAX;
        long long minIdx = n;
        for (long long i = 0; i < n; i++) {
            long long pre = prefix[i] / (i + 1);
            long long post = i == n - 1 ? 0 : (prefix[n - 1] - prefix[i]) / (n - i - 1);
            long long diff = abs(pre - post);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }
        return minIdx;
    }
};