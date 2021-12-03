#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int maxSoFar = nums[0];
        vector<vector<int>> ans = vector<vector<int>>(nums.size(), {1, 1});
        ans[0] = {nums[0], nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int prevMin = ans[i - 1][0];
            int prevMax = ans[i - 1][1];
            int currMin = min(min(curr, prevMin * curr), prevMax * curr);
            int currMax = max(max(curr, prevMin * curr), prevMax * curr);
            ans[i] = {currMin, currMax};
            maxSoFar = max(maxSoFar, currMax);
        }
        return maxSoFar;
    }
};