#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m, 0);
        std::sort(nums.begin(), nums.end());
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            auto lb = std::lower_bound(prefix.begin(), prefix.end(), q);
            if (lb != prefix.end()) {
                if (*lb == q) {
                    ans[i] = lb - prefix.begin() + 1;
                } else {
                    ans[i] = lb - prefix.begin();
                }
            } else {
                ans[i] = n;
            }
        }
        return ans;
    }
};
