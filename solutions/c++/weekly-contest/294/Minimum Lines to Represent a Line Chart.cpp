#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLines(vector <vector<int>> &stockPrices) {
        int n = stockPrices.size();
        if (n <= 1) return 0;
        std::sort(stockPrices.begin(), stockPrices.end());
        int count = 1;
        for (int i = 2; i < n; i++) {
            auto curr = stockPrices[i];
            auto prev = stockPrices[i - 1];
            auto prevPrev = stockPrices[i - 2];
            if ((long long) (curr[1] - prev[1]) * (prev[0] - prevPrev[0]) !=
                (long long) (prev[1] - prevPrev[1]) * (curr[0] - prev[0]))
                count++;
        }
        return count;
    }
};