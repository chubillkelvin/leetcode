#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int> &prices) {
        int n = prices.size();
        vector<long long> count = vector<long long>(n, 1);
        for (int i = 1; i < n; i++) {
            int prev = prices[i - 1];
            int curr = prices[i];
            if (prev - curr == 1) {
                count[i] = count[i - 1] + 1;
            }
        }
        long long ans = 0;
        for (auto num: count) ans += num;
        return ans;
    }
};