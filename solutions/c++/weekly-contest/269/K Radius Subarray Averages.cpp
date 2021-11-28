#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int> &nums, int k) {
        vector<int> ans = {};
        vector<long long> total = {};
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                ans.push_back(-1);
                total.push_back(-1);
                continue;
            }
            if (i >= nums.size() - k) {
                ans.push_back(-1);
                total.push_back(-1);
                continue;
            }
            long long prevTotal = -1;
            if (i - 1 > 0) prevTotal = total[i - 1];
            if (prevTotal == -1) {
                long long curr = 0;
                for (int j = i - k; j <= i + k; j++) {
                    curr += nums[j];
                }
                ans.push_back((int) (curr / (2 * k + 1)));
                total.push_back(curr);
            } else {
                int d = nums[i - k - 1];
                int a = nums[i + k];
                long long curr = prevTotal - d + a;
                ans.push_back((int) (curr / (2 * k + 1)));
                total.push_back(curr);
            }
        }
        return ans;
    }
};