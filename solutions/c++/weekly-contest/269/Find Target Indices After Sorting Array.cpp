#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans = {};
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) ans.push_back(i);
            if (target < nums[i]) break;
        }
        return ans;
    }
};