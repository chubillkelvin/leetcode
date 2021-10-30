#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<vector<int>> profit = {};

        if (prices.size() < 2) return 0;

        // base cases
        profit.push_back({0, 0});
        profit[0][0] = -prices[0]; // buy on i = 0
        profit[0][1] = 0; // do not buy on i = 0
        profit.push_back({0, 0});
        profit[1][0] = max(profit[0][0], -prices[1]); // continue holding or buy on i = 1
        profit[1][1] = max(profit[0][1], profit[0][0] + prices[1]); // either continue not buying or sell on i = 1

        for (int i = 2; i < prices.size(); i++) {
            profit.push_back({0, 0});
            profit[i][0] = max(profit[i - 1][0], max(profit[i - 2][1], profit[i - 2][0] + prices[i - 2]) - prices[i]);
            profit[i][1] = max(profit[i - 1][1], profit[i - 1][0] + prices[i]);
        }

        return max(0, profit[prices.size() - 1][1]);
    }
};