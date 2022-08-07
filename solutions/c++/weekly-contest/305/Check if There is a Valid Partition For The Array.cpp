#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> nums;
    unordered_map<int, unordered_map<int, bool>> memo;
public:
    bool isValid(int left, int right) {
        if (memo.count(left) && memo[left].count(right)) return memo[left][right];
        int m = right - left + 1;
        if (m == 1) return false;
        if (m == 2) {
            if (nums[left] == nums[left + 1]) return memo[left][right] = true;
            return memo[left][right] = false;
        }
        if (m == 3) {
            if (nums[left] == nums[left + 1] && nums[left + 1] == nums[left + 2]) return memo[left][right] = true;
            if (nums[left + 2] - nums[left + 1] == 1 && nums[left + 1] - nums[left + 0] == 1)
                return memo[left][right] = true;
            return memo[left][right] = false;
        }
        if (isValid(left, left + 1) && isValid(left + 2, n - 1)) return memo[left][right] = true;
        return memo[left][right] = isValid(left, left + 2) && isValid(left + 3, n - 1);
    }

    bool validPartition(vector<int> &nums) {
        n = nums.size();
        this->nums = nums;
        return isValid(0, n - 1);
    }
};