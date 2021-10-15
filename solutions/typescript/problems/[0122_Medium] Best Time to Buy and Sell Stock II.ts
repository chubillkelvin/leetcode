function maxProfit(prices: number[]): number {
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
