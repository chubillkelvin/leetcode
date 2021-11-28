#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
public:
    vector<int> prices = {};
    stack<int> index = {};

    StockSpanner() {

    }

    int next(int price) {
        prices.push_back(price);
        while (!index.empty() && prices[index.top()] <= price) index.pop();
        int currIndex = prices.size() - 1;
        int ans = index.empty() ? currIndex + 1 : currIndex - index.top();
        index.push(currIndex);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */