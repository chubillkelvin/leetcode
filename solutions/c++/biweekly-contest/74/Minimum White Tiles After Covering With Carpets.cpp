#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<int> memo(n, 0);
        memo[0] = floor[0] == '1' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            char c = floor[i];
            memo[i] = memo[i - 1] + (c == '1' ? 1 : 0);
        }
        if (numCarpets == 0) return memo[n - 1];
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(numCarpets + 1, n));
        for (int i = 0; i < n; i++) ans[i][numCarpets] = memo[i];
        for (int i = 0; i < numCarpets; i++) ans[0][i] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < numCarpets; j++) {
                ans[i][j] = min(ans[i - 1][j] + (floor[i] == '1' ? 1 : 0),
                                (i - carpetLen >= 0) ? ans[i - carpetLen][j + 1] : 0);
            }
        }
        return ans[n - 1][0];
    }
};