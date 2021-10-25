#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void twoSum(vector<vector<int>> &ans, vector<int> &nums, int checkIndex) {
        int startIndex = checkIndex + 1;
        int endIndex = nums.size() - 1;
        while (startIndex < endIndex) {
            int sum = nums[checkIndex] + nums[startIndex] + nums[endIndex];
            if (sum == 0) {
                ans.push_back({nums[checkIndex], nums[startIndex], nums[endIndex]});
                do {
                    startIndex++;
                } while (nums[startIndex] == nums[startIndex - 1] && startIndex < endIndex);
                endIndex--;
            } else if (sum > 0) {
                endIndex--;
            } else {
                startIndex++;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans = {};
        if (nums.size() >= 3) {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                twoSum(ans, nums, i);
            }
        }
        return ans;
    }
};