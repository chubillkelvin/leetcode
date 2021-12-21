#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getCounts(vector<int> nums, int target) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int count = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    int kthSmallestSubarraySum(vector<int> &nums, int k) {
        int lo = 0;
        int hi = 0;
        for (int num: nums) hi += num;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int counts = getCounts(nums, mid);
            if (counts >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};