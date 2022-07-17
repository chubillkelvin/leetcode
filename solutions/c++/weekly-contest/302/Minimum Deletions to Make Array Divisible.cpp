#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
public:
    vector<int> getFactors(int n) {
        vector<int> f;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                f.push_back(i);
                if (n / i != i) f.push_back(n / i);
            }
        }
        return f;
    }

    int getGcd(int x, int y) {
        if (x == 0) return y;
        if (memo.count(x) > 0 && memo[x].count(y) > 0) return memo[x][y];
        memo[x][y] = getGcd(y % x, x);
        return memo[y][x] = memo[x][y];
    }

    int minOperations(vector<int> &nums, vector<int> &numsDivide) {
        int gcd = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++) {
            gcd = getGcd(gcd, numsDivide[i]);
        }
        std::sort(nums.begin(), nums.end());
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++) {
            if (pos.count(nums[i]) == 0) pos[nums[i]] = i;
        }
        auto factors = getFactors(gcd);
        std::sort(factors.begin(), factors.end());
        for (int f: factors) {
            if (pos.count(f) > 0) return pos[f];
        }
        return -1;
    }
};