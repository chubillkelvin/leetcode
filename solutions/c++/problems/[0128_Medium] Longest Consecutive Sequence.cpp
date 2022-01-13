class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int longest = 0;
        int currSeq = 1;
        for (int i = 1; i < n; i++) {
            int prev = nums[i - 1];
            int curr = nums[i];
            if (curr == prev) continue;
            if (curr - 1 == prev) {
                currSeq++;
            } else {
                longest = max(longest, currSeq);
                currSeq = 1;
            }
        }
        return max(longest, currSeq);
    }
};