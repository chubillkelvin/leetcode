#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        map<int, int> ans;
        ans[0] = 0;
        for (auto coin: coins) {
            ans[coin] = 1;
        }
        int maxCoins = amount / coins.back() + 1;
        for (int i = 0; i <= amount; i++) {
            if (ans.find(i) == ans.end()) continue;
            int currCount = ans[i];
            for (auto coin: coins) {
                long next = (long) coin + i;
                if (next <= amount) {
                    auto nextVal = ans.find(next);
                    if (nextVal == ans.end()) {
                        ans[next] = currCount + 1;
                    } else {
                        ans[next] = min(ans[next], currCount + 1);
                    }
                }
            }
        }
        return ans.find(amount) == ans.end() ? -1 : ans[amount];
    }
};