class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        int maxLen = 0;
        unordered_map<int, vector<int>> counts;
        counts[0].push_back(-1);
        for (int i = 0; i < n; i++) {
            count += nums[i] == 0 ? -1 : 1;
            counts[count].push_back(i);
            if (counts[count].size() > 1) maxLen = max(maxLen, i - counts[count][0]);
        }
        return maxLen;
    }
};