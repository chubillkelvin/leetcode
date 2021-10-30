#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        vector<vector<int>> profit = {};

        // base cases
        profit.push_back({0, 0});
        profit[0][0] = -prices[0]; // buy on i = 0
        profit[0][1] = 0; // do not buy on i = 0

        for (int i = 1; i < prices.size(); i++) {
            profit.push_back({0, 0});
            profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] - prices[i]);
            profit[i][1] = max(profit[i - 1][1], profit[i - 1][0] + prices[i] - fee);
        }

        return max(0, profit[prices.size() - 1][1]);
    }
};