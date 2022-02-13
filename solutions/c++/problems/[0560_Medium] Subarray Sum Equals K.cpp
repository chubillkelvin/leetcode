class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0]++;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            count += prefixSum[sum - k];
            prefixSum[sum]++;
        }
        return count;
    }
};