class Solution {
    vector<int> nums;
    vector<vector<int>> memo;
public:
    int dp(int s, int e) {
        if(s > e) return 0;

        if(memo[s][e]) return memo[s][e];

        int maxSoFar = 0;
        for(int i = s; i <= e; i++) {
            int g = nums[s-1] * nums[i] * nums[e+1];
            int r = dp(s, i-1) + dp(i+1, e);
            maxSoFar = max(maxSoFar, g+r);
        }
        memo[s][e] = maxSoFar;
        return maxSoFar;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        this->nums = nums;
        memo = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
        return dp(1, nums.size()-2);
    }
};