#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> pos;
public:
    bool allCovered(vector<int> &rolls, int k, int curr) {
        int lastIndex = -1;
        for (int i = 0; i < curr; i++) {
            int temp = lastIndex;
            for (int j = 1; j <= k; j++) {
                auto ub = upper_bound(pos[j].begin(), pos[j].end(), lastIndex);
                if (ub == pos[j].end()) return false;
                temp = max(temp, *ub);
            }
            lastIndex = temp;
        }
        return true;
    }

    int shortestSequence(vector<int> &rolls, int k) {
        int n = rolls.size();
        pos = vector<vector<int>>(k + 1);
        for (int i = 0; i < n; i++) pos[rolls[i]].push_back(i);
        int lo = 1;
        int hi = n + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (!allCovered(rolls, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};