#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int n = nums.size();
        int maxNum = nums[0];
        int curr = 1;
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == maxNum && nums[i] == nums[i - 1]) {
                curr++;
                maxLen = max(maxLen, curr);
            } else {
                if (nums[i] > maxNum) {
                    maxNum = nums[i];
                    maxLen = 1;
                }
                curr = 1;
            }
        }
        return maxLen;
    }
};