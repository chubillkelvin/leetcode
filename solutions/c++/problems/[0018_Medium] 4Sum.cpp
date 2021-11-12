#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        long long realTarget = target;
        vector<vector<int>> ans = {};
        if (nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            int num1 = nums[i];
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int num2 = nums[j];
                int startIndex = j + 1;
                int endIndex = nums.size() - 1;
                while (startIndex < endIndex) {
                    long long sum = (long long) num1 + (long long) num2 + (long long) nums[startIndex] +
                                    (long long) nums[endIndex];
                    if (sum == realTarget) {
                        ans.push_back({num1, num2, nums[startIndex], nums[endIndex]});
                    }
                    if (sum < realTarget) {
                        startIndex++;
                    } else {
                        endIndex--;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};