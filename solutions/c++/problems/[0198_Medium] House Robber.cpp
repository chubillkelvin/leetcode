#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return nums[0];

        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>{0, 0});
        // base cases
        ans[0][0] = 0;
        ans[0][1] = nums[0]; // break into house 0
        ans[1][0] = ans[0][1];
        ans[1][1] = nums[1]; // break into house 1
        for (int i = 2; i < n; i++) {
            int curr = nums[i];
            ans[i][0] = max(ans[i - 1][0], ans[i - 1][1]);
            ans[i][1] = ans[i - 1][0] + curr;
        }

        vector<int> lastItem = ans[n - 1];
        return max(lastItem[0], lastItem[1]);
    }
};