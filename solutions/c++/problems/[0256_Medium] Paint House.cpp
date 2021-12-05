#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        vector<vector<int>> ans = vector<vector<int>>(n, {0, 0, 0});
        // base case
        ans[0] = costs[0];
        for (int i = 1; i < n; i++) {
            auto prev = ans[i - 1];
            auto curr = costs[i];
            ans[i] = {min(prev[1], prev[2]) + curr[0], min(prev[0], prev[2]) + curr[1],
                      min(prev[0], prev[1]) + curr[2]};
        }
        vector<int> last = ans.back();
        return *min_element(last.begin(), last.end());
    }
};