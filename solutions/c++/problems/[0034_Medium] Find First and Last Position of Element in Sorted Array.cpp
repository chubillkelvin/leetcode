#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo < n && nums[lo] == target) {
            ans.push_back(lo);
        } else {
            ans.push_back(-1);
        }

        lo = 0;
        hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2 + 1;
            if (nums[mid] <= target) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (hi >= 0 && nums[hi] == target) {
            ans.push_back(hi);
        } else {
            ans.push_back(-1);
        }
        return ans;
    }
};