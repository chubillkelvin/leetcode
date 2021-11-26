#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int midNum = nums[mid];
            if (midNum < target) {
                low = mid + 1;
            } else if (midNum > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return target <= nums[low] ? low : low + 1;
    }
};