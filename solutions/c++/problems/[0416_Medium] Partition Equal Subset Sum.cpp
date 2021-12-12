#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int num: nums)sum += num;
        if (sum % 2 != 0) return false;
        int targetSum = sum / 2;
        vector<bool> ans = vector<bool>(targetSum + 1, false);
        ans[0] = true;
        for (int num: nums) {
            for (int i = targetSum; i >= num; i--) {
                ans[i] = ans[i] || ans[i - num];
            }
        }
        return ans[targetSum];
    }
};
