class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> minimum(n, 0);
        vector<int> maximum(n, 0);
        int total = nums[0];
        int minSoFar = nums[0];
        int maxSoFar = nums[0];
        minimum[0] = nums[0];
        maximum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            total += curr;
            minimum[i] = min(curr, minimum[i - 1] + curr);
            maximum[i] = max(curr, maximum[i - 1] + curr);
            minSoFar = min(minSoFar, minimum[i]);
            maxSoFar = max(maxSoFar, maximum[i]);
        }
        if (total - minSoFar == 0) {
            return maxSoFar;
        } else {
            return max(maxSoFar, total - minSoFar);
        }
    }
};