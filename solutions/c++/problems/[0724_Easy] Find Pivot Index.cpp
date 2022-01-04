class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int n = nums.size();
        vector<int> leftSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            leftSum[i + 1] = nums[i] + leftSum[i];
        }
        for (int i = 0; i < n; i++) {
            if (leftSum[i] == leftSum[n] - leftSum[i] - nums[i]) return i;
        }
        return -1;
    }
};