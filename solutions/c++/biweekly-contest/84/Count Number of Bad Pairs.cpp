#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getArithmeticSum(long long n) {
        return n * (n - 1) / 2;
    }

    long long countBadPairs(vector<int> &nums) {
        int n = nums.size();
        long long count = getArithmeticSum(n);
        unordered_map<int, int> counts;
        for (int i = 0; i < n; i++) counts[nums[i] - i]++;
        for (auto p: counts) count -= getArithmeticSum(p.second);
        return count;
    }
};