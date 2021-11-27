#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int zeroCounts = count(nums.begin(), nums.end(), 0);
        if (zeroCounts >= 2) return vector<int>(nums.size(), 0);

        int prod = 1;
        for (int num: nums) {
            if (num != 0) prod *= num;
        }
        vector<int> ans = {};
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            if (curr == 0) {
                ans.push_back(prod);
            } else if (zeroCounts == 1) {
                ans.push_back(0);
            } else {
                ans.push_back(prod / curr);
            }

        }
        return ans;
    }
};