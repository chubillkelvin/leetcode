class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;
        if (prices.empty()) return 0;
        int n = prices.size();
        k *= 2;
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(k+1, 0));
        int maxP = 0;
        // base cases
        dp[0][k] = 0;
        dp[0][k-1] = -prices[0];
        for (int i = 1; i < n; i++) {
            for (int j = k; j >= k - 1 - i && j >= 0; j--) {
                if (j % 2 == 0) {
                    // not holding stock
                    if (j == k) {
                        dp[i][j] = dp[i-1][j];
                    } else if (j == k - 1 - i) {
                        dp[i][j] = dp[i-1][j+1] + prices[i];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j+1] + prices[i]);
                    }
                } else {
                    // holding stock
                    if (j == k - 1 - i) {
                        dp[i][j] = dp[i-1][j+1] - prices[i];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j+1] - prices[i]);
                    }
                }
                maxP = max(maxP, dp[i][j]);
            }
        }
        return maxP;
    }
};