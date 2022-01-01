enum Transaction {
    buy,
    sell
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, -99999));
        int maxP = 0;
        // base cases
        dp[0][sell] = 0;
        dp[0][buy] = -prices[0];
        dp[1][sell] = max(0, dp[0][buy] + prices[1]);
        dp[1][buy] = max(dp[0][buy], -prices[1]);
        maxP = max(dp[1][buy], dp[1][sell]);
        for(int i = 2; i < n; i++) {
            dp[i][buy] = max(dp[i-1][buy], dp[i-2][sell] - prices[i]);
            dp[i][sell] = max(dp[i-1][sell], dp[i-1][buy] + prices[i]);
            maxP = max(maxP, max(dp[i][buy], dp[i][sell]));
        }
        return maxP;
    }
};