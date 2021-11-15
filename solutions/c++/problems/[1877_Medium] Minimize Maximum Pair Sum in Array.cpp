#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int> &nums) {
        if (nums.size() == 2) return nums[0] + nums[1];

        sort(nums.begin(), nums.end());
        int maxFound = nums[0] + nums[nums.size() - 1];
        for (int i = 1; i < nums.size() / 2; i++) {
            maxFound = max(maxFound, nums[i] + nums[nums.size() - i - 1]);
        }
        return maxFound;
    }

};