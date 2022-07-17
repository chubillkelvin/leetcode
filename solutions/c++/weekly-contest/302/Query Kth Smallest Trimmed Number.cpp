#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        unordered_map<int, vector<pair<string, int>>> trimmed;
        int n = queries.size();
        int wordSize = nums[0].size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            auto q = queries[i];
            int k = q[0];
            int trim = q[1];
            if (trimmed.count(trim) == 0) {
                for (int j = 0; j < nums.size(); j++) {
                    string sub = nums[j].substr(wordSize - trim, trim);
                    trimmed[trim].push_back({sub, j});
                }
                sort(trimmed[trim].begin(), trimmed[trim].end());
            }
            ans[i] = trimmed[trim][k - 1].second;
        }
        return ans;
    }
};