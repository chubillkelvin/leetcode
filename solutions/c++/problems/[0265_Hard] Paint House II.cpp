#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getCurrCost(vector<int> prev, vector<int> curr) {
        int n = prev.size();
        int min = 999;
        int min2 = 1000;
        for (int num: prev) {
            if (num < min) {
                min2 = min;
                min = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        vector<int> ans = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = prev[i] == min ? min2 + curr[i] : min + curr[i];
        }
        return ans;
    }

    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>{});
        // base case
        ans[0] = costs[0];
        for (int i = 1; i < n; i++) {
            auto prev = ans[i - 1];
            auto curr = costs[i];
            ans[i] = getCurrCost(prev, curr);
        }
        vector<int> last = ans.back();
        return *min_element(last.begin(), last.end());
    }
};