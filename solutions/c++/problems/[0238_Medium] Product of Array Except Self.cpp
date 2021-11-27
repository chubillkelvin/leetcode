#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int zeroCounts = count(nums.begin(), nums.end(), 0);
        if (zeroCounts >= 2) return vector<int>(nums.size(), 0);

        vector<int> prodRight = vector<int>(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            prodRight[i] = nums[i + 1] * prodRight[i + 1];
        }
        int prodLeft = 1;
        vector<int> ans = vector<int>(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) prodLeft *= nums[i - 1];
            ans[i] = prodLeft * prodRight[i];
        }
        return ans;
    }
};