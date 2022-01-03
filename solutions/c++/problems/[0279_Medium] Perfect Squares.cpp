class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = (int) sqrt(n); i >= 1; i--) {
            nums.push_back(i * i);
        }
        vector<int> memo(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int num: nums) {
                if (i - num == 0) {
                    memo[i] = 1;
                } else if (i - num >= 0 && memo[i - num] != 0) {
                    if (memo[i] == 0) {
                        memo[i] = memo[i - num] + 1;
                    } else {
                        memo[i] = min(memo[i], memo[i - num] + 1);
                    }
                }
            }
        }
        return memo[n];
    }
};