#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int mi = nums[i];
            int ma = nums[i];
            for (int j = i + 1; j < n; j++) {
                mi = min(mi, nums[j]);
                ma = max(ma, nums[j]);
                sum += ma - mi;
            }
        }
        return sum;
    }
};