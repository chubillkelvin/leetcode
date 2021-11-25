#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        vector<int> mp = {nums[0]};
        for(int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int currEntry = max(curr, curr + mp[i-1]);
            mp.push_back(currEntry);
            maxSoFar = max(maxSoFar, currEntry);
        }
        return maxSoFar;
    }
};