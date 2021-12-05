#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 1) return target == nums[0] ? 0 : -1;
        int low = 0;
        int hi = n - 1;
        while (low <= hi) {
            int mid = low + (hi - low) / 2;
            int m = nums[mid];
            if (target == m) return mid;
            if (m >= nums[low]) {
                // left hand side normal
                if (target >= nums[low] && target < m) {
                    hi = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // right hand side normal
                if (target <= nums[hi] && target > m) {
                    low = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};