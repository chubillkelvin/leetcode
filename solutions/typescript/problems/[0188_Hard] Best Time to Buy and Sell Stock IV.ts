function maxProfit(k: number, prices: number[]): number {
    const n = prices.length;

    // Special case 1: No trades are done
    if (n <= 1 || k <= 0) {
        return 0;
    }

    // Special case 2: More trades allowed than available days - solution for Problem 122
    if (n <= 2 * k) {
        let profit = 0;
        for (let i = 0; i < prices.length - 1; i++) {
            const buyPrice = prices[i];
            const sellPrice = prices[i + 1];

            if (sellPrice > buyPrice) {
                profit += sellPrice - buyPrice;
            }
        }
        return profit;
    }

    /**
     * DP
     * Note: dp[day number][transactions done][0 - not holding stock / 1 - holding stock]
     */
    const dp: number[][][] = [];
    for (let i = 0; i < n; i++) {
        dp[i] = [];
        for (let j = 0; j <= k; j++) {
            dp[i][j] = [];
            // value can be negative when stock is bought and money is spent - need to initialize with -Infinity
            dp[i][j][0] = -Infinity;
            dp[i][j][1] = -Infinity;
        }
    }

    dp[0][0][0] = 0;
    dp[0][1][1] = -prices[0];

    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= k; j++) {
            // Max of two cases: [1] continue not holding any stock; [2] sell stock and get the money
            if (i > 0) {
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

                // Max of two cases: [1] continue holding stock; [2] buy stock and spend the money
                if (j > 0) {
                    dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
    }

    let result = 0;
    for (let j = 0; j <= k; j++) {
        result = Math.max(result, dp[n - 1][j][0]);
    }

    return result;
}
