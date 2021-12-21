#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> nums, int target) {
        int n = nums.size();
        int count = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            while (nums[right] - nums[left] > target) left++;
            count += right - left;
        }
        return count;
    }

    int smallestDistancePair(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[n - 1] - nums[0];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int pairs = countPairs(nums, mid);
            if (pairs >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};