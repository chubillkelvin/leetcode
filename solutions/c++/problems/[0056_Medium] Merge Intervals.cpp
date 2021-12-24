#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<bool> coverage = vector<bool>(20002, false);
        for (auto interval: intervals) {
            int start = interval[0] * 2;
            int end = interval[1] * 2;
            for (int i = start; i <= end; i++) {
                coverage[i] = true;
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i <= 20001; i++) {
            int curr = coverage[i];
            if (curr) {
                int start = i;
                int end = i;
                for (int j = i + 1; j <= 200001; j++) {
                    if (coverage[j]) {
                        end = j;
                    } else {
                        i = j;
                        break;
                    }
                }
                ans.push_back({start / 2, end / 2});
            }
        }
        return ans;
    }
};