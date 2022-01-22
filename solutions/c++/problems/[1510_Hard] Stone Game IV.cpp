class Solution {
public:
    bool winnerSquareGame(int n) {
        int maxLog = (int) sqrt(n);
        vector<bool> nums(n + 1, false);
        for (int i = 0; i <= n; i++) {
            if (nums[i] == false) {
                for (int j = 1; j <= maxLog; j++) {
                    int next = i + j * j;
                    if (next <= n) {
                        nums[next] = true;
                    }
                }
            }
        }
        return nums[n];
    }
};