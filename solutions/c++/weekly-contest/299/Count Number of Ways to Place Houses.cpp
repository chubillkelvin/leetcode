#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countHousePlacements(int n) {
        if (n == 1) return 4;
        if (n == 2) return 9;
        int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= MOD;
        }
        return (dp[n] * dp[n]) % MOD;
    }
};

