class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        vector<int> counts = vector<int>(amount + 1, 0);
        for (int coin: coins) {
            if (coin <= amount) counts[coin] = 1;
        }
        for (int i = 0; i <= amount - coins[0]; i++) {
            if (counts[i] == 0) continue;
            for (int coin: coins) {
                if ((long) i + coin <= amount) {
                    if (counts[i + coin] == 0) {
                        counts[i + coin] = counts[i] + 1;
                    } else {
                        counts[i + coin] = min(counts[i + coin], counts[i] + 1);
                    }
                }
            }
        }
        return counts[amount] == 0 ? -1 : counts[amount];
    }
};