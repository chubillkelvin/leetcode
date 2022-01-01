class Solution {
    vector<int> nums;
public:
    int missing(int index, vector<int> nums) {
        return nums[index] - nums[0] - index;
    }

    int missingElement(vector<int> &nums, int k) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int count = missing(hi, nums);
        if (k > count) return nums[hi] + k - count;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = missing(mid, nums);
            if (count >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return nums[lo - 1] + k - missing(lo - 1, nums);
    }
};