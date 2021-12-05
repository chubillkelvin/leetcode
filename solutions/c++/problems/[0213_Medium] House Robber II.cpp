#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob_linear(vector<int> &nums, int start, int end) {
        vector<vector<int>> value = vector<vector<int>>(nums.size(), {0, 0});
        value[start] = {0, nums[start]};
        for (int i = start + 1; i <= end; i++) {
            vector<int> prev = value[i - 1];
            value[i] = {max(prev[0], prev[1]), prev[0] + nums[i]};
        }
        vector<int> ending = value[end];
        return max(ending[0], ending[1]);
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(rob_linear(nums, 0, n - 2), rob_linear(nums, 1, n - 1));
    }
};