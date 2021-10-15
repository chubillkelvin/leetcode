function maxProfit(prices: number[]): number {
    let buyPrice = Infinity;
    let profit = 0;
    for (const price of prices) {
        if (price < buyPrice) {
            buyPrice = price;
        } else {
            const currProfit = price - buyPrice;
            if (currProfit > profit) {
                profit = currProfit;
            }
        }
    }

    return profit;
}
