#include <bits/stdc++.h>

using namespace std;

#define NEG_INF -999999

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<vector<vector<int>>> profit = {};

        // base cases
        profit.push_back({{NEG_INF, NEG_INF},
                          {NEG_INF, NEG_INF},
                          {NEG_INF, NEG_INF}});
        profit[0][0][0] = NEG_INF; // impossible case
        profit[0][0][1] = NEG_INF; // impossible case
        profit[0][1][0] = NEG_INF; // impossible case
        profit[0][1][1] = NEG_INF; // impossible case
        profit[0][2][0] = -prices[0]; // bought at i = 0
        profit[0][2][1] = 0; // do not buy and be available at i = 0

        for (int i = 1; i < prices.size(); i++) {
            // init value
            profit.push_back({{NEG_INF, NEG_INF},
                              {NEG_INF, NEG_INF},
                              {NEG_INF, NEG_INF}});
            for (int j = 2; j >= 0; j--) {
                if (j == 0) {
                    // impossible case - cannot do anymore transaction
                    profit[i][0][0] = numeric_limits<int>::lowest();
                    // either finished all transactions already, or finish the last transaction
                    profit[i][0][1] = max(profit[i - 1][0][1], profit[i - 1][1][0] + prices[i]);
                } else if (j == 2) {
                    // either continue holding first buy, or buy at i
                    profit[i][2][0] = max(profit[i - 1][2][0], profit[i - 1][2][1] - prices[i]);
                    // continue not buying at all
                    profit[i][2][1] = profit[i - 1][2][1];
                } else {
                    /**
                     * if already bought at i, two possible cases:
                     * [1] bought token already, continue holding
                     * [2] buy token at i
                     */
                    profit[i][j][0] = max(profit[i - 1][j][0], profit[i - 1][j][1] - prices[i]);

                    /**
                     * if not already bought at i, two possible cases:
                     * [1] continue not buying token
                     * [2] sell token at i
                     */
                    profit[i][j][1] = max(profit[i - 1][j][1], profit[i - 1][j + 1][0] + prices[i]);
                }
            }
        }


        int maxProfit = 0;
        for (int j = 0; j <= 2; j++) {
            maxProfit = max(maxProfit, profit[prices.size() - 1][j][1]);
        }

        return maxProfit;
    }
};
