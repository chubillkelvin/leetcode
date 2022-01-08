class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> memo;
        memo[nums[n - 1] - nums[n - 2]]++;
        int count = 0;
        for (int b = n - 3; b >= 1; b--) {
            for (int a = 0; a < b; a++) {
                count += memo[nums[a] + nums[b]];
            }

            for (int d = n - 1; d >= b + 1; d--) {
                memo[nums[d] - nums[b]]++;
            }
        }
        return count;
    }
};