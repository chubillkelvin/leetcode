#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = security.size();
        vector<int> decreasing = vector<int>(n, 1);
        vector<int> increasing = vector<int>(n, 1);
        for (int i = 1; i < n; i++) {
            int prev = security[i - 1];
            int curr = security[i];
            if (curr <= prev) {
                decreasing[i] = decreasing[i - 1] + 1;
            } else {
                decreasing[i] = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            int curr = security[i];
            int next = security[i + 1];
            if (curr <= next) {
                increasing[i] = increasing[i + 1] + 1;
            } else {
                increasing[i] = 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (time == 0) {
                ans.push_back(i);
            } else if (i >= time && i < n - time) {
                int prev = security[i - 1];
                int curr = security[i];
                int next = security[i + 1];
                if (curr <= prev && decreasing[i - 1] >= time)
                    if (curr <= next && increasing[i + 1] >= time) {
                        ans.push_back(i);
                    }
            }
        }
        return ans;
    }
};
