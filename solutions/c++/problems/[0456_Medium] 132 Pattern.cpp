class Solution {

public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        vector<int> mins(n, nums[0]);
        int minSoFar = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            minSoFar = min(minSoFar, curr);
            mins[i] = minSoFar;
        }
        stack<int> check;
        for (int i = n - 1; i >= 0; i--) {
            int curr = nums[i];
            if (curr > mins[i]) {
                if (check.empty() || curr < check.top()) {
                    check.push(curr);
                } else {
                    while (!check.empty() && curr > check.top()) {
                        if (check.top() > mins[i]) return true;
                        check.pop();
                    }
                }
            }
        }
        return false;
    }
};