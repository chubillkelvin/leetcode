#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        long long MOD = 1000000007;
        vector<long long> full = vector<long long>(n + 1, 0);
        vector<long long> partial = vector<long long>(n + 1, 0);
        // base cases
        full[1] = 1;
        full[2] = 2;
        partial[2] = 1;
        for (int i = 3; i <= n; i++) {
            full[i] = (full[i - 1] + full[i - 2] + 2 * partial[i - 1]) % MOD;
            partial[i] = (partial[i - 1] + full[i - 2]) % MOD;
        }
        return full.back();
    }
};