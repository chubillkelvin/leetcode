#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int MOD = 1e9 + 7;
        int count = 1;
        unordered_map<int, long long> steps;
        steps[startPos] = 1;
        while (count < k) {
            unordered_map<int, long long> curr;
            for (auto p: steps) {
                curr[p.first - 1] += p.second;
                curr[p.first - 1] %= MOD;
                curr[p.first + 1] += p.second;
                curr[p.first + 1] %= MOD;
            }
            steps = curr;
            count++;
        }
        return (steps[endPos - 1] + steps[endPos + 1]) % MOD;
    }
};