// TLE :(

#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, vector<int>> factors;
public:
    vector<int> getFactors(int n) {
        if (factors.count(n) > 0) return factors[n];
        vector<int> f;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                f.push_back(i);
                if (n / i != i) f.push_back(n / i);
            }
        }
        return factors[n] = f;
    }

    int idealArrays(int n, int maxValue) {
        int MOD = 1e9 + 7;
        vector<vector<long long>> memo(n, vector<long long>(maxValue + 1, 0));
        for (int i = 1; i <= maxValue; i++) memo[0][i] = 1;
        long long sum = 0;
        for (int i = 1; i < n; i++) {
            for (int num = 1; num <= maxValue; num++) {
                vector<int> factors = getFactors(num);
                for (int f: factors) {
                    memo[i][num] += memo[i - 1][f];
                    memo[i][num] %= MOD;
                }
                if (i == n - 1) {
                    sum += memo[i][num];
                    sum %= MOD;
                }
            }
        }
        return sum;
    }
};