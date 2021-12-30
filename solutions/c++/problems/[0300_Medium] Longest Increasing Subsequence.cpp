class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        int maxSoFar = 1;
        vector<int> ans = vector<int>(n, 1);
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            for (int j = 0; j < i; j++) {
                if (curr > nums[j]) ans[i] = max(ans[i], ans[j] + 1);
            }
            maxSoFar = max(maxSoFar, ans[i]);
        }
        return maxSoFar;
    }
};