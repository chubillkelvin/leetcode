class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        prefix[0] = 0;
        int maxCount = 0;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            sum += curr;
            count++;
            int diff = sum - k;
            if (curr == k) maxCount = max(maxCount, 1);
            if (diff == 0) maxCount = count;
            if (prefix[diff]) maxCount = max(maxCount, count - prefix[diff]);
            if (sum != 0 && prefix[sum] == 0) prefix[sum] = count;
        }
        return maxCount;
    }
};