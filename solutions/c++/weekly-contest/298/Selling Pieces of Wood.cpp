// TLE :(

#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> prices;
    unordered_map<int, unordered_map<int, long long>> memo;
public:
    long long dp(int m, int n) {
        if (memo.count(m) > 0 && memo[m].count(n) > 0) return memo[m][n];
        if (m <= 0 || n <= 0) return 0;
        if (m < prices[0][0]) return 0;
        long long maxPrice = 0;
        vector<int> maxUsed = {0, 0, -10000};
        for (auto price: prices) {
            if (price[0] > m) break;
            if (price[1] > n) continue;
            if (price[0] >= maxUsed[0] && price[1] >= maxUsed[1] && price[2] <= maxUsed[2]) continue;
            maxPrice = max(maxPrice, price[2] + max(dp(m, n - price[1]) + dp(m - price[0], price[1]),
                                                    dp(m - price[0], n) + dp(price[0], n - price[1])));
            if (price[2] > maxUsed[2]) maxUsed = price;
        }
        return memo[m][n] = maxPrice;
    }

    long long sellingWood(int m, int n, vector<vector<int>> &prices) {
        sort(prices.begin(), prices.end());
        this->prices = prices;
        return dp(m, n);
    }
};