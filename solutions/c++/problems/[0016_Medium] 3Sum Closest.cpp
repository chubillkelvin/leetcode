#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        if (nums.size() == 3) return closest;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int curr = nums[i];
            int startIndex = i + 1;
            int endIndex = nums.size() - 1;
            do {
                int sum = curr + nums[startIndex] + nums[endIndex];
                closest = abs(target - closest) < abs(target - sum) ? closest : sum;
                if (sum > target) {
                    endIndex--;
                } else {
                    startIndex++;
                }
            } while (startIndex < endIndex);
        }
        return closest;
    }
};