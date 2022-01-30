#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int> &nums) {
        int n = nums.size();
        vector<int> zeros(n, 0);
        vector<int> ones(n, 0);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int add = num == 0 ? 1 : 0;
            zeros[i] = i == 0 ? add : zeros[i - 1] + add;
        }
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            int add = num == 1 ? 1 : 0;
            ones[i] = i == n - 1 ? add : ones[i + 1] + add;
        }
        vector<vector<int>> scores(n + 1, vector<int>{});
        int maxScore = 0;
        for (int i = 0; i <= n; i++) {
            int leftScore = i > 0 ? zeros[i - 1] : 0;
            int rightScore = i < n ? ones[i] : 0;
            int total = leftScore + rightScore;
            scores[total].push_back(i);
            maxScore = max(maxScore, total);
        }
        return scores[maxScore];
    }
};