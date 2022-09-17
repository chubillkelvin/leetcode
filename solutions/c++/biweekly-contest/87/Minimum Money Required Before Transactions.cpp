#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        long long cost = 0;
        int maxCost = INT_MIN;
        int maxCashback = INT_MIN;
        for (auto t: transactions) {
            if (t[1] >= t[0]) {
                maxCost = max(maxCost, t[0]);
                continue;
            }
            cost += t[0];
            cost -= t[1];
            maxCashback = max(maxCashback, t[1]);
        }
        if (maxCost > maxCashback) {
            cost += maxCost;
        } else {
            cost += maxCashback;
        }
        return cost;
    }
};